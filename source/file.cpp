#include <iostream>
#include <fstream>
#include <string>
#include "../headers/file.h"
#include "../headers/validation.h"

bool can_open_file(const char *file_name) {
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << "!\n";
        return false;
    }
    return true;
}

unsigned int calculate_array_size(const std::string &file_name) {
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << " !\n";
        return 1;
    }
    unsigned int count = 0;
    std::string line;
    // ignore the first column (x,y)
    getline(infile, line);
    while (getline(infile, line)) {
        if (!has_characters(line) && !line.empty() && !has_more_than_two_columns(line)) {
            count++;
        }
    }

    infile.close();
    return count;
}

bool
validate_and_extract_data_from_column(const std::string &file_name,
                                      double x_column_array[],
                                      double y_column_array[]) {
    int index = 0;
    int incorrectIndex = 0;
    std::ifstream infile(file_name);
    std::string line;
    // skip first line (x,y)
    getline(infile, line);
    while (getline(infile, line)) {
        remove_whitespace(line);

        if (has_characters(line) || line.empty() || has_more_than_two_columns(line)) {
            std::cerr << "Skipping row " << incorrectIndex + 2 << " in file " << file_name
                      << ". Incorrect/empty row data: " << line << std::endl;
            incorrectIndex++;
            continue;
        } else {
            // find the first occurrence of ',' to extract column numbers
            int index_to_comma = line.find(',');
            // x_value comes from beginning of array to index of ','
            std::string x_value = line.substr(0, index_to_comma);
            // y_value comes from beginning of ',' to end of line
            std::string y_value = line.substr(index_to_comma + 1, line.length());
            x_column_array[index] = std::stod(x_value);
            y_column_array[index] = std::stod(y_value);
            incorrectIndex++;
            index++;
        }
    }
    infile.close();
    return true;
}