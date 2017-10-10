#include "list.h"

list_t* list_create() {
    list_t *l = (list_t*)malloc(sizeof(list_t));
    list_init(l);
    return l;
}

list_t* list_init(list_t *l) {
    l->current = (node_t*)malloc(sizeof(node_t));
    l->current->data = 0;
    l->current->next = NULL;
    l->size = 0;
    l->head = l->current;
    return l;
}

/*Установка рабочего указателя в начало списка*/
void get_first(list_t *l) {
	l->current = l->head;
}

/*Установка рабочего указателя в конец списка*/
void get_last(list_t *l) {
	while (l->current->next) {
		l->current = l->current->next;
	}
}

/*Предикат: является ли список пустым*/
int is_empty(list_t *l) {
	if (!l->head->next) {
		return 1;
	}
	return 0;
}

/*Сдвиг текущего указателя*/
void move_current(list_t *l) {
	/*Если текущий указатель есть последний элемент*/
	if (!l->current->next) {
		printf("This is end of list\n");
	} else { 
		l->current = l->current->next;
	}
}

/*
 * Вставка элемента в список l -- дескриптор. 
 * cur -- текущий элемент после которого вставляем новый, 
 * value -- данные
 */
void list_insert(list_t *l) {
	int value;
	if ((scanf("%d", &value)) == 1) {
		node_t *tmp = malloc(sizeof(node_t));
		if(tmp != NULL) {
			tmp->data = value;
			tmp->next = l->current->next;	
			l->current->next->next = tmp;
        } else printf("%d  not inserted. No memory avaible\n", value);
	}
}

/*
 * Включение элемента в начало списка 
 * l -- дескриптор. 
 * n -- данные
 */
void list_push_front(list_t *l) {
	int n;
    if ((scanf("%d", &n)) == 1) {
		if (l->size == 0) {
			l->head->data = n;
			l->head->next = NULL;
		} else {
			node_t *tmp = malloc(sizeof(node_t));
			tmp->data = n;
			tmp->next = l->head;
			l->head = tmp;
		}
		l->current = l->head;
		l->size++;
	}
}
/*
 * Включение элемента в конец списка 
 * l -- дескриптор. 
 * n -- данные
 */
void list_push_back(list_t *l, int n) {
	if (l->size == 0) {
		l->head->data = n;
		l->head->next = NULL;
		l->current = l->head;
	} else {
		get_last(l);
		node_t *tmp = malloc(sizeof(node_t));
		tmp->data = n;
		tmp->next = NULL;
		l->current->next = tmp;
		l->current = tmp;
	}
	l->size++;
}

/*
 * Исключение первого элемента из списка
 * l -- дескриптор. 
 */
void list_pop_front(list_t *l) {
	/*Если список пуст*/
	if (is_empty(l)) {
		printf("list is empty\n");
	} else {
		if (!l->head->next) {
			l->head->data = 0;
			l->current = l->head;
		} else {
			// Временный элемент
			node_t *tmp = l->head;
			// Вывод информации из элемента списка
			//printf("%d\n", tmp->data);
			l->head = tmp->next;
			l->current = tmp->next;
			// Временный элемент ни на что не ссылается
			tmp->next = NULL;
			// Удаление временного элемента
			free(tmp);
		}
		l->size--;
	}
}

/*
 * Исключение последнего элемента из списка
 * l -- дескриптор. 
 */
void list_pop_back(list_t *l) {
	/*Если список пуст*/
	if (is_empty(l)) {
		printf("list is empty\n");
	} else {
		get_last(l);
		// Временный элемент
		node_t *tmp = l->current;
		get_first(l);
		while (l->current->next != tmp) {
			move_current(l);
		}
		// Вывод информации из элемента списка
		printf("%d\n", tmp->data);
		l->current->next = NULL;
		// Удаление временного элемента
		free(tmp);
		l->size--;
	}
}

void list_erase(list_t *l) {
	while (!is_empty(l)) {	// Пока список не пуст
		list_pop_front(l);	// Извлечь элемент
	}
}

void list_print(list_t *l) {
	if (l->size == 0) {
		printf("\nList is empty\n");
	} else {
		printf("\nThe list is: \n");
		node_t *tmp = l->head;
		while (tmp != NULL) {
			printf("%d -> ", tmp->data);
			tmp = tmp->next;
		}
		printf("NULL\n\n");
    }
}
