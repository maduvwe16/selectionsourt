#include <iostream>
using namespace std;

/**
 * emmanuelmaduvwe
 * EB3/68882/23
 * Selection Sort Function
 * Sorts an array by repeatedly finding the minimum element from the unsorted part
 * and placing it at the beginning.
 * 
 * @param arr[] - The array to be sorted
 * @param n - The size of the array
 */
void selectionSort(int arr[], int n) {
    // Outer loop: Move through each element of the array
    // We only need n-1 passes because after n-1 elements are sorted,
    // the last element is automatically in the correct position
    for (int i = 0; i < n - 1; i++) {
        
        // Assume the current position (i) contains the minimum element
        // This index will be updated if we find a smaller element
        int minIndex = i;
        
        // Inner loop: Find the minimum element in the unsorted portion
        // Start from i+1 because elements before i are already sorted
        for (int j = i + 1; j < n; j++) {
            
            // If current element is smaller than our found minimum
            if (arr[j] < arr[minIndex]) {
                // Update minIndex to the new minimum's position
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the element at position i
        // Only perform swap if we found a smaller element (minIndex changed)
        if (minIndex != i) {
            // Store the current element in a temporary variable
            int temp = arr[i];
            
            // Place the minimum element at position i
            arr[i] = arr[minIndex];
            
            // Move the original element to where the minimum was found
            arr[minIndex] = temp;
        }
    }
}

/**
 * Main Function - Program entry point
 * Demonstrates the selection sort algorithm with a sample array
 */
int main() {
    // Initialize a sample array with unsorted integers
    // This array contains 5 elements in random order
    int arr[] = {64, 25, 12, 22, 11};
    
    // Calculate the number of elements in the array
    // sizeof(arr) gives total bytes of array
    // sizeof(arr[0]) gives bytes of one element
    // Dividing gives the total number of elements
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Display the original array before sorting
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Print each element followed by space
    }
    
    // Call the selection sort function to sort the array
    // Pass the array and its size as arguments
    selectionSort(arr, n);
    
    // Display the sorted array after sorting
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Print each sorted element
    }
    
    // Return 0 indicates successful program execution
    return 0;
}