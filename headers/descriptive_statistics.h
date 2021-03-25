#ifndef APT_ASSIGNMENT_1_DESCRIPTIVE_STATISTICS_H
#define APT_ASSIGNMENT_1_DESCRIPTIVE_STATISTICS_H

#include <fstream>
#include <iostream>

// B.1
double calculate_median(const double sorted_array[], unsigned int array_size);

void calculate_medians_driver_function(const double x_column[], const double y_column[], unsigned int array_size);

// B.2
std::string calculate_modes(const double array[], unsigned int array_size);

void calculate_modes_driver_function(const double x_column[], const double y_column[], unsigned int array_size);

// B.3
double calculate_mean(const double array[], unsigned int array_size);

double calculate_variance(const double array[], unsigned int array_size);

double calculate_standard_deviation(double variance);

void
calculate_variance_standard_variance_driver_function(const double x_column[], const double y_column[],
                                                     unsigned int array_size);

// B.4
double calculate_mad(const double array[], unsigned int array_size);

void calculate_mad_driver_function(const double x_column[], const double y_column[], unsigned int array_size);

// B.5
double calculate_first_quantile(const double array[], unsigned int array_size);

void calculate_first_quantiles_driver_function(double x_column[], double y_column[], unsigned int array_size);

// B.6
double calculate_skewness(double array[], unsigned int array_size);

void calculate_skewness_driver_function(double x_column[], double y_column[], unsigned int array_size);

// B.7
double calculate_kurtosis(double array[], unsigned int array_size);

void calculate_kurtosis_driver_function(double x_column[], double y_column[], unsigned int array_size);

#endif //APT_ASSIGNMENT_1_DESCRIPTIVE_STATISTICS_H
