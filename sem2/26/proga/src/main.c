#include "list.h"

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
