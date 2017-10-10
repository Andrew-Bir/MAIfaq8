#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>

typedef float _Complex compl_t;

typedef struct {
    int m; // сколько строк
    int n; // сколько столбцов
    int _size; // счетчик элементов в data
    compl_t *_data; //значение - комплексное число
} matrix_t;

void create(matrix_t *, int, int); // создает матрицу m x n пустую
void destroy(matrix_t *);
void push_back(matrix_t *, float, compl_t); // добавляет в _data две "ячейки" col=nj value=с
void nextRow_set(matrix_t *, float); // добавляет в _data две "ячейки" col=0 value=row+1
void print_usual_view(matrix_t *); // выводит матрицу в обычном квадратно-гнездовом представлении m x n
void print_vector_view(matrix_t *); // выводит матрицу во "внутреннем представлении" т е один вектор
int get_first(matrix_t *, float); //  возвращает первую col!=0 в строке row или если таковой нет _size
compl_t get_el(matrix_t *, int, float); // возвращает значение данного n-ного элемента если таковой имеется или 0 (что равнозначно нулевому елементу)
int row_el_count(matrix_t *, float); // возвращает количество ненулевых элементов в строке
int max_count(matrix_t *);
void initiation(FILE *, matrix_t *, int, int);
void print_row_max_elem_count(matrix_t *);

#endif
