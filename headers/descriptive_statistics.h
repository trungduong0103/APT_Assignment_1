#include <fstream>
#include <math.h>
// B.1
double calculate_median(double sorted_array[], unsigned int array_size) {
    unsigned int middle_index = array_size / 2;
    if (array_size % 2 == 0) {
        return (sorted_array[middle_index - 1] + sorted_array[middle_index]) / 2;
    } else {
        return sorted_array[middle_index];
    }
}

void calculate_medians_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    std::cout << "median_x=" << calculate_median(x_column, array_size) << " - ";
    std::cout << "median_y=" << calculate_median(y_column, array_size) << std::endl;
}

// B.2
std::string calculate_modes(double array[], unsigned int array_size) {
    unsigned int occurrence = 1;
    unsigned int max_occurrence = 1;
    double tempValue = array[0];
    std::string modes;
    for (double *p = array; p < array + array_size; p++) {
        double currentValue = *p;
        if (tempValue == *p) {
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
    return modes.substr(0, modes.length() - 2);
}

void calculate_modes_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    std::cout << "mode_x={" << calculate_modes(x_column, array_size) << "} - ";
    std::cout << "mode_y={" << calculate_modes(y_column, array_size) << "}" << std::endl;
}

// B.3
double calculate_mean(double array[], unsigned int array_size) {
    double sum = 0;
    int index = 0;
    for (double *p = array; p < array + array_size; p++) {
        sum += *p;
        index++;
    }

    return sum / (double) array_size;
}

double calculate_variance(double array[], unsigned int array_size) {
    double mean = calculate_mean(array, array_size);
    double diff = 0;
    for (double *ptr = array; ptr < array + array_size; ptr++) {
        diff += pow(*ptr - mean, 2);
    }
    return diff / (double) (array_size - 1);
}

double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

void
calculate_variance_standard_variance_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    double x_variance = calculate_variance(x_column, array_size);
    double y_variance = calculate_variance(y_column, array_size);
    std::cout << "var_x=" << x_variance << " - " << "var_y=" << y_variance << std::endl;
    std::cout << "stdev_x=" << calculate_standard_deviation(x_variance) << " - stdev_y="
              << calculate_standard_deviation(y_variance) << std::endl;
}

// B.4
double calculate_mad(double array[], unsigned int array_size) {
    double mean = calculate_mean(array, array_size);
    double diff = 0;
    for (double *ptr = array; ptr < array + array_size; ptr++) {
        diff += abs(*ptr - mean);
    }
    return diff / array_size;
}

//mad_x=__ - mad_y=__
void calculate_mad_driver_function(double x_column[], double y_column[], unsigned int array_size) {
    std::cout << "mad_x=" << calculate_mad(x_column, array_size) << " - mad_y=" << calculate_mad(y_column, array_size)
              << std::endl;
}