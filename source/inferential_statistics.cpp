#include "../headers/inferential_statistics.h"
#include "../headers/descriptive_statistics.h"
#include <cmath>

//Sample covariance of X and Y
double calculate_sample_covariance(const double x[], const double y[], unsigned int size) {
    double sum_of_product = 0;
    double mean_x = calculate_mean(x, size);
    double mean_y = calculate_mean(y, size);

    for (int i = 0; i != size; ++i) {
        sum_of_product += (x[i] - mean_x) * (y[i] - mean_y);
    }

    return sum_of_product / (size - 1);
}

void calculate_sample_covariance_driver_function(const double cov_x_y) {

    std::cout << "cov(x_y)=" << cov_x_y << std::endl;
}

//Pearson coefficient of corellation of X and Y
double sum_of_product(const double x[], const double y[], unsigned int size) {
    double product_sum = 0;

    for (int i = 0; i != size; ++i) {
        product_sum += x[i] * y[i];
    }

    return product_sum;
}

double sum_of_square(const double numbers[], unsigned int size) {
    double square_sum = 0;

    for (int i = 0; i != size; ++i) {
        square_sum += numbers[i] * numbers[i];
    }

    return square_sum;
}

double sum_of_elements(const double numbers[], unsigned int size) {
    double element_sum = 0;

    for (int i = 0; i != size; ++i) {
        element_sum += numbers[i];
    }

    return element_sum;
}

double calculate_correlation_coefficient(const double x[], const double y[], unsigned int size) {
    double sum_of_xy = sum_of_product(x, y, size);

    double sum_of_x = sum_of_elements(x, size);
    double sum_of_x_squared = sum_of_square(x, size);

    double sum_of_y = sum_of_elements(y, size);
    double sum_of_y_squared = sum_of_square(y, size);

    double numerator = (size * sum_of_xy) - sum_of_x * sum_of_y;
    double denominator = sqrt((size * sum_of_x_squared - pow(sum_of_x, 2)) * (size * sum_of_y_squared - pow(sum_of_y, 2)));

    return numerator / denominator;
}

void calculate_correlation_coefficient_driver_function(const double r_x_y) {


    std::cout << "r(x_y)=" << r_x_y << std::endl;
}

//Calculate and display linear regression line of X and Y
void display_linear_regression_formula(double mean_x, double mean_y, double stdev_x, double stdev_y, double r) {
    double slope = (r * stdev_y) / stdev_x;
    double intercept = mean_y - slope * mean_x;

    std::cout << "y = " << slope << "*x +" << intercept << std::endl;
}
