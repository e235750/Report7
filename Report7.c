#include <stdio.h>
#include <limits.h>

void printArray(int array[], int size);
void numOrder(int array[], int size);
int contain(int target, int array[], int size);


int main(void){
    const int SIZE = 5; //定数として配列のサイズを宣言
    int scores[5] = {0, 60, 70, 100, 90};
    numOrder(scores, SIZE);

    printArray(scores, SIZE);

    return 0;
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i ++){
        printf("%d\n", array[i]);
    }
}

void numOrder(int array[], int size){
    int saved_array[size];

    for(int i = 0; i < size; i ++){
        int max_value = INT_MIN;

        for(int j = 0; j < size; j ++){
            if(array[j] >= max_value && !contain(array[j], saved_array, i)){
                max_value = array[j];
            }
        }
        
        saved_array[i] = max_value;
        // printf("%d\n", saved_array[i]);
    }
    
    for(int k = 0; k < size; k ++){
        array[k] = saved_array[k];
    }
}

int contain(int target, int array[], int size){
    for(int i = 0; i < size; i ++){
        if(target == array[i]){
            return 1;
        }
    }
    return 0;
}