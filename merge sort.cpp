#include <iostream>
#include <vector>

// Merge two sorted subarrays into a single sorted subarray
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Number of elements in the left subarray
    int n2 = right - mid;     // Number of elements in the right subarray

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = left;  // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Merge sort function
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print the elements of an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int size = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
