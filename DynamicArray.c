//
// Created by Admin on 26.02.2024.
//

#include "DynamicArray.h"

#include <stdlib.h>

DynamicArray *createDynamicArray(int capacity){
    //Выделение памяти под динамический массив (структуру)
    DynamicArray *dynamicArray = (DynamicArray *) malloc(sizeof(DynamicArray));
    //Выделение памяти под массив указателей на элементы массива (внутри структуры)
    dynamicArray->array = (void **) malloc(capacity * sizeof(void *));
    //Инициализация полей структуры по умолчанию
    dynamicArray->size = 0;
    dynamicArray->capacity = capacity;
    //Возврат указателя на динамический массив
    return dynamicArray;
}

void deleteDynamicArray(DynamicArray *dynamicArray) {
    //Освобождение памяти, выделенной под массив указателей на элементы массива
    free(dynamicArray->array);
    //Освобождение памяти, выделенной под динамический массив (структуру)
    free(dynamicArray);
}

void insert(DynamicArray *dynamicArray, int index, void* value) {
    //Если массив заполнен, то увеличиваем его вместимость вдвое
    if (dynamicArray->size == dynamicArray->capacity) {
        dynamicArray->capacity *= 2;
        //Выделение памяти под новый массив указателей на элементы массива
        void** tmp = (void**) realloc(dynamicArray->array, dynamicArray->capacity * sizeof(void *));
        //Если удалось выделить память, то обновляем указатель на массив
        if (tmp != NULL) {
            dynamicArray->array = tmp;
        }
        //Иначе, возвращаемся из функции
        else {
            return;
        }
    }
    //Сдвигаем элементы массива вправо, начиная с индекса index
    for (int i = dynamicArray->size; i > index; i--) {
        dynamicArray->array[i] = dynamicArray->array[i - 1];
    }
    //Устанавливаем значение value на место элемента с индексом index
    dynamicArray->array[index] = value;
    //Увеличиваем количество элементов в массиве
    dynamicArray->size++;
}

void append(DynamicArray *dynamicArray, void* value) {
    //Вставка элемента в конец массива
    insert(dynamicArray, dynamicArray->size, value);
}

void erase(DynamicArray *dynamicArray, int index) {
    //Сдвигаем элементы массива влево, начиная с индекса index
    for (int i = index; i < dynamicArray->size - 1; i++) {
        dynamicArray->array[i] = dynamicArray->array[i + 1];
    }
    //Уменьшаем количество элементов в массиве
    dynamicArray->size--;
}

void* get(DynamicArray *dynamicArray, int index) {
    //Возвращаем значение элемента массива с индексом index
    return dynamicArray->array[index];
}

void set(DynamicArray *dynamicArray, int index, void* value) {
    //Устанавливаем значение value на место элемента с индексом index
    dynamicArray->array[index] = value;
}

int size(DynamicArray *dynamicArray) {
    //Возвращаем количество элементов в массиве
    return dynamicArray->size;
}

int capacity(DynamicArray *dynamicArray) {
    //Возвращаем вместимость массива
    return dynamicArray->capacity;
}