#include "list.h"

// выделяет память под дескриптор списка, создат пустой список
List* CreateList() {
    List *ls = (List*)malloc(sizeof(List));
    ls->head = (elem_t*)malloc(sizeof(elem_t));
    ls->head->next = NULL;
    ls->head->data = 0;
    ls->size = 0;
    return ls;
}

// Создание итератора из ссылочной компоненты list->head списка
Iterator *first(List *ls) {
	Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it->node = ls->head;
    return it;
}

// Функция Last создает итератор из последнего элемента списка
Iterator* last(List *ls){
	elem_t *p = ls->head;
	while (p->next) {
		p = p->next;
	}
	Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it->node = p;
    return it;
}

// Список пуст???
bool is_empty(const List * ls) {
    return ls->size == 0;
}

// Ищем в списке нужный индекс
Iterator* find_item_by_index(List *ls, const int index) {
    int counter = 0;
    Iterator *it = (Iterator*)malloc(sizeof(Iterator));

    if (index == 0) {
        it = first(ls);
        return it;
    }
    if (is_empty(ls)) return NULL;

    it = first(ls);
    while (it->node->next) {
        if (counter == index) return it;
        it->node = it->node->next;
        counter++;
    }
    return it;
}

// Выводим список на экран
void print_list(List *ls) {
    if (is_empty(ls)) {
        printf("\nError: List is empty!\n");
        return;
    }
    printf("\nThe list is: (%d)\n",ls->size);
    Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it = first(ls);
    while (it->node != NULL) {
        printf("%d -> ", it->node->data);
        it->node = it->node->next;
    }
    printf("NULL\n\n");
}

// Функция Destroy уничтожает список, перебирая его элементы и удаляя их
void destroy_list(List * ls) {
    elem_t *p = ls->head->next;

    while (p != ls->head) {
        elem_t *tmp = p;
        p = p->next;
        free(tmp);
    }
    free(ls->head);
    ls->head = NULL;
    ls->size = 0;
}

// Функция Insert вставляет элемент в список перед заданным.
void insert(List * ls, const int i, int t) {
	if (ls->size == 0) {
		ls->head->data = t;
		ls->head->next = NULL;
	} else {
		elem_t *tmp = (elem_t*)malloc(sizeof(elem_t));
		tmp->data = t;
		if (i == 0) {
			tmp->next = ls->head;
			ls->head = tmp;
		} else {
			Iterator *it = find_item_by_index(ls, i-1);
			tmp->next = it->node->next;
			it->node->next = tmp;
		}
    }
    ls->size++;
    print_list(ls);
}

// функция Delete удаляет элемент на который указывает индекс
void delete(List *ls, const int i) {
    Iterator *tmp = last(ls);
	Iterator *it = find_item_by_index(ls, i);
    if (!ls->size) return;
    tmp->node = it->node->next;
    if (i>0) {
		Iterator *prev = find_item_by_index(ls, i-1);
		prev->node->next = tmp->node;
		free(prev);
	} else ls->head = tmp->node;
    
    printf("deleted = %d\n",it->node->data);
    free(it->node);
    it->node = tmp->node;
    ls->size--;
}
