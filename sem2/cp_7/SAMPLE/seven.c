#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int T;

typedef struct {
    T* data; // массив
    size_t size; // текущее количество элементов 
    size_t capacity; // под сколько элементов выделена память
} Vector;

