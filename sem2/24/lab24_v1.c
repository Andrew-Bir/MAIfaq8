#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_INPUT 1024
#define SIZE_STR 40

typedef struct node{
	char data[SIZE_STR];
	struct node *left;
	struct node *right;
} node;

node* add_node(char* dt, node* l, node* r);
int priority(char c);
node* make_tree(char* expr, int first, int last);
void print_tree(node* tree, int lrc);
node* zip_tree(node* tree);
int check_int(char* str);
void tree_to_expr(node* tree, int priority_node);
void int2str(int n, char* s);
void reverse_t(char* s);

int main(int argc, char* argv[]){
	char input[SIZE_INPUT];
	node* tree;

	printf("Input expression: "); 
	fgets(input, SIZE_INPUT-2, stdin);
	input[strlen(input)-1] = 0;
	printf("-----------------------\n");
	tree = make_tree(input, 0, strlen(input)-1);
	print_tree(tree, 0);
	printf("-----------------------\n");
	tree = zip_tree(tree);
	print_tree(tree, 0);
	printf("-----------------------\n");
	tree_to_expr(tree, 1);
	printf("\n\n");
	
	return 0;
} 

node* add_node(char *dt, node* l, node* r){
	node* add = (node*)malloc(sizeof(node));
	strcpy(add->data, dt);
	add->left = l;
	add->right = r;
	return add;
}

int priority(char c){
	switch(c){
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: return 3;
	}
}

node* make_tree(char* expr, int first, int last){
	int minprt = 3, nest = 0, i, k, prt;
	char temp[SIZE_STR];
	
	if(first == last){
		temp[0] = expr[first];
		temp[1] = 0;
		return add_node(temp, 0, 0);
	}
	for(i = first; i<=last; i++){
		if(expr[i] == '(') {nest++; continue;}
		if(expr[i] == ')') {nest--; continue;}
		if(nest>0) continue;
		prt = priority(expr[i]);
		if(prt <= minprt) {minprt = prt; k = i;}
	}
	if(minprt == 3){
		if((expr[first] == '(') && (expr[last] == ')'))
			return make_tree(expr, first+1, last-1);
		else {
			k = last-first+1;
			strncpy(temp, expr+first, k);
			temp[k] = 0;
			return add_node(temp, 0, 0);
		}
	}
	temp[0] = expr[k];
	temp[1] = 0;
	return add_node(temp, make_tree(expr, first, k-1), make_tree(expr, k+1, last));
}

void print_tree(node* tree, int lrc){
	static int level = 0;
	int i;

	level++;
	if (tree){
		print_tree(tree->right, 2);
		for (i = 0; i<level; i++) printf("  ");
		if(lrc == 1) printf("\\_%s\n", tree->data);
		else if (lrc == 2) printf("__%s\n", tree->data);
		else printf("_%s\n", tree->data);
		print_tree(tree->left, 1);
	}
	level--;
}

node* zip_tree(node* tree){
	char temp[SIZE_STR];
	if(tree){
		if(!check_int(tree->data)){
			tree->left = zip_tree(tree->left);
			tree->right = zip_tree(tree->right);
		}
		if(!strcmp(tree->data, "+")){
			if(check_int(tree->left->data) && check_int(tree->right->data)){
				int2str(atoi(tree->left->data)+atoi(tree->right->data), temp); //itoa нет на лаб.компах 
				strcpy(tree->data, temp);
				tree->left = 0;
				tree->right = 0;
			}
		}
	}
	return tree;
}

int check_int(char* str){
	int i;
	for(i = 0; i<strlen(str); i++) if(!(str[i]>='0' && str[i]<='9')) return 0;
	return 1;
}

void tree_to_expr(node* tree, int priority_node){
	if(priority_node == 2) printf("(");
	if(tree->left) {
		if(!tree->left->left && !tree->left->right) tree_to_expr(tree->left, 1);
		else tree_to_expr(tree->left, priority(tree->data[0]));
	}
	printf("%s", tree->data);
	if(tree->right) {
		if(!tree->right->left && !tree->right->right) tree_to_expr(tree->right, 1);
		else tree_to_expr(tree->right, priority(tree->data[0]));
	}
	if(priority_node == 2) printf(")");
}

void int2str(int n, char* s){
    int i, sign;
    if((sign = n) < 0) n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse_t(s);
}

void reverse_t(char* s){
    int i, j;
    char c;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
