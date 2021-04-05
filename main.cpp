#include "headers/helpers.h"
#include "headers/validation.h"
#include "headers/test_functions.h"

int main(int argc, char *argv[]) {
//    const std::string FILE_PATH = "/Users/trung/CLionProjects/APT_Assignment_1/data/data4.csv";
//    generate_sample_data(FILE_PATH, 100000, -50000, 50000);

    if (!cli_input_is_correct(argc, argv)) {
        return 1;
    }

    display_statistics_calculation_time(argv[1], &main_driver_function);
//    main_driver_function(argv[1]);
    return 0;
}
