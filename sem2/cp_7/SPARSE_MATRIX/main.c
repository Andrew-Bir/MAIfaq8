#include "matrix.h"

int main(int argc, char *argv[]) {
    FILE *pfile = NULL;
    char *fname;
    int m = 0; // количество строк
    int n = 0; // количество столбцов
    matrix_t mat;

    if (argc == 2) {
        fname = argv[1];
    } else {
        printf("Invalid number of parameters\n");
        exit(1);
    }
    //Open the file for reading
    if(!(pfile = fopen(fname, "r"))) {
        printf("Error opening %s for reading. Program terminated.\n", fname);
        exit(1);
    } else printf("\nFile %s open for reading...\n", fname);

    // считываем количество строк и столбцов (размер матрицы) из файла
    if (fscanf(pfile, "%d %d", &m, &n)!=2) {
        printf("Error! Invalid input format! No number of rows specified. Program terminated.\n");
        exit(1);
    }
    printf("\nEntering matrix consists %d rows and %d columns...\n\n", m, n);
    create(&mat, m, n);
    initiation(pfile, &mat, m, n);
    fclose(pfile); // Close the file

    printf("One vector view:\n\n");
    print_vector_view(&mat);
    printf("\n\n");
    print_usual_view(&mat);

    print_row_max_elem_count(&mat);

    destroy(&mat);
    return 0;
}
