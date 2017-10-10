#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include "matrix.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

void matrix_create(Matrix *mat, int n, int m)
{
	mat->n = n; // сколько столбцов возможно
	mat->m = m; // сколько строк
	mat->entries = 0;  // это похоже количество т е по сути это размер size
	mat->rowp = (int *)malloc((n + 1) * sizeof(int)); // строка
	mat->column = (int *)malloc(1 * sizeof(int)); // столбец
	mat->elem = NULL; // значение комплексное число
	memset(mat->rowp, 0, (n + 1) * sizeof(int)); // первые n+1 mat->rowp массива заполняются символом ‘0’ пока не знаю зачем
	mat->column[0] = 0;
}

void matrix_destroy(Matrix *mat)
{
	free(mat->rowp);
	free(mat->column);
	free(mat->elem);
}

void matrix_set(Matrix *mat, int i, int j, elem_type val)
{
	if (val == 0)
		return;
	for (int k = i + 1; k <= mat->n; ++k)
		mat->rowp[k]++;

	mat->entries++;
	mat->column = (int *)realloc(mat->column, (mat->entries + 1) * sizeof(int));
	mat->elem = (elem_type *)realloc(mat->elem, (mat->entries + 1) * sizeof(elem_type));
	mat->column[mat->entries - 1] = j;
	mat->elem[mat->entries - 1] = val;
}

void matrix_check_null_rows(Matrix *mat)
{
	for (int i = 0; i < mat->n; ++i) {
		if (mat->rowp[i] == mat->rowp[i + 1])
			mat->rowp[i] = -1;
	}
}

elem_type matrix_get(Matrix *mat, int i, int j)
{
	if (mat->rowp[i] == -1)
		return 0;
	for (int k = i + 1; k <= mat->n; ++k) {
		if (mat->rowp[k] != -1) {
			for (int l = mat->rowp[i]; l < mat->rowp[k]; ++l) {
				if (mat->column[l] == j)
					return mat->elem[l];					
			}
			break;
		}
	}
	return 0;
}

void print_full_matrix(Matrix *mat)
{
	for (int i = 0; i < mat->n; ++i) {
		for (int j = 0; j < mat->m; ++j) {
			elem_type num = matrix_get(mat, i, j);
			printf("(%.2lf + %.2lfi) ", creal(num), cimag(num));			
		}
		printf("\n");
	}
	printf("\n");
}

void print_sum_row_elements(Matrix *mat, int i, elem_type sum)
{
	printf("Строка под номером %d содержит наибольшее количество ненулевых элементов, а их сумма == %.2lf + %.2lfi\n\n", i + 1, creal(sum), cimag(sum));
}

void find_row_with_max_nonzero_elements(Matrix *mat)
{
	int max_elems = 0;
	elem_type sum_row_elems[mat->n];
	int nonzero_elems_in_row[mat->n];

	for (int i = 0; i < mat->n; ++i) {
		sum_row_elems[i] = 0;
		nonzero_elems_in_row[i] = 0;
		for (int j = 0; j < mat->m; ++j) {
			if (matrix_get(mat, i, j) != 0) {
				sum_row_elems[i] += matrix_get(mat, i, j);
				++nonzero_elems_in_row[i];
			}
		}
		max_elems = max(max_elems, nonzero_elems_in_row[i]);
	}

	for (int i = 0; i < mat->n; ++i) {
		if (max_elems == nonzero_elems_in_row[i])
			print_sum_row_elements(mat, i, sum_row_elems[i]);
	}
}

void print_in_computer_view(Matrix *mat)
{
	printf("CIP: ");
    for (int i = 0; i < mat->n; ++i)
    	printf("%d ", mat->rowp[i]);
    printf("\n\n");

    printf("PI: ");
    for (int i = 0; i < mat->entries; ++i)
    	printf("      %d       ", mat->column[i]);
    printf("\n");

    printf("YE: ");
    for (int i = 0; i < mat->entries; ++i)
    	printf("(%.2lf + %.2lf) ", creal(mat->elem[i]), cimag(mat->elem[i]));
}
