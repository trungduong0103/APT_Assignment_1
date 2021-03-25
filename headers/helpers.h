#ifndef APT_ASSIGNMENT_1_HELPERS_H
#define APT_ASSIGNMENT_1_HELPERS_H

#include <fstream>
#include <iostream>

void print_array(int array[], unsigned int array_size);

double sum_of_array_elements(const double array[], unsigned int array_size);

unsigned int calculate_array_size(const std::string &file_name);

void display_execution_time(int function());

#endif //APT_ASSIGNMENT_1_HELPERS_H
