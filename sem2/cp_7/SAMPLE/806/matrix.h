#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef complex double elem_type;

typedef struct {
	int n;
	int m;
	int entries;
	int *rowp;
	int *column;
	elem_type *elem;
} Matrix;

void matrix_create(Matrix *mat, int n, int m);
void matrix_destroy(Matrix *mat);
void matrix_set(Matrix *mat, int i, int j, elem_type val);
void matrix_check_null_rows(Matrix *mat);
elem_type matrix_get(Matrix *mat, int i, int j);

void print_full_matrix(Matrix *mat);
void print_sum_row_elements(Matrix *mat, int i, elem_type sum);
void print_in_computer_view(Matrix *mat);

void find_row_with_max_nonzero_elements(Matrix *mat);

#endif
