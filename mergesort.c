#include <stdio.h>

void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    // Копирование данных во временные массивы
    for (i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];

    // Слияние временных массивов в исходный массив
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов левого массива
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов правого массива
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Рекурсивная сортировка двух половинок массива
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Слияние двух отсортированных половинок
        merge(array, left, middle, right);
    }
}

// Функция для вывода массива на экран
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Введите размер массива: ");
    scanf("%d", &size);

    int array[size];

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Исходный массив:\n");
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    printf("Отсортированный массив:\n");
    printArray(array, size);

    return 0;
}
