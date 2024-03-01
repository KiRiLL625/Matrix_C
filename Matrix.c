//
// Created by Admin on 26.02.2024.
//

#include <stdlib.h>
#include "Matrix.h"

Matrix *createMatrix(int rows, int columns) {
    //Выделение памяти под матрицу (структуру)
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    //Выделение памяти под динамический массив указателей на строки матрицы
    matrix->matrix_array = createDynamicArray(rows);
    for (int i = 0; i < rows; i++) {
        //Выделение памяти под динамический массив указателей на элементы строки матрицы
        DynamicArray *row = createDynamicArray(columns);
        for (int j = 0; j < columns; j++) {
            //Добавление в строку пустых указателей на элементы
            append(row, NULL);
        }
        //Добавление в матрицу строку
        append(matrix->matrix_array, row);
    }
    //Инициализация полей структуры по умолчанию
    matrix->rows = rows;
    matrix->columns = columns;
    return matrix;
}

void deleteMatrix(Matrix *matrix) {
    //Освобождение памяти, выделенной под динамический массив указателей на строки матрицы
    for (int i = 0; i < matrix->rows; i++) {
        deleteDynamicArray(get(matrix->matrix_array, i));
    }
    //Освобождение памяти, выделенной под матрицу (массив и саму структуру)
    deleteDynamicArray(matrix->matrix_array);
    free(matrix);
}

void setElement(Matrix *matrix, int row, int column, void *value) {
    //Установка значения элемента матрицы
    set(get(matrix->matrix_array, row), column, value);
}

void *getElement(Matrix *matrix, int row, int column) {
    //Получение значения элемента матрицы
    return get(get(matrix->matrix_array, row), column);
}

Matrix *add(Matrix *matrix1, Matrix *matrix2) {
    //Проверка на равенство размеров матриц
    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
        return NULL;
    }
    //Создание матрицы-результата
    Matrix *result = createMatrix(matrix1->rows, matrix1->columns);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->columns; j++) {
            //fixme
            //setElement(result, i, j, getElement(matrix1, i, j) + getElement(matrix2, i, j));
        }
    }
    return result;
}

Matrix *multiply(Matrix *matrix1, Matrix *matrix2) {
    //Проверка на возможность умножения матриц
    if (matrix1->columns != matrix2->rows) {
        return NULL;
    }
    //Создание матрицы-результата
    Matrix *result = createMatrix(matrix1->rows, matrix2->columns);
    //Умножение матриц
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->columns; j++) {
            void *value = 0;
            for (int k = 0; k < matrix1->columns; k++) {
                //fixme
                //value += getElement(matrix1, i, k) * getElement(matrix2, k, j);
            }
            setElement(result, i, j, value);
        }
    }
    return result;
}