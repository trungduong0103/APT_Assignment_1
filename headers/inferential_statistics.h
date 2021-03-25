#ifndef APT_ASSIGNMENT_1_INFERENTIAL_STATISTICS_H
#define APT_ASSIGNMENT_1_INFERENTIAL_STATISTICS_H

//Sample covariance and its driver function
double calculate_sample_covariance(const double x[], const double y[], unsigned int size);

void calculate_sample_covariance_driver_function(const double cov_x_y);

//Pearson correlation of coefficient and its driver function
double calculate_correlation_coefficient(const double x[], const double y[], unsigned int size);

void calculate_correlation_coefficient_driver_function(const double r_x_y);

//Displaying linear regression formula
void display_linear_regression_formula(double mean_x, double mean_y, double stdev_x, double stdev_y, double r);

#endif //APT_ASSIGNMENT_1_INFERENTIAL_STATISTICS_H
