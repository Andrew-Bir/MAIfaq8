#include "student.h"

#define DEFAULT_DATABASE_FILENAME "data/student.db";
#define DEFAULT_TEST_FILENAME "data/test1.dat";

int main(int argc, char *argv[]) {
    char *db_fname;
    FILE *out = NULL;
    FILE *pfile = NULL;
    char *in_fname;
    size_t row = 0;
    student_t student;

    if (argc == 3) {
        in_fname = argv[1];
        db_fname = argv[2];
    } else {
        db_fname = DEFAULT_DATABASE_FILENAME;
        in_fname = DEFAULT_TEST_FILENAME;
    }

    /* Open the file for reading */
    if(!(pfile = fopen(in_fname, "r"))) {
        printf("Error opening %s for reading. Program terminated.\n", in_fname);
        exit(1);
    } else printf("File %s open for reading...\n", in_fname);

    if(!(out = fopen(db_fname, "wb"))) {  // Create a new file we can write
        printf("Error opening %s for writing. Program terminated.\n", db_fname);
        exit (1);
    } else printf("File %s open for writing...\n", db_fname);

    printf("\nTable 1: Generated data.\n");
    printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n");
    printf("| ID  | SURNAME          | NAME             | PATRONYMIC       | GENDER     | GROUP      | GRADES           |\n");
    printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n");
    while (student_fscanf(pfile, &student) == 1) {
        student.id = ++row;
        fwrite(&student, sizeof(student), 1, out);
        fflush(out);
        student_print(&student);
    }
    printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n\n");
    fclose(out); // file close
    fclose(pfile); // Close the file

    return 0;
}
