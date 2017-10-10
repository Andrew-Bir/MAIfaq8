#include "student.h"
//Программа загружает данные из бинарного файла

int main(int argc, char* argv[])
{
    char *fname;
    FILE *in = NULL;
    student_t m;
    int condition = 0;

    if (argc == 3) {
        fname = argv[1];
        if(!(in = fopen(fname, "r"))) {
            printf("Error opening %s for reading. Program terminated.\n", fname);
            exit(1);
        } else {
            printf("File %s open for reading...\n", fname);
            fseek(in, 0, SEEK_SET);
        }
    } else {
        printf("Invalid number of parameters\n");
        exit(1);
    }
    if (strcmp(argv[2],"-f") == 0) {
        printf("\nTable 2: Print data.\n");
        printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n");
        printf("| ID  | SURNAME          | NAME             | PATRONYMIC       | GENDER     | GROUP      | GRADES           |\n");
        printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n");
        while (fread(&m, sizeof(m), 1, in) == 1) {
            student_print(&m);
        }
        printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n\n");
    } else if (strcmp(argv[2],"-p1") == 0) {
        condition = 1;
    } else if (strcmp(argv[2],"-p2") == 0) {
        condition = 2;    
    } else {
        printf("The second parameter may be only -f, -p1 or -p2 \n");
        exit(1);
    }
    if (condition) {
        printf("\nTable 3: Scholarship recipients.\n");
        printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n");
        printf("| ID  | SURNAME          | NAME             | PATRONYMIC       | GENDER     | GROUP      | GRADES           |\n");
        printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n");
        while (fread(&m, sizeof(m), 1, in) == 1) {
            if (condition == 1) {
                if (m.credit[0]==0 && m.credit[1]<2 && m.credit[4]==3) {
                    student_print(&m);
                }
            } else {
                if (m.credit[0]==0 && m.credit[1]==0 && m.credit[2]<2 && m.credit[4]==3) {
                    student_print(&m);
                }
            }
        }
        printf("+-----+------------------+------------------+------------------+------------+------------+------------------+\n\n");
    }
    fclose(in); // Close the file
    return 0;
}
