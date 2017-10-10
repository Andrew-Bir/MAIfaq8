#include<stdio.h>
#include<stdlib.h>

struct node;
typedef struct node Node;
typedef Node *Tree;
typedef float data_type;

Tree tree_create();
Tree node_maker(Tree son, Tree brother, data_type x);
void subtree_output(Tree p, int depth, Tree cur);
void tree_add(Tree * tree, data_type x);
void tree_output(Tree tree, Tree p);
void tree_delete(Tree * tree);
int is_list(Tree p);

struct node {
    data_type data;
    struct node *son;
    struct node *brother;
};

int main() {
    Tree tree = tree_create();
    Tree *cur = NULL;
    int choice;
    enum { ROOT, ELSE } check;

    do {
        data_type data;

        printf("0 exit\t\t\t" "4 add node\n"
               "1 root/create\t\t" "5 delete\n"
               "2 brother\t\t" "6 tree output\n" 
               "3 son\t\t\t" "7 is line\n");
        if (scanf("%i", &choice) != 1)
            getchar();

        switch (choice) {
            case 0:
                break;
            case 1:
                cur = &tree;
                check = ROOT;
                break;
            case 2:
                if (!cur)
                    printf("\nERR 404!\n\n");
                else {
                    if (*cur && check != ROOT)
                        cur = &((*cur)->brother);
                    else
                        printf("\nERR 404!\n\n");
                }
                break;
            case 3:
                if (!cur)
                    printf("\nERR 404!\n\n");
                else {
                    if (*cur) {
                        cur = &((*cur)->son);
                        check = ELSE;
                    }
                    else
                        printf("\nERR 404!\n\n");
                }
                break;
            case 4:
                if (!cur)
                    printf("\nERR 404!\n\n");
                else {
                    printf("NEW_NODE->DATA = ");
                    scanf("%f", &data);
                    tree_add(cur, data);
                    tree_output(tree, (*cur));
                }
                break;
            case 5:
                if (!cur) {
                    printf("\nERR 404!\n\n");
                } else {
                    if (*cur) {
                        tree_delete(cur);
                        cur = &tree;
                        check = ROOT;
                        tree_output(tree, (*cur));
                    } else {
                        printf("\nERR 404!\n\n");
                    }
                }
                break;
            case 6:
                tree_output(tree, (*cur));
                break;
            case 7:
                printf(is_list(tree) ? "\nYES\n\n" : "\nNO\n\n");
                break;
            default:
                printf("\nCOMMAND ERR\n\n");
                break;
        }
    } while (choice != 0);
    tree_delete(&tree);
    return 1;
}

Tree tree_create() {
    return NULL;
}

void tree_add(Tree * tree, data_type x) {
    if (*tree == NULL) {
        *tree = node_maker(NULL, NULL, x);
    } else {
        printf("\nERROR\n\n");
    }
}

Tree node_maker(Tree son, Tree brother, data_type x) {
    Tree p;

    p = (Tree) malloc(sizeof(Node));
    p->data = x;
    p->son = son;
    p->brother = brother;
    return p;
}

void tree_output(Tree tree, Tree p) {
    printf("============== TREE VIEW ===============\n\n");
    if (tree) {
        subtree_output(tree, 0, p);
    } else {
        printf("NOTHING\n");
    }
    printf("\n=============== END TREE ===============\n");
}

void subtree_output(Tree p, int depth, Tree cur) {
    int i;
    Tree son = p->son;
    for (i = 0; i != depth; ++i) {
        printf(" ");
    }
    printf("%f%s\n", p->data, (cur==p ? "_  " : ""));
    while (son) {
        subtree_output(son, 1 + depth, cur);
        son = son->brother;
    }
}

void tree_delete(Tree * tree) {
    if (*tree) {
        Tree *it = &(*tree)->son;
        while (*it) {
            Tree *tmp = &(*tree)->brother;
            tree_delete(it);
            it = tmp;
        }
        free(*tree);
        *tree = NULL;
    }
}

int is_list(Tree p) {
    int flag = 1;
        Tree it = p->son;
        while (it) {
            if (it->brother != NULL) {
                flag = 0;
                break;
            } else {
                it = it->son;
            }
        }
    return flag;
}

