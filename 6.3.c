#include <stdio.h>

int partition(int arr[], int low, int high) {
    int run = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= run) {
            i++;
            
            // Обмен значениями элементов
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Обмен значениями элементов
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    int start[high - low + 1];
    int end[high - low + 1];
    int top = -1;
    
    start[++top] = low;
    end[top] = high;
    
    while (top >= 0) {
        low = start[top];
        high = end[top--];
        
        int runIndex = partition(arr, low, high);
        
        if (runIndex - 1 > low) {
            start[++top] = low;
            end[top] = runIndex - 1;
        }
        
        if (runIndex + 1 < high) {
            start[++top] = runIndex + 1;
            end[top] = high;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array before sorting: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Array after sorting: ");
    printArray(arr, n);
    
    return 0;
}
