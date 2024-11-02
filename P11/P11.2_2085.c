#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void sortEvenOdd(int arr[], int n) {
    int evenCount = 0, oddCount = 0;
    int *evenArr = (int*)malloc(n * sizeof(int));
    int *oddArr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[evenCount++] = arr[i];
        } else {
            oddArr[oddCount++] = arr[i];
        }
    }

    qsort(evenArr, evenCount, sizeof(int), compareAsc);
    qsort(oddArr, oddCount, sizeof(int), compareDesc);

    int index = 0;
    for (int i = 0; i < evenCount; i++) {
        arr[index++] = evenArr[i];
    }
    for (int i = 0; i < oddCount; i++) {
        arr[index++] = oddArr[i];
    }

    free(evenArr);
    free(oddArr);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortEvenOdd(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}