#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#include "matrix.h"

int main(void)
{
	int n, m;
	double x = 0.0, y = 0.0;
	Matrix mat;
	scanf("%d %d", &n, &m);
    matrix_create(&mat, n, m);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		scanf("%lf %lf", &x, &y);
    		elem_type val = x + y * I;
    		matrix_set(&mat, i, j, val);
    	}
    }
    matrix_check_null_rows(&mat);

    printf("\n\nМатрица %d на %d в обычном представлении:\n", mat.n, mat.m);
    print_full_matrix(&mat);

    print_in_computer_view(&mat);
    printf("\n\n");

	find_row_with_max_nonzero_elements(&mat);
	printf("\n");

    matrix_destroy(&mat);
    return 0;
}
