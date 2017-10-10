#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum gender_t{
    MALE,
    FEMALE
};

typedef struct __student__ {
    size_t id;
    char surname[32];
    char name[32];
    char patronymic[32];
    enum gender_t gender;
    char group[8];
    int grades[4];
    int tests[3];
    int credit[5];
} student_t;

student_t student_init(void);

int student_fscanf(FILE *, student_t *);
int student_print(student_t *);

#endif
