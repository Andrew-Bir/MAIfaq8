#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _node_ node_t;
struct _node_ {
    int value;
    node_t *next;
};
typedef node_t *list_t;

void udt_create();
bool udt_is_empty(const udt *);
void udt_push_front(udt *);
void  udt_push_back(udt *);
void udt_pop_front(udt *);
void  udt_pop_back(udt *);
void udt_print(const udt *);
size_t udt_size(const udt *);
void udt_insert(udt *, const data_type);
void udt_erase(udt *, const list_t);

#endif /* _LIST_H_ */
