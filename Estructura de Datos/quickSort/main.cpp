#include <iostream>
using namespace std;

void quicksort(int arr[], int low, int high) {
    int i = low, j = high, pivot = arr[(low + high) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j) quicksort(arr, low, j);
    if (i < high) quicksort(arr, i, high);
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 1, 4, 9, 22, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
