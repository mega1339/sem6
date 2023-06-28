#include <stdio.h>

#define RANGE 1000 // Диапазон чисел для сортировки

void countingSort(int array[], int size) {
    int output[size]; // Выходной массив
    int count[RANGE + 1]; // Вспомогательный массив для подсчета элементов

    // Инициализация вспомогательного массива нулями
    for (int i = 0; i <= RANGE; i++) {
        count[i] = 0;
    }

    // Подсчет количества элементов
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Подсчет позиции элемента в выходном массиве
    for (int i = 1; i <= RANGE; i++) {
        count[i] += count[i - 1];
    }

    // Формирование выходного массива
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Копирование отсортированного массива обратно в исходный
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
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

    printf("enter size of massive: ");
    scanf("%d", &size);

    int array[size];

    printf("enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("befor sorting:\n");
    printArray(array, size);

    countingSort(array, size);

    printf("sfter sorting:\n");
    printArray(array, size);

    return 0;
}
