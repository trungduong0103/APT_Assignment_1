#include "../headers/descriptive_statistics.h"
#include <cmath>

double calculate_median(const double sorted_array[], unsigned int array_size) {
    unsigned int middle_index = array_size / 2;
    if (array_size % 2 == 0) {
        return (sorted_array[middle_index - 1] + sorted_array[middle_index]) / 2;
    } else {
        return sorted_array[middle_index];
    }
}

void calculate_medians_driver_function(const double x_column[], const double y_column[], unsigned int array_size) {
    std::cout << "median_x=" << calculate_median(x_column, array_size) << " - ";
    std::cout << "median_y=" << calculate_median(y_column, array_size) << std::endl;
}

// B.2
std::string calculate_modes(const double array[], unsigned int array_size) {
    unsigned int occurrence = 0;
    unsigned int max_occurrence = 1;
    double tempValue = array[0];
    std::string modes;
    for (const double *p = array; p < array + array_size; p++) {
        double currentValue = *p;
        if (tempValue == currentValue) {
            occurrence++;
        } else {
            if (occurrence == max_occurrence) {
                modes.append(std::to_string(tempValue) + ", ");
            } else if (occurrence > max_occurrence) {
                modes.clear();
                modes.append(std::to_string(tempValue) + ", ");
                max_occurrence = occurrence;
            }
            occurrence = 1;
            tempValue = currentValue;
        }
    }

    if (occurrence == max_occurrence) {
        modes.append(std::to_string(tempValue) + ", ");
    } else if (occurrence > max_occurrence) {
        modes.clear();
        modes.append(std::to_string(tempValue) + ", ");
    }

    return modes.substr(0, modes.length() - 2);
}

void calculate_modes_driver_function(const double x_column[], const double y_column[], unsigned int array_size) {
    std::cout << "mode_x={" << calculate_modes(x_column, array_size) << "} - ";
    std::cout << "mode_y={" << calculate_modes(y_column, array_size) << "}" << std::endl;
}

// B.3
double calculate_mean(const double array[], unsigned int array_size) {
    double sum = 0;
    int index = 0;
    for (const double *p = array; p < array + array_size; p++) {
        sum += *p;
        index++;
    }

    return sum / (double) array_size;
}

double calculate_variance(const double array[], unsigned int array_size) {
    double mean = calculate_mean(array, array_size);
    double diff = 0;
    for (const double *ptr = array; ptr < array + array_size; ptr++) {
        diff += pow(*ptr - mean, 2);
    }
    return diff / (double) (array_size - 1);
}

double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

void
calculate_variance_standard_variance_driver_function(const double x_column[], const double y_column[],
                                                     unsigned int array_size) {
    double x_variance = calculate_variance(x_column, array_size);
    double y_variance = calculate_variance(y_column, array_size);
    std::cout << "var_x=" << x_variance << " - " << "var_y=" << y_variance << std::endl;
    std::cout << "stdev_x=" << calculate_standard_deviation(x_variance) << " - stdev_y="
              << calculate_standard_deviation(y_variance) << std::endl;
}

// B.4
double calculate_mad(const double array[], unsigned int array_size) {
    double mean = calculate_mean(array, array_size);
    double diff = 0;
    for (const double *ptr = array; ptr < array + array_size; ptr++) {
        diff += abs(*ptr - mean);
    }
    return diff / array_size;
}

//mad_d=__ - mad_y=__
void calculate_mad_driver_function(const double x_column[], const double y_column[], unsigned int array_size) {
    std::cout << "mad_x=" << calculate_mad(x_column, array_size) << " - mad_y=" << calculate_mad(y_column, array_size)
              << std::endl;
}

// B.5
double calculate_first_quantile(const double array[], unsigned int array_size) {
    unsigned int first_quantile_index = (array_size - 1) / 4;
    double fraction = (double) array_size / 4 - (double) first_quantile_index;
    double i = array[first_quantile_index];
    double j = array[first_quantile_index + 1];
    return i + (j - i) * fraction;
}

void calculate_first_quantiles_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    std::cout << "q1_x=" << calculate_first_quantile(x_column, array_size) << " - ";
    std::cout << "q1_y=" << calculate_first_quantile(y_column, array_size) << std::endl;
}

// B.6
double calculate_skewness(double array[], unsigned int array_size) {
    double mean = calculate_mean(array, array_size);
    double s = sqrt(calculate_variance(array, array_size));
//   double deviation[array_size];
    double sum = 0;
    for (double *p = array; p < array + array_size; p++) {
        double deviation = *p - mean;
        double fraction = deviation / s;
        sum += pow(fraction, 3.0);
    }
    return sum / array_size;
}

void calculate_skewness_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    std::cout << "skew_x=" << calculate_skewness(x_column, array_size) << " - ";
    std::cout << "skew_y=" << calculate_skewness(y_column, array_size) << std::endl;
}

// B.7
double calculate_kurtosis(double array[], unsigned int array_size) {
    double mean = calculate_mean(array, array_size);
    double s = sqrt(calculate_variance(array, array_size));
    double sum = 0;
    for (double *p = array; p < array + array_size; p++) {
        double deviation = *p - mean;
        double fraction = deviation / s;
        sum += pow(fraction, 4.0);
    }
    //  return sum / (array_size-1) - 3; pandas xài (n-1)
    return sum / array_size - 3;
}

void calculate_kurtosis_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    std::cout << "kurt_x=" << calculate_kurtosis(x_column, array_size) << " - ";
    std::cout << "kurt_y=" << calculate_kurtosis(y_column, array_size) << std::endl;
}
