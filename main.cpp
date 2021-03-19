#include <iostream>
#include <fstream>
//#include <math.h>

// enums
enum Column {
    x,
    y
};

void print_array(float array[], unsigned int array_size) {
    for (float *p = array; p < array + array_size; p++) {
        std::cout << *p << "\n";
    }
}

long int sum_array(int array[], unsigned int array_size) {
    long int sum = 0;
    for (int *p = array; p < array + array_size; p++) {
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

bool string_is_digits(const std::string &digits) {
    if (digits[0] == '-') {
        return digits.substr(1, digits.length()).find_first_not_of("0123456789");
    }
    return digits.find_first_not_of("0123456789");
}

void extract_data_from_column(const std::string &file_name, float array[], Column column) {
    int index = 0;
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "Cannot read file: " << file_name << " !\n";
        return;
    }
    std::string line;
    getline(infile, line);
    while (getline(infile, line)) {
        // find the first occurrence of ',' to extract column numbers
        int index_to_comma = line.find(',');
        // x_value comes from beginning of array to index of ','
        std::string x_value = line.substr(0, index_to_comma);
        // y_value comes from beginning of ',' to end of line
        std::string y_value = line.substr(index_to_comma + 1, line.length());
        // 2 cases: x column and y column
        switch (column) {
            case x:
                if (!string_is_digits(x_value)) {
                    std::cerr << "Data is in incorrect format, data: " << x_value << std::endl;
                    return;
                }
                array[index] = std::stof(x_value);
                break;
            case y:
                if (!string_is_digits(y_value)) {
                    std::cerr << "Data is in incorrect format, data: " << x_value << std::endl;
                    return;
                }
                array[index] = std::stof(y_value);
                break;
            default:
                std::cerr << "column must be of Column enum!" << std::endl;
                break;
        }
        index++;
    }
    infile.close();
}

void merge(float arr[], unsigned int l, unsigned int m, unsigned int r) {
    unsigned int n1 = m - l + 1;
    unsigned int n2 = r - m;

    // Create temp arrays
    float L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    unsigned int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void merge_sort(float arr[], unsigned int l, unsigned int r) {
    if (l >= r) {
        return;//returns recursively
    }
    unsigned int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// B.1
float calculate_median(float sorted_array[], unsigned int array_size) {
    unsigned int middle_index = array_size / 2;
    if (array_size % 2 == 0) {
        return ((float) sorted_array[middle_index - 1] + (float) sorted_array[middle_index]) / 2;
    } else {
        return (float) sorted_array[middle_index];
    }
}

void calculate_medians_driver_function(float x_column[], float y_column[], unsigned int array_size) {
    std::cout << "median_x=" << calculate_median(x_column, array_size) << " - ";
    std::cout << "median_y=" << calculate_median(y_column, array_size) << std::endl;
}

// B.2
std::string calculate_modes(float array[], unsigned int array_size) {
    merge_sort(array, 0, array_size - 1);
    unsigned int occurrence = 1;
    unsigned int max_occurrence = 1;
    float tempValue = array[0];
    std::string modes;
    for (float *p = array; p < array + array_size; p++) {
        float currentValue = *p;
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

void calculate_modes_driver_function(float x_column[], float y_column[], unsigned int array_size) {
    std::cout << "mode_x={" << calculate_modes(x_column, array_size) << "} - ";
    std::cout << "mode_y={" << calculate_modes(y_column, array_size) << "}" << std::endl;
}

// B.3

int main() {
    const std::string FILE_NAME = "/Users/trung/CLionProjects/APT_Assignment_1/data1.csv";
    const unsigned int ARRAY_SIZE = calculate_array_size(FILE_NAME);
    float x_column_array[ARRAY_SIZE], y_column_array[ARRAY_SIZE];
    extract_data_from_column(FILE_NAME, x_column_array, Column::x);
    extract_data_from_column(FILE_NAME, y_column_array, Column::y);
    merge_sort(x_column_array, 0, ARRAY_SIZE - 1);
    merge_sort(y_column_array, 0, ARRAY_SIZE - 1);
    calculate_medians_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
    calculate_modes_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
}





