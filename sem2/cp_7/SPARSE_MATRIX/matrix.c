#include "matrix.h"

void create(matrix_t *mat, int m, int n){
    mat->m = m;
    mat->n = n;
    mat->_size = 0;
    mat->_data = NULL;
    mat->_data = (compl_t *)malloc(1 * sizeof(compl_t)); //выделяем память
    mat->_data[0] = 0;
}

void destroy(matrix_t *mat){
    mat->_data = NULL;
    mat->_data = (compl_t *)malloc(1 * sizeof(compl_t));
    free(mat->_data);
}

void push_back(matrix_t *mat, float nj, compl_t c){
    mat->_size++;
    mat->_data[mat->_size-1] = nj;
    mat->_size++;
    mat->_data[mat->_size-1] = c;
}

void nextRow_set(matrix_t *mat, float mi){
    mat->_size++;
    mat->_data[mat->_size-1] = 0;
    mat->_size++;
    mat->_data[mat->_size-1] = mi;
}

void initiation(FILE *pfile, matrix_t *mat, int m, int n) {
    compl_t c;
    float pReal;
    float pImag;
    char sign;
    for (int row = 0; row < m; ++row) {
        // проверяем вдруг у нас предыдущая строка была совсем пустой тогда нам ее как бы и незачем хранить
        /*if (row!=0 && mat->_data[mat->_size-1]==0.0+0.0*I) {
         *           mat->_data[mat->_size] = row+1; // записываем на ее место значение+1 текущей строки
    } else {
        тут есть свои подводные камни - есть мнение что может не сработать функция get_el так как нужно,
        а ковыряться лень, пусть пока будут пустые строки
        */
        nextRow_set(mat, row+1); // иначе добавляем col=0 value=row+1
        //}
        for (int col = 0; col < n; ++col) {
            if (fscanf(pfile,"%f%c%fi",&pReal,&sign,&pImag)==3) {
                if( sign == '-' ) {
                    pImag *= -1;
                }
                c = pReal + pImag*I;
                if (c){
                    push_back(mat, col+1, c);
                }
            } else {
                printf("Failed to read complex.\n");
                exit(1);
            }
        }
    }
    nextRow_set(mat, 0); // иначе добавляем col=0 value=row+1
}
// выводим матрицу в традиционном виде
void print_usual_view(matrix_t *mat){
    for (int i = 0; i < mat->m; ++i) {
        int it = get_first(mat, i+1);
        printf("|  ");
        for (int j = 0; j < mat->n; ++j) {
            compl_t c = get_el(mat, it, j+1);
            printf("%.3f%+.3fi ",creal(c),cimag(c));
            if(c) it+=2; // если у нас вернулся не 0 то увеличиваем it на 2, т е перескакиваем текущую пару col-value
        }
        printf(" |\n");
    }
}

// выводим матрицу как храним - в виде одного вектора
void print_vector_view(matrix_t *mat){
    for (int i = 0; i < mat->_size; ++i) {
        compl_t c = mat->_data[i];
        if (c == 0.0+0.0*I) {
            printf("|  0  |  %d  |", (int)creal(mat->_data[i+1]));
        } else {
            printf("|  %d  |  %.3f%+.3fi  |",(int)creal(c),creal(mat->_data[i+1]),cimag(mat->_data[i+1]));
        }
        i++;
    }
    printf("\n");
}

int get_first(matrix_t *mat, float row) {
    for (int j = 0; j < mat->_size; ++j) {
        if (mat->_data[j]==0.0+0.0*I && mat->_data[j+1]==row+0.0*I) {
            return j+2;
        }
    }
    return mat->_size;
}

compl_t get_el(matrix_t *mat, int it, float col) {
    if (it < mat->_size && col == (int)creal(mat->_data[it])) {
        return mat->_data[it+1];
    } else {
        return 0;
    }
}

int row_el_count(matrix_t *mat, float row) {
    int count = 0;
    int it = get_first(mat, row);
    while (mat->_data[it] != 0.0+0.0*I) {
        ++count;
        it+=2; // если у нас вернулся не 0 то увеличиваем it на 2, т е перескакиваем текущую пару col-value
    }
    return count;
}

int max_count(matrix_t *mat){
    int max = 0, tmp_max = 0;
    for (int i = 0; i < mat->m; ++i) {
        tmp_max = row_el_count(mat, i+1);
        if (tmp_max > max) max = tmp_max;
    }
    return max;
}

/*
 * Найти строку, содержащую наибольшее количество ненулевых элементов, напечатать ее номер и сумму элементов этой строки. 
 * Если таких строк несколько, обработать все.
 */
void print_row_max_elem_count(matrix_t *mat){
    int max = max_count(mat);
    compl_t sum = 0;
    for (int i = 0; i < mat->m; ++i) {
        int it = get_first(mat, i+1);
        int count = row_el_count(mat, i+1);
        if (count == max) {
            while (mat->_data[it] != 0.0+0.0*I) {
                sum += mat->_data[it+1];
                it+=2; // если у нас вернулся не 0 то увеличиваем it на 2, т е перескакиваем текущую пару col-value
            }
            printf("\nROW %d containing the maximum number of elements ", i+1);
            printf("(MAX=%d), SUM of elements is equal to %.3f%+.3fi\n\n", max, creal(sum),cimag(sum));
        }
    }
}
