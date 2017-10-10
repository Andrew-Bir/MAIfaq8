#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
#define BUFFER_SIZE 1024

typedef struct _node_ node_t;
struct _node_ {
    char data;
    node_t *left;
    node_t *right;
};
typedef node_t* tree_t;
tree_t tree_build(char *buffer);
void preorder(tree_t tree);
void postorder(tree_t tree);
void inorder(tree_t tree);
void inorder_depth(tree_t tree, int flag);
void tree_print(tree_t tree);
void node_print(tree_t tree, int tab);
tree_t swap_t(tree_t tree);
tree_t redo_t(tree_t left_t, tree_t right_t);
tree_t simpl_t(tree_t one, tree_t two);
tree_t remake_t(tree_t one, tree_t two);

typedef struct stack_ {
    int data[MAX];
    int top;
}stack_;
int precedence(char c);
void init(stack_ *s);
int empty(stack_ *s);
int pop(stack_ *s);
void push(stack_ *s, int x);
int top(stack_ *s);   //value of the top element

typedef struct _stack_ stack_t;
struct _stack_ {
    int top;        /* Индекс верхнего элемента стека. */
    tree_t *data;   /* Содержимое стека. */
};
stack_t *stack_new();
void stack_push(stack_t * stack, tree_t tree);
tree_t stack_pop(stack_t * stack);
tree_t stack_base(stack_t * self);


int main(void) {
    char *buffer = malloc(sizeof(buffer) * BUFFER_SIZE);
    printf("Enter an Infix expression(eg: 5+2*4): ");
    fgets(buffer, BUFFER_SIZE, stdin);

    /* Стоим по этому выражению дерево */
    tree_t tree = tree_build(buffer);
    printf("\n");
    printf("******************** TREE ********************\n");
    printf("\n");
    /* Печатаем дерево */
    tree_print(tree);

    /* Показываем как выгляжит выражение в префиксной форме. */
    printf("\nPre-Order Traversal :  \n");
    preorder(tree);
    printf("\n");


    /* Показываем как выгляжит выражение в инфиксной форме. */
    printf("\nIn-Order Traversal :  \n");
    inorder(tree);
    printf("\n");

    /* Показываем как выгляжит выражение в постфиксной форме, для отладки. */
    printf("\nPost-Order Traversal :  \n");
    postorder(tree);
    printf("\n\n");
    printf("****************** NEW TREE ******************\n");
    printf("\n");
    tree_t r_tree = swap_t(tree);
    tree_print(r_tree);
    printf("\n");
    printf("\nIn-Order Traversal :  \n");
    inorder(r_tree);
    printf("\n\n");
    return 0;
}

tree_t tree_build(char *buffer) {
    tree_t new_tree;
    tree_t t_left;
    tree_t t_right;

    char value, token;
    stack_ op_stack;
    init(&op_stack);
    stack_t *stack = stack_new();
    token = buffer[0];
    for (int i = 0; token != '\0'; ++i) {
        token = buffer[i];
        if (isalnum(token)) {
            new_tree = malloc(sizeof(node_t));
            new_tree->data = token;
            new_tree->left = NULL;
            new_tree->right = NULL;
            stack_push(stack, new_tree);
        } else if(token=='(') {
            push(&op_stack, token);
        } else if(token == ')') {
            while((value = pop(&op_stack)) != '(') {
                t_right = stack_pop(stack);
                t_left = stack_pop(stack);
                new_tree = malloc(sizeof(node_t));
                new_tree->data = value;
                new_tree->left = t_left;
                new_tree->right = t_right;
                stack_push(stack, new_tree);
                value = '\0';
            }
        } else if ('+' == token || '-' == token || '*' == token || '/' == token || '^' == token) {
            while(precedence(token) <= precedence(top(&op_stack)) && !empty(&op_stack)) {
                value = pop(&op_stack);
                t_right = stack_pop(stack);
                t_left = stack_pop(stack);
                new_tree = malloc(sizeof(node_t));
                new_tree->data = value;
                new_tree->left = t_left;
                new_tree->right = t_right;
                stack_push(stack, new_tree);
            }
            push(&op_stack, token);
        } else {
            continue;
        }
    }
    while(!empty(&op_stack)) {
        value = pop(&op_stack);
        t_right = stack_pop(stack);
        t_left = stack_pop(stack);
        new_tree = malloc(sizeof(node_t));
        new_tree->data = value;
        new_tree->left = t_left;
        new_tree->right = t_right;
        stack_push(stack, new_tree);
    }
    return stack_base(stack);
}

// ==================== ЭТО ПОКА ТОЛЬКО НАМЕТКИ ДЛЯ ФУНКЦИИ ИЗ ВАР 17 ==============================
tree_t swap_t(tree_t tree) {
    if (tree->left && tree->right) {
        if (tree->data == '*') {
            tree = redo_t(tree->left, tree->right);
        } else {
            tree->left = swap_t(tree->left);
            tree->right = swap_t(tree->right);
        }
    }
    return tree;
}

