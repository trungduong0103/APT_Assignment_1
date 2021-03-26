#ifndef APT_ASSIGNMENT_1_HELPERS_H
#define APT_ASSIGNMENT_1_HELPERS_H

#include <fstream>
#include <iostream>

void print_array(int array[], unsigned int array_size);

double sum_of_array_elements(const double array[], unsigned int array_size);

unsigned int calculate_array_size(const std::string &file_name);

void display_statistics_calculation_time(int function());

bool generate_sample_data(const std::string &FILE_PATH, unsigned long int num_of_columns, double lower_bound,
                          double upper_bound);

#endif //APT_ASSIGNMENT_1_HELPERS_H
