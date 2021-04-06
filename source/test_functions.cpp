//#include <iostream>
//#include <fstream>
//#include <string>
//#include <random>
//
//void display_statistics_calculation_time(const char *FILE_PATH, int(*function)(const char*)) {
//    auto t1 = std::chrono::high_resolution_clock::now();
//    function(FILE_PATH);
//    auto t2 = std::chrono::high_resolution_clock::now();
//
//    /* Getting number of milliseconds as an integer. */
//    // auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
//
//    /* Getting number of milliseconds as a double. */
//    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
//
//    std::cout << "Execution time in ms: " << ms_double.count() << "ms" << std::endl;
//}
//
//double generate_random_double(double min, double max) {
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_real_distribution<double> dist(min, max);
//
//    return dist(mt);
//}
//
//bool generate_sample_data(const std::string &FILE_PATH, unsigned long int num_of_columns, double lower_bound,
//                          double upper_bound) {
//    std::ofstream outfile(FILE_PATH);
//    if (!outfile.is_open()) {
//        std::cerr << "Cannot create file at" << FILE_PATH << std::endl;
//        return false;
//    }
//
//    outfile << "x,y" << std::endl;
//
//    for (int i = 0; i < num_of_columns; i++) {
//        double random_x = generate_random_double(lower_bound, upper_bound);
//        double random_y = generate_random_double(lower_bound, upper_bound);
//        std::string new_line = i == num_of_columns - 1 ? "" : "\n";
//        if (i != num_of_columns) {
//            outfile << random_x << "," << random_y << new_line;
//        }
//    }
//
//    std::cout << "csv file generated at " << FILE_PATH << std::endl;
//
//    outfile.close();
//    return true;
//}