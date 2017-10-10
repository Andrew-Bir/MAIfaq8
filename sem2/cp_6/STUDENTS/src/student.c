#include "student.h"

//  считываем информацию о студенте из файла f
int student_fscanf(FILE* f, student_t* member){

    if(!f){
        printf("f is null pointer\n");
        return 0;
    }

    if(feof(f)){
        return EOF;
    }

    if(!member) {
        printf("member is null\n");
        return -2;
    }
    if (fscanf(f, "%32s", (member->surname))!=1) {
        return -3;
    }

    if (fscanf(f, "%32s", (member->name))!=1) {
        return -4;
    }

    if (fscanf(f, "%32s", (member->patronymic))!=1){
        return -5;
    }

    int temp;
    if (fscanf(f, "%d", &temp)!=1){
        return -6;
    } else member->gender = temp;

    if (fscanf(f, "%8s", (member->group))!=1){
        return -7;
    }

    if(fscanf(f,"%1d%1d%1d%1d",(int *)&(member->grades[0]),(int *)&(member->grades[1]),(int *)&(member->grades[2]),(int *)&(member->grades[3]))!=4){
        return -8;
    }
    int test_cost = 0;
    for (int i=0; i<3; ++i) {
        char test[2];
        if (fscanf(f, "%2s", test)!=1) {
            return -9;
        } else {
            if (strcmp(test,"FL") == 0){
                member->tests[i] = 0;
            } else {
                member->tests[i] = 1;
                test_cost++;
            }
        }
    }
    int unsatisfactory=0, passing_grade=0, satisfactory=0, excellent=0;
    for(int i = 0 ; i < 4 ; ++i) {
        if (member->grades[i] == 2) unsatisfactory++;
        if (member->grades[i] == 3) passing_grade++;
        if (member->grades[i] == 4) satisfactory++;
        if (member->grades[i] == 5) excellent++;
    }
    member->credit[0]=unsatisfactory;
    member->credit[1]=passing_grade;
    member->credit[2]=satisfactory;
    member->credit[3]=excellent;
    member->credit[4]=test_cost;

    return 1;
}
// выводит строку таблицы в stdout
int student_print(student_t* member){
    fprintf(stdout, "| %3lu | ",member->id);
    fprintf(stdout, "%-*s | ",(int)((32 - strlen(member->surname)) / 2 + strlen(member->surname)),member->surname);
    fprintf(stdout, "%-*s | ",(int)((32 - strlen(member->name)) / 2 + strlen(member->name)),member->name);
    fprintf(stdout, "%-*s | ",(int)((32 - strlen(member->patronymic)) / 2 + strlen(member->patronymic)),member->patronymic);
    char *temp = (member->gender ? "Female" : "Male  ");
    fprintf(stdout, "%-*s | ",(int)((14 - strlen(temp)) / 2 + strlen(temp)),temp);
    fprintf(stdout, "%-*s | ",(int)((14 - strlen(member->group)) / 2 + strlen(member->group)),member->group);
    for(int i = 0 ; i < 4 ; i++) {
        fprintf(stdout, "%-1d ", member->grades[i]);
    }
    for(int i = 0 ; i < 3 ; i++) {
        printf(member->tests[i] ? "PS " : "FL ");
    }
    /*for(int i = 0 ; i < 4 ; i++) {
        fprintf(stdout, "%-1d ", member->credit[i]);
    }*/
    fprintf(stdout, "|\n");
    return 1;
}
