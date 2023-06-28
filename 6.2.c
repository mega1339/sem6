#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid; // Найден элемент
        }
        
        if (arr[mid] < target) {
            return binarySearch(arr, mid + 1, high, target); // Рекурсивный вызов для правой половины массива
        } else {
            return binarySearch(arr, low, mid - 1, target); // Рекурсивный вызов для левой половины массива
        }
    }
    
    return -1; // Элемент не найден
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);
    
    int index = binarySearch(arr, 0, n - 1, target);
    
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}
