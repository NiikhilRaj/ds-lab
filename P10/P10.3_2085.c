#include <stdio.h>

void selectionSort(int arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending ? (arr[j] < arr[idx]) : (arr[j] > arr[idx])) {
                idx = j;
            }
        }
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array sorted in ascending order:\n");
    selectionSort(arr, n, 1);
    printArray(arr, n);

    printf("Array sorted in descending order:\n");
    selectionSort(arr, n, 0);
    printArray(arr, n);

    return 0;
}