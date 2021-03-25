#include <iostream>
#include <fstream>
#include <string>
#include "../headers/file.h"

bool can_open_file(const std::string &file_name) {
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << "!\n";
        return false;
    }
    return true;
}

bool string_is_digits(const std::string &string) {
    std::cout<<string<<std::endl;
    if (string[0] == '-') {
        return string.substr(1, string.length()).find_first_not_of("0123456789.");
    }
    return string.find_first_not_of("0123456789.");
}

void remove_whitespace(std::string &string) {
    for (int i = string.find(' '); i < string.length(); i = string.find(' ', i)) {
        string.erase(i, 1);
        std::cout << string << std::endl;
    }
}

bool has_more_than_two_columns(const std::string &string) {
    unsigned short num_of_columns = 1;
    int pos = string.find(',');
    while (pos != std::string::npos) {
        num_of_columns++;
        pos++;
        pos = string.find(',', pos);
    }

    if (num_of_columns > 2) {
        return true;
    }
    return false;
}

bool has_characters(const std::string &string) {

}

bool validate_and_extract_data_from_column(const std::string &file_name, double array[], char column) {
    int index = 0;
    std::ifstream infile(file_name);
    std::string line;
    getline(infile, line);
    while (getline(infile, line)) {
        // check if csv has more than 2 columns
        if (has_more_than_two_columns(line)) {
            std::cerr << "Parsing failed, data has more than 2 columns at row "
                      << index + 2
                      << " in file " << file_name << std::endl;
            return false;
        }
        // remove whitespace if there is any
        // accepts whitespace, e.g: -#32, -#..32, #-#32, #..-#..32, -32#, -32#..
        // where # represents a space and .. means more than 1
        remove_whitespace(line);

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
                    std::cerr << "Parsing failed, data is in incorrect format at row "
                              << index + 2
                              << " in file " << file_name << std::endl;
                    break;
                }
                array[index] = std::stod(x_value);
                break;
            case 'y':
                if (!string_is_digits(y_value)) {
                    std::cerr << "Parsing failed, data is in incorrect format at row "
                              << index + 2
                              << " in file " << file_name << std::endl;
                    break;
                }
                array[index] = std::stod(y_value);
                break;
            default:
                std::cerr << "Parsing failed, column must be either x or y!" << std::endl;
                break;
        }
        index++;
    }
    infile.close();
    return true;
}