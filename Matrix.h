//
// Created by Admin on 26.02.2024.
//

#ifndef L1_MATRIX_H
#define L1_MATRIX_H

#include "DynamicArray.h"

/*
 Структура Matrix, которая представляет собой матрицу.
 */
typedef struct{
    DynamicArray *matrix_array; // Динамический массив указателей на строки матрицы.
    int rows; // Количество строк в матрице.
    int columns; // Количество столбцов в матрице.
} Matrix;

Matrix *createMatrix(int rows, int columns); // Создание матрицы.

void deleteMatrix(Matrix *matrix); // Удаление матрицы.

void setElement(Matrix *matrix, int row, int column, void *value); // Установка значения элемента матрицы.

void *getElement(Matrix *matrix, int row, int column); // Получение значения элемента матрицы.

Matrix* add(Matrix *matrix1, Matrix *matrix2); // Сложение матриц.

Matrix* multiply(Matrix *matrix1, Matrix *matrix2); // Умножение матриц.

Matrix* scalarMultiply(Matrix *matrix, void *scalar); // Умножение матрицы на скаляр.

Matrix* addLinearCombination(Matrix* matrix, int row, void* alphas); // Сложение линейной комбинации строк матрицы.

void printMatrix(Matrix *matrix); // Вывод матрицы.

#endif //L1_MATRIX_H
