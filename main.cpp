#include "headers/helpers.h"

int main(int argc, char *argv[]) {
//    const std::string FILE_PATH = "/Users/trung/CLionProjects/APT_Assignment_1/data/data4.csv";
//    generate_sample_data(FILE_PATH, 50000, -50000, 50000);
//    display_statistics_calculation_time(main_driver_function);

    if (argc != 2) {
        std::cerr << "Must enter 1 argument" << std::endl;
        return 1;
    }
    main_driver_function(argv[1]);

    return 0;
}
