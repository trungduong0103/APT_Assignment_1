#include <fstream>

// enums
enum Column {
    x,
    y
};

bool string_is_digits(const std::string &digits) {
    if (digits[0] == '-') {
        return digits.substr(1, digits.length()).find_first_not_of("0123456789");
    }
    return digits.find_first_not_of("0123456789");
}

void extract_data_from_column(const std::string &file_name, double array[], Column column) {
    int index = 0;
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << " !\n";
        return;
    }
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
            case x:
                if (!string_is_digits(x_value)) {
                    std::cerr << "Data is in incorrect format, data: " << x_value << std::endl;
                    return;
                }
                array[index] = std::stod(x_value);
                break;
            case y:
                if (!string_is_digits(y_value)) {
                    std::cerr << "Data is in incorrect format, data: " << x_value << std::endl;
                    return;
                }
                array[index] = std::stod(y_value);
                break;
            default:
                std::cerr << "column must be of Column enum!" << std::endl;
                break;
        }
        index++;
    }
    infile.close();
}