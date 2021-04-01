#ifndef APT_ASSIGNMENT_1_HELPERS_H
#define APT_ASSIGNMENT_1_HELPERS_H

#include <fstream>
#include <iostream>

void print_array(int array[], unsigned int array_size);

double sum_of_array_elements(const double array[], unsigned int array_size);

//void display_statistics_calculation_time(int function());
//
//bool generate_sample_data(const std::string &FILE_PATH, unsigned long int num_of_columns, double lower_bound,
//                          double upper_bound);

bool input_is_correct(int argc, char *argv[]);

int main_driver_function(const char *FILE_PATH);

#endif //APT_ASSIGNMENT_1_HELPERS_H
