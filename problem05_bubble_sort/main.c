// Bubble Sort: O(n^2) best case (when array is already sorted)
#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;
    for(i = 0; i < n-1; i++) {
        swapped = 0;
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
