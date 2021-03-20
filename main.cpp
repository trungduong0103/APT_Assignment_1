#include <iostream>
#include "headers/file.h"
#include "headers/merge_sort.h"
#include "headers/helper_functions.h"
#include "headers/descriptive_statistics.h"

// B.5
//float calculate_first_quantile(const float array[], unsigned int array_size) {
//    unsigned int first_quantile_index = (array_size - 1) / 4;
//    float fraction = (float) array_size / 4 - (float) first_quantile_index;
//    float i = array[first_quantile_index];
//    float j = array[first_quantile_index + 1];
//    return i + (j - i) * fraction;
//}
//
//void calculate_first_quantiles_driver_function(float x_column[], float y_column[], unsigned int array_size) {
//    cout << "q1_x=" << calculate_first_quantile(x_column, array_size) << " - ";
//    cout << "q1_y=" << calculate_first_quantile(y_column, array_size) << endl;
//}

// B.6
//float calculate_variance(float array[], unsigned int array_size) {
//    float mean = calculate_mean(array, array_size);
//    float deviation[array_size];
//    // Chỗ này e loop 2 lần để mốt có gì mình bỏ thẳng cái deviation vô đây luôn
//    for (int i = 0; i < array_size; i++) {
//        deviation[i] = array[i] - mean;
//    }
//    float numerator = 0;
//    for (float *p = array; p < array + array_size; p++) {
//        float deviation = *p - mean;
//        numerator += pow(deviation, 2.0);
//    }
//    return (float) numerator / (array_size - 1);
//
//}

//double calculate_skewness(double array[], unsigned int array_size) {
//    double mean = calculate_mean(array, array_size);
//    double s = sqrt(calculate_variance(array, array_size));
//    double deviation[array_size];
//    double sum = 0;
//    for (double *p = array; p < array + array_size; p++) {
//        double deviation = *p - mean;
//        double fraction = deviation / s;
//        sum += pow(fraction, 3.0);
//    }
//    return sum / array_size;
//}
//
//void calculate_skewness_driver_function(double x_column[], double y_column[], unsigned int array_size) {
//    cout << "skew_x=" << calculate_skewness(x_column, array_size) << " - ";
//    cout << "skew_y=" << calculate_skewness(y_column, array_size) << endl;
//}
//
// B.7
//float calculate_kurtosis(double array[], unsigned int array_size) {
//    double mean = calculate_mean(array, array_size);
//    double s = sqrt(calculate_variance(array, array_size));
//    float sum = 0;
//    for (double *p = array; p < array + array_size; p++) {
//        double deviation = *p - mean;
//        double fraction = deviation / s;
//        sum += pow(fraction, 4.0);
//    }
//    return sum / array_size;
//}

//void calculate_kurtosis_driver_function(double x_column[], double y_column[], unsigned int array_size) {
//    cout << "kurt_x=" << calculate_kurtosis(x_column, array_size) << " - ";
//    cout << "kurt_y=" << calculate_kurtosis(y_column, array_size) << endl;
//}

// C.1

//float calculate_covariance(double x_column[], double y_column[], unsigned int array_size) {
//    float mean_x = calculate_mean(x_column, array_size);
//    float mean_y = calculate_mean(y_column, array_size);
//    float sum = 0;
//    for (int i = 0; i < array_size; i++) {
//        float deviation_x = x_column[i] - mean_x;
//        float deviation_y = y_column[i] - mean_y;
//        sum += deviation_x * deviation_y;
//    }
//    return sum / (array_size - 1);
//}

int main() {
    const std::string FILE_NAME = "/Users/trung/CLionProjects/APT_Assignment_1/datasets/data3.csv";
    if (can_open_file(FILE_NAME)) {
        const unsigned int ARRAY_SIZE = calculate_array_size(FILE_NAME);
        double x_column_array[ARRAY_SIZE], y_column_array[ARRAY_SIZE];

        if (validate_and_extract_data_from_column(FILE_NAME, x_column_array, Column::x) &&
            validate_and_extract_data_from_column(FILE_NAME, y_column_array, Column::y)) {
            merge_sort(x_column_array, 0, ARRAY_SIZE - 1);
            merge_sort(y_column_array, 0, ARRAY_SIZE - 1);

            std::cout.precision(10);
//            calculate_medians_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_modes_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
//            calculate_variance_standard_variance_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
//            calculate_mad_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
        } else {
            return 1;
        }

        return 0;
    }
    return 1;

}
