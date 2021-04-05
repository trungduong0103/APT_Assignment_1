#ifndef APT_ASSIGNMENT_1_TEST_FUNCTIONS_H
#define APT_ASSIGNMENT_1_TEST_FUNCTIONS_H

void display_statistics_calculation_time(const char *FILE_PATH, int (*function)(const char *));

double generate_random_double(double min, double max);

bool generate_sample_data(const std::string &FILE_PATH, unsigned long int num_of_columns, double lower_bound,
                          double upper_bound);

#endif //APT_ASSIGNMENT_1_TEST_FUNCTIONS_H
