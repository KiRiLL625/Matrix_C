#include <stdio.h>
#include "DynamicArray.h"

int main() {
    //Создание динамического массива
    DynamicArray *dynamicArray = createDynamicArray(2);
    int a = 1;
    int b = 2;
    int c = 3;
    //char* d = "Hello";
    append(dynamicArray, &a);
    append(dynamicArray, &b);
    append(dynamicArray, &c);
    //Если попросят сделать, например, переменные не int, то тип переменных a, b, c
    //нужно будет поменять на double и в printf *(int*) поменять на *(double *).
    //Если попросят сделать строки, то тип переменных a, b, c нужно будет поменять на char* и в printf *(int*) поменять на *(char*).
    //Формат вывода соответственно тоже поменяется (для строк %s, для double %lf).
    //Для float (маленький double) %f.
    //Вывод всех элементов массива
    for(int i = 0; i < size(dynamicArray); i++){
        printf("%d\n", *(int *) get(dynamicArray, i));
    }
    //Вывод элемента массива по индексу
    printf("%d\n", *(int *) get(dynamicArray, 2)); //Нумерация с нуля
    //Освобождение памяти, выделенной под динамический массив
    deleteDynamicArray(dynamicArray);
    return 0;
}
