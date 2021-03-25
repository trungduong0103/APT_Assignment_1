#include <iostream>
#include <string>
#include "../headers/helpers.h"
#include "../headers/file.h"
#include "../headers/descriptive_statistics.h"
#include "../headers/inferential_statistics.h"
#include "../headers/merge_sort.h"

int main_driver_function() {
    // file name
    const std::string FILE_NAME = "/Users/trung/CLionProjects/APT_Assignment_1/data/data3.csv";
    // open the file and extract x and y columns to arrays
    if (can_open_file(FILE_NAME)) {
        const unsigned int ARRAY_SIZE = calculate_array_size(FILE_NAME);
        double *x_column_array = (double *)malloc(ARRAY_SIZE * sizeof(double)), *y_column_array = (double *)malloc(ARRAY_SIZE * sizeof(double));

        // validate if data in csv file is in correct format and extract data
        if (validate_and_extract_data_from_column(FILE_NAME, x_column_array, 'x') &&
            validate_and_extract_data_from_column(FILE_NAME, y_column_array, 'y')) {
            // inferential statistics
            // b1 covariance
            double cov_x_y = calculate_sample_covariance(x_column_array, y_column_array, ARRAY_SIZE);

            // b2 Pearson correlation coefficient (bivariate correlation or just correlation coefficient)
            double r_x_y = calculate_correlation_coefficient(x_column_array, y_column_array, ARRAY_SIZE);

            // b3 linear regression
            // TODO: finish this
            double reg_x_y;

            // sort for descriptive statistics
            merge_sort(x_column_array, 0, ARRAY_SIZE - 1);
            merge_sort(y_column_array, 0, ARRAY_SIZE - 1);

            // descriptive statistics
            // b1 median
            double median_x = calculate_median(x_column_array, ARRAY_SIZE);
            double median_y = calculate_median(y_column_array, ARRAY_SIZE);

            // b2 modes
            std::string modes_x = calculate_modes(x_column_array, ARRAY_SIZE);
            std::string modes_y = calculate_modes(y_column_array, ARRAY_SIZE);

            // b3 variance and standard deviation
            double variance_x = calculate_variance(x_column_array, ARRAY_SIZE);
            double variance_y = calculate_variance(y_column_array, ARRAY_SIZE);
            double stdev_x = calculate_standard_deviation(variance_x);
            double stdev_y = calculate_standard_deviation(variance_y);

            // b4 mean absolute deviation
            double mad_x = calculate_mad(x_column_array, ARRAY_SIZE);
            double mad_y = calculate_mad(y_column_array, ARRAY_SIZE);

            // b5 first quartile
            double q1_x = calculate_first_quantile(x_column_array, ARRAY_SIZE);
            double q1_y = calculate_first_quantile(y_column_array, ARRAY_SIZE);

            // b6 skewness
            double skew_x = calculate_skewness(x_column_array, ARRAY_SIZE);
            double skew_y = calculate_skewness(y_column_array, ARRAY_SIZE);

            // b7 kurtosis
            double kurt_x = calculate_kurtosis(x_column_array, ARRAY_SIZE);
            double kurt_y = calculate_kurtosis(y_column_array, ARRAY_SIZE);

            /*
            median_x=45 - median_y=96245.5
            mode_x={64.000000} - mode_y={95419.000000}
            var_x=134.3161217 - var_y=645123047.5
            stdev_x=11.58948324 - stdev_y=25399.27258
            mad_x=10.03658578 - mad_y=21033.12476
            q1_x=35 - q1_y=82930
            skew_x=0.01262271892 - skew_y=0.3619007236
            kurt_x=-1.200678883 - kurt_y=-0.7245041858
            cov(x_y)=1139.114745
            r(x_y)=0.003869742997
             */

            // display results
            std::cout.precision(10);
            std::cout << "median_x=" << median_x << " - median_y=" << median_y << std::endl;
            std::cout << "mode_x={" << modes_x << "} - mode_y={" << modes_y << "}" << std::endl;
            std::cout << "var_x=" << variance_x << " - var_y=" << variance_y << std::endl;
            std::cout << "stdev_x=" << stdev_x << " - stdev_y=" << stdev_y << std::endl;
            std::cout << "mad_x=" << mad_x << " - mad_y=" << stdev_y << std::endl;
            std::cout << "q1_x=" << q1_x << " - q1_y=" << q1_y << std::endl;
            std::cout << "skew_x=" << skew_x << " - skew_y=" << skew_y << std::endl;
            std::cout << "kurt_x=" << kurt_x << " - kurt_y=" << kurt_y << std::endl;
            std::cout << "cov(x_y)=" << cov_x_y << std::endl;
            std::cout << "r(x_y)=" << r_x_y << std::endl;

            return 0;
        }
    }

    // return 1 if the file cannot be read or the validate/extract function cannot be completed
    return 1;
}