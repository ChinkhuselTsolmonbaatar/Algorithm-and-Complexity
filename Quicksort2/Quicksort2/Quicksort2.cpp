#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] < arr[low]) swap(&arr[low], &arr[mid]);
    if (arr[high] < arr[low]) swap(&arr[low], &arr[high]);
    if (arr[high] < arr[mid]) swap(&arr[mid], &arr[high]);

    int pivot = arr[high];


    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    while (low < high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low < high - pivotIndex) {
            quicksort(arr, low, pivotIndex - 1);
            low = pivotIndex + 1;
        }
        else {
            quicksort(arr, pivotIndex + 1, high);
            high = pivotIndex - 1;
        }
    }
}

int main() {
    const int size = 50000;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i; 
    }

    cout << "Initial array (first 10 elements): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();
    quicksort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by quicksort: " << duration.count() << " ms" << endl;

    cout << "Sorted array (first 10 elements): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
