//
// Created by Admin on 26.02.2024.
//

#ifndef L1_DYNAMICARRAY_H
#define L1_DYNAMICARRAY_H

/*
 Структура DynamicArray, которая представляет собой динамический массив.
 */
typedef struct {
    void **array; // Массив указателей на элементы массива (любого типа).
    int size; // Количество элементов в массиве.
    int capacity; // Вместимость массива.
} DynamicArray;

DynamicArray *createDynamicArray(int capacity); // Создание динамического массива.

void deleteDynamicArray(DynamicArray *dynamicArray); // Удаление динамического массива.

void insert(DynamicArray *dynamicArray, int index, void* value); // Вставка элемента в массив.

void append(DynamicArray *dynamicArray, void* value); // Добавление элемента в конец массива.

void erase(DynamicArray *dynamicArray, int index); // Удаление элемента из массива.

void* get(DynamicArray *dynamicArray, int index); // Получение элемента массива.

void set(DynamicArray *dynamicArray, int index, void* value); // Установка значения элемента массива.

int size(DynamicArray *dynamicArray); // Получение количества элементов в массиве.

int capacity(DynamicArray *dynamicArray); // Получение вместимости массива.

#endif //L1_DYNAMICARRAY_H
