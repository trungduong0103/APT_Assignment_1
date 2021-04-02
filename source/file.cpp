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
    unsigned int index_to_comma;
    std::string x_value, y_value;

    // ignore the first column (x,y)
    getline(infile, line);
    while (getline(infile, line)) {
        index_to_comma = line.find(',');
        x_value = line.substr(0, index_to_comma);
        y_value = line.substr(index_to_comma + 1, line.length());
        if (!line.empty() && !has_more_than_two_columns(line) &&
            (column_data_is_correct(x_value) && (column_data_is_correct(y_value))))
            count++;
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
    unsigned int index_to_comma;
    std::string x_value, y_value;
    // skip first line (x,y)
    getline(infile, line);
    while (getline(infile, line)) {
        remove_whitespace(line);
        if (line.empty() || has_more_than_two_columns(line)) {
            std::cerr << "Skipping row " << incorrectIndex + 2 << " in file " << file_name
                      << ". Row is empty or has more than 2 columns: " << line << std::endl;
            incorrectIndex++;
        } else {
            // find the first occurrence of ',' to extract column numbers
            index_to_comma = line.find(',');
            // x_value comes from beginning of array to index of ','
            x_value = line.substr(0, index_to_comma);
            // y_value comes from beginning of ',' to end of line
            y_value = line.substr(index_to_comma + 1, line.length());
            if (!column_data_is_correct(x_value) || !column_data_is_correct(y_value)) {
                std::cerr << "Skipping row " << incorrectIndex + 2 << " in file " << file_name
                          << ". Invalid row data: " << line << std::endl;
                incorrectIndex++;
            } else {
                x_column_array[index] = std::stod(x_value);
                y_column_array[index] = std::stod(y_value);
                incorrectIndex++;
                index++;
            }
        }
    }
    infile.close();
    return true;
}