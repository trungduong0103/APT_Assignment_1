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

string calculate_mode(int array[], unsigned int array_size) {
    string modes;
    print_array(array, array_size);
    // Initialize modes variable to store all the mode value
//    vector<int> modes;
    // Assign temporary value at the first value in the vector

    int tempValue = array[0];
    // Initialize current_count with 1
    int currentCount = 1;
    // Initialize maxCount variable to store the max count
    int maxCount = 0;

    for (int i = 1; i < array_size; i++) {
        int currentValue = array[i];
//        cout << currentValue << endl;
        if (currentValue == tempValue) {
            currentCount++;
        } else {
            if (currentCount == maxCount) {
                modes.push_back(tempValue);
            } else if (currentCount > maxCount) {
                maxCount = currentCount;
                modes.clear();
                modes.push_back(tempValue);
            }
            currentCount = 1;
        }
        tempValue = currentValue;
    }

    if (currentCount == maxCount) {
        modes.push_back(tempValue);
    } else if (currentCount > maxCount) {
        maxCount = currentCount;
        modes.clear();
        modes.push_back(tempValue);
    }

    return modes;
}

int main() {
    const string file_name = "/Users/trung/CLionProjects/APT_Assignment_1/data1.csv";
    const unsigned int ARRAY_SIZE = calculate_array_size(file_name);
    int x_column_array[ARRAY_SIZE], y_column_array[ARRAY_SIZE];
    extract_data_from_column(file_name, x_column_array, Column::x);
    calculate_mode(x_column_array, ARRAY_SIZE);
//    merge_sort(x_column_array, 0, ARRAY_SIZE);
//    print_array(x_column_array, ARRAY_SIZE);
//    cout << calculate_mode(x_column_array, ARRAY_SIZE) << endl;

//    merge_sort(x_column_array, 0, ARRAY_SIZE - 1);
//    print_array(x_column_array, ARRAY_SIZE);
//    extract_data_from_column(file_name, y_column_array, Column::y);
//    merge_sort(y_column_array, 0, ARRAY_SIZE - 1);
//    print_array(y_column_array, ARRAY_SIZE);
}





