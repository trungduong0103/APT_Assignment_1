#ifndef APT_ASSIGNMENT_1_DESCRIPTIVE_STATISTICS_H
#define APT_ASSIGNMENT_1_DESCRIPTIVE_STATISTICS_H

#include <string>

// B.1
double calculate_median(const double sorted_array[], unsigned int array_size);

// B.2
std::string calculate_modes(const double sorted_array[], unsigned int array_size);

// B.3
double calculate_mean(const double sorted_array[], unsigned int array_size);

double calculate_variance(const double sorted_array[], unsigned int array_size);

double calculate_standard_deviation(double variance);

// B.4
double calculate_mad(const double sorted_array[], unsigned int array_size);

// B.5
double calculate_first_quantile(const double sorted_array[], unsigned int array_size);

// B.6
double calculate_skewness(double sorted_array[], unsigned int array_size);

// B.7
double calculate_kurtosis(double sorted_array[], unsigned int array_size);

#endif //APT_ASSIGNMENT_1_DESCRIPTIVE_STATISTICS_H
