#include "../headers/file.h"

bool can_open_file(const std::string &file_name) {
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << "!\n";
        return false;
    }
    return true;
}

bool string_is_digits(const std::string &digits) {
    if (digits[0] == '-') {
        return digits.substr(1, digits.length()).find_first_not_of("0123456789");
    }
    return digits.find_first_not_of("0123456789");
}

bool validate_and_extract_data_from_column(const std::string &file_name, double array[], char column) {
    int index = 0;
    std::ifstream infile(file_name);
    std::string line;
    getline(infile, line);
    while (getline(infile, line)) {
        // find the first occurrence of ',' to extract column numbers
        int index_to_comma = line.find(',');
        // x_value comes from beginning of array to index of ','
        std::string x_value = line.substr(0, index_to_comma);
        // y_value comes from beginning of ',' to end of line
        std::string y_value = line.substr(index_to_comma + 1, line.length());
        // 2 cases: x column and y column
        switch (column) {
            case 'x':
                if (!string_is_digits(x_value)) {
                    std::cerr << "Parsing failed, data is in incorrect format, data: " << x_value << " at row "
                              << index + 2
                              << " in file " << file_name << std::endl;
                    return false;
                }
                array[index] = std::stod(x_value);
                break;
            case 'y':
                if (!string_is_digits(y_value)) {
                    std::cerr << "Parsing failed, data is in incorrect format, data: " << x_value << " at row "
                              << index + 2
                              << " in file " << file_name << std::endl;
                    return false;
                }
                array[index] = std::stod(y_value);
                break;
            default:
                std::cerr << "Parsing failed, column must be either x or y!" << std::endl;
                return false;
        }
        index++;
    }
    infile.close();
    return true;
}