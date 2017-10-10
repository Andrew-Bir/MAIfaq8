#include "list.h"

void push(list_t *head, int data) {
    list_t tmp = malloc(sizeof(node_t));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(list_t **head) {
    list_t* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

list_t getNth(list_t head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

list_t getLast(list_t head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}
 
void pushBack(list_t head, int value) {
    list_t last = getLast(head);
    list_t tmp = malloc(sizeof(node_t));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}
// возвращает указатель на предпоследний элемент
list_t getLastButOne(list_t head) {
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}
// Будем использовать два указателя. Один – текущий узел, второй – предыдущий. 
// Тогда можно обойтись без вызова функции getLastButOne
int popBack(Node **head) {
    Node *pFwd = NULL;  //текущий узел
    Node *pBwd = NULL;  //предыдущий узел
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
     
    pFwd = *head; 
    while (pFwd->next) { 
        pBwd = pFwd;
        pFwd = pFwd->next;
    }
 
    if (pBwd == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(pFwd->next);
        pBwd->next = NULL;
    }
}

void insert(Node *head, unsigned n, int val) {
    unsigned i = 0;
    Node *tmp = NULL;
    //Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
    //ошибка выбрасываться не будет, произойдёт вставка в конец
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = val;
    //Если это не последний элемент, то next перекидываем на следующий узел
    if (head->next) {
        tmp->next = head->next;
    //иначе на NULL
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;
 
        prev->next = elm->next;
        free(elm);
        return val;
    }
}

void deleteList(Node **head) {
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}




