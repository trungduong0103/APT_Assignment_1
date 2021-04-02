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

// check if a row of data has more than 2 columns, by checking comma count
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

// check if string has any characters
bool has_characters(const std::string &string) {
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (string[0] == '-') {
        return string.substr(1, string.length()).find_first_of(alphabet) != std::string::npos;
    }
    return string.find_first_of(alphabet) != std::string::npos;
}

// check if string has any special characters
bool has_special_characters(const std::string &string) {
    for (char c : string) {
        // negative sign encountered, move on
        if (c == '-') {
            continue;
        }
        // if a character is a special character return true
        // however, decimal point '.' and newline '\n' is allowed
        // because we allow decimal numbers, positive and negative,
        // and each csv row ends with '\n'
        if ((c <= 47 || c >= 58) && c != 46) {
            if (c == 13) {
                return false;
            }
            return true;
        }
    }
    return false;
}

// check if string has more than 2 decimal points
bool has_more_than_one_decimal_points(const std::string &string) {
    unsigned int count = 0;
    for (char c : string) {
        if (c == '.') {
            count++;
        }
    }

    return count > 1;
}

// check if string has more than 2 minus signs
bool has_more_than_one_minus_sign(const std::string &string) {
    unsigned int count = 0;
    for (char c : string) {
        if (c == '-') {
            count++;
        }
    }
    return count > 1;
}

// column data is correct if:
// it does not have more than one decimal points or minus signs
// it does not have any characters or special characters
bool column_data_is_correct(const std::string &string) {
    return !has_more_than_one_decimal_points(string) && !has_more_than_one_minus_sign(string) &&
           !has_characters(string) && !has_special_characters(string);
}

// cli input is correct if it has 1 argument and must contains .csv at the end
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
