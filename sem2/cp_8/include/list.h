#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Elem elem_t;
struct Elem {
	int data;
    elem_t *next;
};

typedef struct {
    elem_t *head;
    int size;
} List;

typedef struct {
    elem_t *node;
} Iterator;

List* CreateList();
Iterator* first(List *);
Iterator* last(List *);
bool is_empty(const List *);
Iterator* find_item_by_index(List *, const int);
void print_list(List *);
void destroy_list(List *);
void insert(List *, const int, int);
void delete(List *, const int);

#endif
