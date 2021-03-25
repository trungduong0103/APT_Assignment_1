#ifndef APT_ASSIGNMENT_1_FILE_H
#define APT_ASSIGNMENT_1_FILE_H

#include <string>

bool can_open_file(const std::string &file_name);

bool validate_and_extract_data_from_column(const std::string &file_name, double array[], char column);

#endif //APT_ASSIGNMENT_1_FILE_H
