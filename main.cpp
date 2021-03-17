#include <iostream>
#include <fstream>
//#include <math.h>

using namespace std;

// enums
enum Column {
    x,
    y
};

unsigned int calculate_array_size(const string &file_name);

void extract_data_from_column(const string &file_name, int array[], Column column);

void print_array(int array[], unsigned int array_size);

long int sum_array(int array[], unsigned int array_size);

int main() {
    const string file_name = "/Users/trung/CLionProjects/APT_Assignment_1/data1.csv";
    const unsigned int array_size = calculate_array_size(file_name);
    int x_column_array[array_size], y_column_array[array_size];
    extract_data_from_column(file_name, x_column_array, Column::x);
    extract_data_from_column(file_name, y_column_array, Column::y);
}

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
    int count = 0;
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



