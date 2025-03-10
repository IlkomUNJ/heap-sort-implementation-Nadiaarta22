#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
  
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
  
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {3, 19, 1, 14, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diubah menjadi Max Heap:\n";
    printHeap(arr, n);

    buildMaxHeap(arr, n);

    cout << "Array setelah menjadi Max Heap:\n";
    printHeap(arr, n);

    return 0;
}
