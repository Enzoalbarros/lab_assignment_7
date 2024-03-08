#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // Increment the swap count for the swapped elements
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
                // Increment the total swap count
                total_swaps++;
            }
        }
    }
    printf("Total number of swaps (Bubble Sort): %d\n", total_swaps);
    printf("Number of swaps for each element:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap arr[min_idx] and arr[i] only if necessary
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            // Increment the swap count for the swapped elements
            swaps[arr[min_idx]]++;
            swaps[arr[i]]++;
            // Increment the total swap count
            total_swaps++;
        }
    }
    printf("Total number of swaps (Selection Sort): %d\n", total_swaps);
    printf("Number of swaps for each element:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    // Find the maximum element in array1
    int max1 = array1[0];
    for (int i = 1; i < n1; i++) {
        if (array1[i] > max1) {
            max1 = array1[i];
        }
    }

    // Find the maximum element in array2
    int max2 = array2[0];
    for (int i = 1; i < n2; i++) {
        if (array2[i] > max2) {
            max2 = array2[i];
        }
    }

    // Arrays to store swap counts for each sorting method
    int swaps1_bubble[max1+1];
    int swaps2_bubble[max2+1];
    int swaps1_selection[max1+1];
    int swaps2_selection[max2+1];

    // Initialize swap count arrays with zeros
    for (int i = 0; i <= max1; i++) {
        swaps1_bubble[i] = 0;
        swaps1_selection[i] = 0;
    }
    for (int i = 0; i <= max2; i++) {
        swaps2_bubble[i] = 0;
        swaps2_selection[i] = 0;
    }

    printf("array1 bubble sort:\n");
    bubbleSort(array1, n1, swaps1_bubble);

    printf("\narray2 bubble sort:\n");
    bubbleSort(array2, n2, swaps2_bubble);

    printf("\narray1 selection sort:\n");
    selectionSort(array3, n1, swaps1_selection);

    printf("\narray2 selection sort:\n");
    selectionSort(array4, n2, swaps2_selection);

    return 0;
}
