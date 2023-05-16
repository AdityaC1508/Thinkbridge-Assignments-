#include <iostream>
#include <vector>

// Bubble Sort implementation
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break; // Array is already sorted, no need to continue
        }
    }
}

// Test the Bubble Sort function
int main() {
    std::vector<int> numbers = {5, 2, 8, 12, 1, 6};

    bubbleSort(numbers);

    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
