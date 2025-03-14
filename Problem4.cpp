//SORTINGG

#include <iostream>
using namespace std;

// bubble sort

void bubble_sort(int arr[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {

                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            else
                continue;
        }
    }
}

// Partition function with first element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low + 1; // Start from the element after the pivot

    for (int j = low + 1; j <= high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]); // Move the smaller element to the left
            i++; // Increment the index of the smaller element
        }
    }
    // Place the pivot in its correct position
    swap(arr[low], arr[i - 1]);
    return i - 1; // Return the partition index
}

// QuickSort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}





int main() {
    int num[] = { 3, 8, 1, 7, 0, 10, 2 };
    int n = sizeof(num) / sizeof(num[0]); // Calculate the size of the array

    quicksort(num, 0, n - 1); // Sort the array

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
