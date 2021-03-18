#include <iostream>
#include <fstream>
//#include <math.h>

using namespace std;

// enums
enum Column {
    x,
    y
};

void print_array(int array[], unsigned int array_size) {
    for (int *p = array; p < array + array_size; p++) {
        cout << *p << "\n";
    }
}

long int sum_array(int array[], unsigned int array_size) {
    long int sum = 0;
    for (int *p = array; p < array + array_size; p++) {
        sum += *p;
    }

    return sum;
}

unsigned int calculate_array_size(const string &file_name) {
    ifstream infile(file_name);
    if (!infile) {
        cerr << "Cannot read file: " << file_name << " !\n";
        return 1;
    }
    unsigned int count = 0;
    string line;
    // ignore the first column (x,y)
    getline(infile, line);
    while (getline(infile, line)) {
        count++;
    }
    infile.close();

    return count;
}

bool string_is_digits(const string &digits) {
    return digits.find_first_not_of("0123456789");
}

void extract_data_from_column(const string &file_name, int array[], Column column) {
    int index = 0;
    ifstream infile(file_name);
    if (!infile) {
        cerr << "Cannot read file: " << file_name << " !\n";
        return;
    }
    string line;
    getline(infile, line);
    while (getline(infile, line)) {
        // find the first occurrence of ',' to extract column numbers
        int index_to_comma = line.find(',');
        // x_value comes from beginning of array to index of ','
        string x_value = line.substr(0, index_to_comma);
        // y_value comes from beginning of ',' to end of line
        string y_value = line.substr(index_to_comma + 1, line.length());
        // 2 cases: x column and y column
        switch (column) {
            case x:
                if (!string_is_digits(x_value)) {
                    cerr << "Data is in incorrect format!\n";
                    return;
                }
                array[index] = stoi(x_value);
                break;
            case y:
                if (!string_is_digits(y_value)) {
                    cerr << "Data is in incorrect format!\n";
                    return;
                }
                array[index] = stoi(y_value);
                break;
            default:
                cerr << "column must be of Column enum!" << endl;
                break;
        }
        index++;
    }
    infile.close();
}

void merge(int arr[], unsigned int l, unsigned int m, unsigned int r) {
    unsigned int n1 = m - l + 1;
    unsigned int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

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
void merge_sort(int arr[], unsigned int l, unsigned int r) {
    if (l >= r) {
        return;//returns recursively
    }
    unsigned int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// B.1
float calculate_median(int array[], unsigned int array_size) {
    merge_sort(array, 0, array_size - 1);
    unsigned int middle_index = array_size / 2;
    if (array_size % 2 == 0) {
        return ((float) array[middle_index - 1] + (float) array[middle_index]) / 2;
    } else {
        return (float) array[middle_index];
    }
}

void calculate_medians_driver_function(int x_column[], int y_column[], unsigned int array_size) {
    cout << "median_x=" << calculate_median(x_column, array_size) << " - ";
    cout << "median_y=" << calculate_median(y_column, array_size) << endl;
}

// B.2
void calculate_modes(int array[], unsigned int array_size) {
    merge_sort(array, 0, array_size - 1);
    unsigned int occurrence = 1;
    unsigned int max_occurrence = 1;
    int tempValue = array[0];
    string modes;
    for (int *p = array; p < array + array_size; p++) {
        int currentValue = *p;
        if (tempValue == *p) {
            occurrence++;
        } else {
            if (occurrence == max_occurrence) {
                modes.append(to_string(tempValue) + " ");
            } else if (occurrence > max_occurrence) {
                modes.clear();
                modes.append(to_string(tempValue) + " ");
                max_occurrence = occurrence;
            }
            occurrence = 1;
            tempValue = currentValue;
        }
    }

    cout << modes << endl;
}

int main() {
    const string file_name = "/Users/trung/CLionProjects/APT_Assignment_1/data1.csv";
    const unsigned int ARRAY_SIZE = calculate_array_size(file_name);
    int x_column_array[ARRAY_SIZE], y_column_array[ARRAY_SIZE];
    extract_data_from_column(file_name, x_column_array, Column::x);
    extract_data_from_column(file_name, y_column_array, Column::y);

    calculate_medians_driver_function(x_column_array, y_column_array, ARRAY_SIZE);
    calculate_modes(x_column_array, ARRAY_SIZE);
    calculate_modes(y_column_array, ARRAY_SIZE);

//    merge_sort(x_column_array, 0, ARRAY_SIZE);
//    print_array(x_column_array, ARRAY_SIZE);
//    cout << calculate_mode(x_column_array, ARRAY_SIZE) << endl;

//    merge_sort(x_column_array, 0, ARRAY_SIZE - 1);
//    print_array(x_column_array, ARRAY_SIZE);
//    extract_data_from_column(file_name, y_column_array, Column::y);
//    merge_sort(y_column_array, 0, ARRAY_SIZE - 1);
//    print_array(y_column_array, ARRAY_SIZE);
}