tree_t redo_t(tree_t left_t, tree_t right_t) {
    tree_t new_tree;
    tree_t tr;
    if (left_t->data == '^' && right_t->data == '^') {
        if (left_t->left->data == right_t->left->data) {
            new_tree = simpl_t(left_t, right_t);
        } else {
            new_tree = remake_t(left_t, right_t);
        }
    } else if (left_t->data == '*' && right_t->data == '^') {
        if (left_t->left->data == '^' && left_t->right->data == '^') {
            if (left_t->left->left->data == left_t->right->left->data) {
                left_t = simpl_t(left_t->left, left_t->right);
                new_tree = redo_t(left_t, right_t);
            } else if (left_t->left->left->data == right_t->left->data) {
                tr = left_t->right;
                left_t = remake_t(left_t->left, right_t);
                right_t = tr;
                new_tree = redo_t(left_t, right_t);
            } else if (left_t->right->left->data == right_t->left->data) {
                tr = left_t->left;
                left_t = remake_t(left_t->right, right_t);
                right_t = tr;
                new_tree = redo_t(left_t, right_t);
            } else {
                new_tree = remake_t(left_t, right_t);
            }
        } else {
            left_t->left = swap_t(left_t->left);
            left_t->right = swap_t(left_t->right);
            new_tree = redo_t(left_t, right_t);
        }
    } else {
        left_t = swap_t(left_t);
        right_t = swap_t(left_t);
        new_tree = remake_t(left_t, right_t);
    }
    return new_tree;
}

tree_t simpl_t(tree_t one, tree_t two) {
    tree_t new_tree;
    tree_t right_t;

    new_tree = malloc(sizeof(node_t));
    new_tree->data = '+';
    new_tree->left = one->right;
    new_tree->right = two->right;
    right_t = new_tree;

    new_tree = malloc(sizeof(node_t));
    new_tree->data = '^';
    new_tree->left = one->left;
    new_tree->right = right_t;
    return new_tree;
}

tree_t remake_t(tree_t one, tree_t two) {
    tree_t new_tree = malloc(sizeof(node_t));
    new_tree->data = '*';
    new_tree->left = one;
    new_tree->right = two;
    return new_tree;
}
// =================================================================================================

int precedence(char c) {
    switch(c) {
        case '(':
            return 0;
        case '+': 
        case '-':
            return 1;
        case '*': 
        case '/': 
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 4;
    }
}

// Выводит выражение в префиксной записи
void preorder(tree_t tree) {
    if (tree) {
        printf(" %c ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

//  Выводит выражение в постфиксной записи
void postorder(tree_t tree) {
    if (tree) {
        postorder(tree->left);
        postorder(tree->right);
        printf(" %c ", tree->data);
    }
}

/**
 *  @fn Выводит выражение в инфиксной записи.
 *      Вспомогательная функция для inorder.
 *      Нужна для правильной обработки скобок.
 */
void inorder_depth(tree_t tree, int flag) {
    if (tree) {
        if (tree->left && tree->right && flag){
            printf("(");
        }
        inorder_depth(tree->left, 1);
        printf(" %c ", tree->data);
        inorder_depth(tree->right, 1);
        if (tree->left && tree->right && flag){
            printf(")");
        }
    }
}

//  Выводит выражение в инфиксной записи.
void inorder(tree_t tree) {
    inorder_depth(tree, 0);
}

/**
 *  @fn Печатает поддерево. Рекурсивная процедура печати узлов.
 *      Сначала печатает левое поддерево.
 *      Потом печатает текущий узел с соответствующим отступом.
 *      Потом печатает правое поддерево.
 */
void node_print(tree_t tree, int tab) {
    if (tree->right) {
        node_print(tree->right, tab + 1);
    }
    printf("%*s [%c]\n", tab * 4, " ", tree->data);
    if (tree->left) {
        node_print(tree->left, tab + 1);
    }
}

//  Печатает дерево.
void tree_print(tree_t tree) {
    if (tree) {
        node_print(tree, 0);
    }
}


// СТЕК

//  Создает новый стек и возвращает указатель на него.
stack_t *stack_new() {
    stack_t *self = malloc(sizeof(stack_t));

    self->top = -1;
    self->data = malloc(sizeof(tree_t));
    return self;
}

// Возвращает дно стека (самый нижний элемент)
tree_t stack_base(stack_t * self) {
    return self->data[0];
}


//  Кладет поддерево в стек.
void stack_push(stack_t * self, tree_t tree) {
    self->top = self->top + 1;
    self->data = realloc(self->data, sizeof(tree_t));
    self->data[self->top] = tree;
}

// Возвращает содержимое верхушки стека.
tree_t stack_pop(stack_t * self) {
    self->top = self->top - 1;
    if (self->top > -2) {
        tree_t tree = self->data[self->top + 1];
        return tree;
    }
    return NULL;
}
// ДРУГОЙ СТЕК
void init(stack_ *s){
    s->top=-1;
}

int empty(stack_ *s) {
    if(s->top==-1) {
        return(1);
    }
    return(0);
}

void push(stack_ *s, int x) {
    s->top=s->top+1;
    s->data[s->top]=x;
}

int pop(stack_ *s){
    int value;
    value = s->data[s->top];
    s->top = s->top-1;
    return(value);
}

int top(stack_ *p){
    return (p->data[p->top]);
}


