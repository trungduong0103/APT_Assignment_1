#include <iostream>
#include "../headers/merge_sort.h"

// SOURCE USED: https://www.geeksforgeeks.org/merge-sort/

void merge(double arr[], unsigned int l, unsigned int m, unsigned int r) {
    unsigned int n1 = m - l + 1;
    unsigned int n2 = r - m;

    // Create temp arrays
    double *L = (double *)malloc(n1 * sizeof(double)), *R = (double *)malloc(n2 * sizeof(double));

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
void merge_sort(double arr[], unsigned int l, unsigned int r) {
    if (l >= r) {
        return;//returns recursively
    }
    unsigned int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}
