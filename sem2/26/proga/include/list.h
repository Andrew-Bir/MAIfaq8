#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Указатель на элемент списка*/
typedef struct __listNode__ node_t;

/*Структура элемента списка*/
struct __listNode__ {
    int data;		// данные
    node_t *next; 	// указатель на следующий элемент списка
};

/*Дескриптор списка*/
typedef struct {
    node_t *head;		//первый
    node_t *current;		// текущий
    size_t size;	// количество элементов не знаю зачем нужно, поглядим
} list_t;

list_t* list_create();
list_t* list_init(list_t *);
void list_push_front(list_t *);
void list_push_back(list_t *, int);
void list_pop_front(list_t *);
void list_pop_back(list_t *);
void list_insert(list_t *);
void list_erase(list_t *);
void list_print(list_t *);

void get_first(list_t *);
void get_last(list_t *);
int is_empty(list_t *);
void move_current(list_t *);

#endif
