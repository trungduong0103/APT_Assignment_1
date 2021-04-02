//#include <iostream>
#include <string>
#include <cmath>
#include "../headers/descriptive_statistics.h"

double calculate_median(const double sorted_array[], unsigned int array_size) {
    unsigned int middle_index = array_size / 2;
    if (array_size % 2 == 0) {
        return (sorted_array[middle_index - 1] + sorted_array[middle_index]) / 2;
    } else {
        return sorted_array[middle_index];
    }
}

// B.2
std::string calculate_modes(const double sorted_array[], unsigned int array_size) {
    unsigned int occurrence = 0;
    unsigned int max_occurrence = 1;
    double tempValue = sorted_array[0];
    std::string modes;
    for (const double *p = sorted_array; p < sorted_array + array_size; p++) {
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

// B.3
double calculate_mean(const double sorted_array[], unsigned int array_size) {
    double sum = 0;
    int index = 0;
    for (const double *p = sorted_array; p < sorted_array + array_size; p++) {
        sum += *p;
        index++;
    }

    return sum / (double) array_size;
}

double calculate_variance(const double sorted_array[], unsigned int array_size) {
    double mean = calculate_mean(sorted_array, array_size);
    double diff = 0;
    for (const double *ptr = sorted_array; ptr < sorted_array + array_size; ptr++) {
        diff += pow(*ptr - mean, 2);
    }
    return diff / (double) (array_size - 1);
}

double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

// B.4
double calculate_mad(const double sorted_array[], unsigned int array_size) {
    double mean = calculate_mean(sorted_array, array_size);
    double diff = 0;
    for (const double *ptr = sorted_array; ptr < sorted_array + array_size; ptr++) {
        diff += abs(*ptr - mean);
    }
    return diff / array_size;
}

// B.5
double calculate_first_quantile(const double sorted_array[], unsigned int array_size) {
    unsigned int first_quantile_index = (array_size - 1) / 4;
    double fraction = (double) array_size / 4 - (double) first_quantile_index;
    double i = sorted_array[first_quantile_index];
    double j = sorted_array[first_quantile_index + 1];
    return i + (j - i) * fraction;
}

// B.6
double calculate_skewness(double sorted_array[], unsigned int array_size) {
    double mean = calculate_mean(sorted_array, array_size);
    double s = sqrt(calculate_variance(sorted_array, array_size));
    double sum = 0;
    for (double *p = sorted_array; p < sorted_array + array_size; p++) {
        double deviation = *p - mean;
        double fraction = deviation / s;
        sum += pow(fraction, 3.0);
    }
    return sum / array_size;
}

// B.7
double calculate_kurtosis(double sorted_array[], unsigned int array_size) {
    double mean = calculate_mean(sorted_array, array_size);
    double s = sqrt(calculate_variance(sorted_array, array_size));
    double sum = 0;
    for (double *p = sorted_array; p < sorted_array + array_size; p++) {
        double deviation = *p - mean;
        double fraction = deviation / s;
        sum += pow(fraction, 4.0);
    }
    //  return sum / (array_size-1) - 3; pandas uses (n-1)
    return sum / array_size - 3;
}
