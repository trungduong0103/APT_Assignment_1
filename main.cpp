#include "headers/helpers.h"

int main() {
    const std::string FILE_PATH = "/Users/trung/CLionProjects/APT_Assignment_1/data/data5.csv";
    generate_sample_data(FILE_PATH, 50000, -50000, 50000);
    display_statistics_calculation_time(main_driver_function);
    return 0;
}
