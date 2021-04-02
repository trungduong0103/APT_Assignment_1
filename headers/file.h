#ifndef APT_ASSIGNMENT_1_FILE_H
#define APT_ASSIGNMENT_1_FILE_H

#include <string>

unsigned int calculate_array_size(const std::string &file_name);

bool can_open_file(const char *file_name);

unsigned int calculate_array_size(const std::string &file_name);

bool validate_and_extract_data_from_column(const std::string &file_name,double x_column_array[],double y_column_array[]);

#endif //APT_ASSIGNMENT_1_FILE_H
