#include <stdio.h>
#include <limits.h>

void numOrder(int array[], int size);
void printArray(int array[], int size);

int main(void) {
    const int SIZE = 6;
    int scores[6] = {100, 60, 70, 100, 90, 80};
    numOrder(scores, SIZE);

    printArray(scores, SIZE);

    return 0;
}

void numOrder(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // 同じ数字の場合も交換するように修正
            if (array[j] < array[j + 1]) {
                int value = array[j];
                array[j] = array[j + 1];
                array[j + 1] = value;
            }
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}
