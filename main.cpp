#include "headers/file.h"
#include "headers/merge_sort.h"
#include "headers/helpers.h"
#include "headers/descriptive_statistics.h"
#include "headers/inferential_statistics.h"

using namespace std;

// TODO:
// refactor driver functions, 1 driver function only
// ONLY accepts calculated values, DO NOT use calculation in the driver functions

// FLOW
// create variable -> calculate descriptive/inferential stats -> pass to driver functions --> done

int main() {
    //File name
    const std::string FILE_NAME = "/Users/trung/CLionProjects/APT_Assignment_1/data/data1.csv";

    //Open the file and read data into x and y arrays
    if (can_open_file(FILE_NAME)) {
//        Initialize two arrays fo size ARRAY_SIZE
        const unsigned int ARRAY_SIZE = calculate_array_size(FILE_NAME);
        double x_column_array[ARRAY_SIZE], y_column_array[ARRAY_SIZE];

        //Validate if data is in correct format and read into them
        if (validate_and_extract_data_from_column(FILE_NAME, x_column_array, 'x') &&
            validate_and_extract_data_from_column(FILE_NAME, y_column_array, 'y')) {
            double cov_x_y = calculate_sample_covariance(x_column_array, y_column_array, ARRAY_SIZE);
            double r_x_y = calculate_correlation_coefficient(x_column_array, y_column_array, ARRAY_SIZE);

            merge_sort(x_column_array, 0, ARRAY_SIZE - 1);
            merge_sort(y_column_array, 0, ARRAY_SIZE - 1);

            //Set doubleing point number precision for display
            std::cout.precision(10);

            //Diplay result for descriptive statistics
            calculate_medians_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_modes_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_variance_standard_variance_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_mad_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_first_quantiles_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_skewness_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
            calculate_kurtosis_driver_function(x_column_array, y_column_array, ARRAY_SIZE);

            //Display result for inferential statistics
            calculate_sample_covariance_driver_function(cov_x_y);
            calculate_correlation_coefficient_driver_function(r_x_y);
            // display_linear_regression_formula(double mean_x, double mean_y, double stdev_x, double stdev_y, double r)
        } else {
            return 1;
        }

        return 0;
    }
    return 1;

}
