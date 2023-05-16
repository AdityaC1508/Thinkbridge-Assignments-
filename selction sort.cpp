#include <iostream>
#include <vector>

// Selection Sort implementation
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the current element
        std::swap(arr[i], arr[minIndex]);
    }
}

// Test the Selection Sort function
int main() {
    std::vector<int> numbers = {5, 2, 8, 12, 1, 6};

    selectionSort(numbers);

    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
