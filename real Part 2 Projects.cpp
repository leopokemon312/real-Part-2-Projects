#include <iostream>

using namespace std;

/**
 * Function to reverse an array by dynamically creating a new array and copying elements in reverse order.
 * @param arr A constant integer array containing the original values.
 * @param size The number of elements in the array.
 * @return A pointer to the newly allocated array containing reversed elements.
 */
int* ReverseArray(const int arr[], int size) {
    int* reversedArr = new int[size];
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
    }
    return reversedArr;
}

/**
 * Function to print the contents of an integer array.
 * @param arr A constant integer array to be printed.
 * @param size The number of elements in the array.
 */
void print(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Define and initialize the original array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Original array: ";
    print(arr, size);

    // Reverse the array
    int* reversedArr = ReverseArray(arr, size);

    // Print the reversed array
    cout << "Reversed array: ";
    print(reversedArr, size);

    // Deallocate dynamically allocated memory
    delete[] reversedArr;

    return 0;
}
