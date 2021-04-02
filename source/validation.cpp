#include <iostream>
#include <fstream>
#include <string>
#include "../headers/validation.h"

// remove whitespace if there is any
// accepts whitespace, e.g: -#32, -#..32, #-#32, #..-#..32, -32#, -32#..
// where # represents a space and .. means more than 1
void remove_whitespace(std::string &string) {
    for (int i = string.find(' '); i < string.length(); i = string.find(' ', i)) {
        string.erase(i, 1);
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

bool valid_number_format(const std::string &string) {
    unsigned short int decimal_point_count = 0;
    for (char c: string) {
        if (c == '.') {
            decimal_point_count++;
        }
    }
    if (decimal_point_count > 1) {
        return false;
    }

    if (string[0] == '-') {
        return string.substr(1, string.length()).find_first_not_of("0123456789.,") == std::string::npos;
    }
    return string.find_first_not_of("0123456789.,") == std::string::npos;
}

// check if string has any characters
bool has_characters(const std::string &string) {
    return string.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
}

bool cli_input_is_correct(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Must enter 1 argument!" << std::endl;
        return false;
    }

    const std::string input_to_string = argv[1];
    if (input_to_string.substr(input_to_string.length() - 3, input_to_string.length()) != "csv") {
        std::cerr << "Must enter a csv file!" << std::endl;
        return false;
    }

    return true;
}

