#include "list.h"

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
    List* ls = CreateList();
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
                    insert(ls,index,value);
                }else {
                    printf("Error!\n");
                }
                break;
            case 3:
                printf("Delete: ");
                if (scanf("%d",&index)==1) {
                    delete(ls,index);
                } else {
                    printf("Error!\n");
                }
                print_list(ls);
                break;
            case 4:
				printf("length of list = %d\n\n", ls->size);
                break;
            case 5:
                printf("function\n");
                printf("Enter number of k-th element: ");
                scanf("%d",&index);
                function(ls,index);
                break;
            case 6: break;
            default:
                printf("Command is missing\n");
                printf("Enter the correct code: ");
                break;
        }
    } while (action != 6);
    return 0;
}
