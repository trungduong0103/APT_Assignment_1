#include <fstream>

void print_array(int array[], unsigned int array_size) {
    for (int *p = array; p < array + array_size; p++) {
        std::cout << *p << "\n";
    }
}

float sum_array(float array[], unsigned int array_size) {
    float sum = 0;
    for (float *p = array; p < array + array_size; p++) {
        sum += *p;
    }

    return sum;
}

unsigned int calculate_array_size(const std::string &file_name) {
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << " !\n";
        return 1;
    }
    unsigned int count = 0;
    std::string line;
    // ignore the first column (x,y)
    getline(infile, line);
    while (getline(infile, line)) {
        count++;
    }
    infile.close();

    return count;
}