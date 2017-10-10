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

void concatenate(list_t *, list_t *);
void partition(int, int, int *);
void swap(int, int, int *);


int menu();

int main(void)
{
    int list_choice = 0;
    list_t *list_one = list_create();
    list_t *list_two = list_create();
    int action;
    
    do {
        action = menu();
        switch (action) {
            case 1: 
				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						list_push_front(list_one);
					} else list_push_front(list_two);	
				}
                break;
            case 2:
 				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					int n;
					if ((scanf("%d", &n)) == 1) {
						if (list_choice == 1) {
							list_push_back(list_one, n);
						} else list_push_back(list_two, n);	
					}
				}	
                break;
            case 3:
				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						list_pop_front(list_one);
					} else list_pop_front(list_two);	
				};
                break;
            case 4:
				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						list_pop_back(list_one);
					} else list_pop_back(list_two);	
				};
                break;
            case 5:
 				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						list_insert(list_one);
					} else list_insert(list_two);	
				};
                break;
            case 6: 
 				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						list_erase(list_one);
					} else list_erase(list_two);	
				};
                break;
            break;
            case 7:
 				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						move_current(list_one);
					} else move_current(list_two);	
				};
                break;
            case 8:
 				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						get_first(list_one);
					} else get_first(list_two);	
				};
                break;
			case 9:
				printf("Select list, enter 1 or 2: ");
				if (scanf("%d", &list_choice) == 1) {
					if (list_choice == 1) {
						list_print(list_one);
					} else list_print(list_two);	
				};
                break;
			case 10:
				concatenate(list_one, list_two);
                break;
			case 11: break;
            default:
                printf("Invalide menu action!\n");
                break;
        }
    } while (action != 11);
    
    return 0;
}

// выводит меню
int menu() {
    int action;
    printf("Program menu:\n");
    printf("1) - List push front\t");
    printf("2) - List push back\t");
    printf("3) - List pop front\n");
    printf("4) - List pop back\t");
    printf("5) - List insert\t");
    printf("6) - List erase\n");
    printf("7) - Move current node to next\t");
    printf("8) - Get first node\t");
    printf("9) - Print\n");
    printf("10) - Concatenate\t");
    printf("11) - Exit\n");
    printf("\nSelect action: ");
    scanf("%d",&action);
    return action;
}

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

//обьединение двух списков
void concatenate(list_t *l1, list_t *l2) {
	list_print(l1);
	list_print(l2);
	get_first(l1);
	get_first(l2);
	int n = l1->size + l2->size;
	int *arr;  // указатель на массив
	// Выделение памяти
	arr = (int*)malloc(n * sizeof(int));
	int i = 0;
	do {
		arr[i] = l1->current->data;
		l1->current = l1->current->next;
		++i;
	} while (l1->current->next);
	arr[i] = l1->current->data;
	++i;
	do {
		arr[i] = l2->current->data;
		l2->current = l2->current->next;
		++i;
	} while (l2->current->next);
	arr[i] = l2->current->data;
	partition(0, n-1, arr);
	list_t *l3 = list_create();
	for (int j = 0; j < (l1->size+l2->size); ++j) {
		list_push_back(l3, arr[j]);
	}
	list_print(l3);
	list_erase(l3);
	free(l3);
	free(arr);
}

// функция сортировки Хоара
void partition(int from, int to, int *array) {
    int pivot = array[(from+to)/2]; //опорный элемент
    int i = from;
    int j = to;
    do {
         while (array[i] < pivot) i++;
         while (array[j] > pivot) j--;
         if (i <= j) {
             swap(i,j, array);
             i++;
             j--;
         }
     } while(i <= j);
     if (from < j) partition(from, j, array);
     if (i < to) partition(i, to, array);
}

//процедура обмена двух элементов
 void swap(int i, int j, int *x) {
     int tmp = x[i];
     x[i] = x[j];
     x[j] = tmp;
 }
