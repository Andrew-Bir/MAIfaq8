/*Задание
 * С оставить и отладить программу на язы*ке Си для обработки линейного списка заданной организации с 
 * отображением на динамические структуры. 
 * Навигацию по списку следует реализовать с применением итераторов. 
 * 
 * Тип элементов списка — 1) целый
 * Вид списка — 2) Линейный однонаправленный
 * Нестандартное действие — 6) удалить каждый k-ый элемент списка
 * 
 * Предусмотреть выполнение одного нестандартного и четырех стандартных действий: 
 * 1. печать списка; 
 * 2. вставка нового элемента в список; 
 * 3. удаление элемента списка; 
 * 4. подсчет длины списка. 
 * 5. удалить каждый k-ый элемент списка
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Elem elem_t;
struct Elem {
	int data;
    elem_t *next;
};

/*typedef struct {
    elem_t *head;
    int size;
} List;*/

typedef struct {
    elem_t *node;
} Iterator;
/*
// выделяет память под дескриптор списка, создат пустой список
List* CreateList() {
    ls[0]->next = NULL;
    ls[0]->data = 0;
    return ls;
}*/

// Создание итератора из ссылочной компоненты list->head списка
Iterator *first(elem_t *ls) {
	Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it->node = &ls[0];
    return it;
}

// Функция Last создает итератор из последнего элемента списка
Iterator* last(elem_t *ls){
	elem_t *p = &ls[0];
	while (p->next) {
		p = p->next;
	}
	Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it->node = p;
    return it;
}

// Список пуст???
bool is_empty(const elem_t * ls) {
    if(!ls[0].data && !ls[0].next) {
		return true;
		}
    return false;
}

int list_size(elem_t *ls) {
	int count = 0;
	if(is_empty(ls)){
		return 0;
	}
	Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it = first(ls);
    while (it->node != NULL) {
        it->node = it->node->next;
        count++;
    }

    return count;
	}
/*
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
*/
// Выводим список на экран
void print_list(elem_t *ls) {
    if (is_empty(ls)) {
        printf("\nError: List is empty!\n");
        return;
    }
    printf("\nThe list is: (%d)\n",list_size(ls));
    Iterator *it = (Iterator*)malloc(sizeof(Iterator));
    it = first(ls);
    while (it->node != NULL) {
        printf("%d -> ", it->node->data);
        it->node = it->node->next;
    }
    printf("NULL\n\n");
}
/*
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
}*/

// Функция Insert вставляет элемент в список перед заданным.
void insert(elem_t *ls, const int i, int t) {
	if (is_empty(ls)) {
		ls[0]->data = t;
		ls[0]->next = NULL;
	} else {
		elem_t *tmp = (elem_t*)malloc(sizeof(elem_t));
		tmp->data = t;
		if (i == 0) {
			tmp->next = &ls[0];
			ls[0] = tmp;
		} else {
			Iterator *it = find_item_by_index(ls, i-1);
			tmp->next = it->node->next;
			it->node->next = tmp;
		}
    }
    ls->size++;
    print_list(ls);
}

// функция Delete удаляет элемент, на который указывает итератор, возвращая
// в качестве результата итератор, ссылающийся на следующий за удаленным элемент

/*void delete(List *ls, const int i) {
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

void function(List *ls, int k) {
	Iterator *it = first(ls);
	int count = 0;
	while (it->node->next) {
		int i = 0;
		while (i < k-1) ++i;
		count +=i;
		if (count == ls->size) break;
		it = find_item_by_index(ls, count+1);
		delete(ls, count);
	}
	print_list(ls);
}
*/
int menu(){
    int action;
    printf("\nPlease, enter your choice:\n"
    "1 --- to print list.\n"
    "2 --- to insert into the list an element before some element (index)\n"
    "3 --- to delete an element from the list (index)\n"
    "4 --- length of list\n"
    "5 --- remove each k-th element, write some like 2\n"
    "6 --- exit.\n");
    printf("\nSelect action: ");
    scanf("%d",&action);
    return action;
}

int main(void){
   //List* ls = CreateList();
    elem_t *ls;  // указатель на массив
	// Выделение памяти
	ls = (elem_t*)malloc(32 * sizeof(elem_t));
    ls[0].data = 0;
    ls[0].next = NULL;
    int index;
    int value;
    int action;
    do {
        action = menu();
        switch (action) {
            case 1: 
                print_list(ls);
                break;
            case 2:
                printf("add: ");
                if (scanf("%d %d",&index, &value)==2){
                    //insert(ls,index,value);
                }else {
                    printf("Error!\n");
                }
                break;
            case 3:
                printf("Delete: ");
                if (scanf("%d",&index)==1) {
                    //delete(ls,index);
                } else {
                    printf("Error!\n");
                }
                //print_list(ls);
                break;
            case 4:
				printf("length of list = %d\n\n", list_size(ls));
                break;
            case 5:
                printf("function\n");
                printf("Enter number of k-th element: ");
                scanf("%d",&index);
                //function(ls,index);
                break;
            case 6: break;
            default:
                printf("Command is missing\n");
                printf("Enter the correct code: ");
                break;
        }
    } while (action != 6);
}






