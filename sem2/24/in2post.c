#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50
#define BUFFER_SIZE 512

typedef struct stack
{
    int data[MAX];
    int top;
}stack;
 
int precedence(char c);
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int top(stack *);   //value of the top element
void infix_to_postfix(char infix[],char postfix[]);
 
int main(void) {
    char *infix = malloc(sizeof(infix) * BUFFER_SIZE);
    char *postfix = malloc(sizeof(postfix) * BUFFER_SIZE);
    printf("Enter an infix expression(eg: 5+2*4): ");
    fgets(infix, BUFFER_SIZE, stdin);
    infix_to_postfix(infix,postfix);
    printf("\nPostfix expression: %s\n\n", postfix);
    return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
    stack s;
    char x,token;
    int i, j = 0;    //i-index of infix,j-index of postfix
    init(&s);
    for(i=0;infix[i]!='\0';i++) {
        token=infix[i];
        if(isalnum(token)) {
            postfix[j++]=token;
        } else if(token=='(') {
            push(&s,'(');
        } else if(token==')') {
            while((x = pop(&s)) != '(') {
                postfix[j++] = x;
                //putchar(x); 
                x = '\0';
            }
        } else if ('+' == token || '-' == token || '*' == token || '/' == token || '^' == token) {
            while(precedence(token) <= precedence(top(&s)) && !empty(&s)) {
                x = pop(&s);
                postfix[j++] = x;
            }
            push(&s,token);
        } else {
            continue;
        }
    }
    while(!empty(&s)) {
        x=pop(&s);
        postfix[j++]=x;
    }
    postfix[j]='\0';
}
 
int precedence(char c) {
    switch(c) {
        case '(':
            return 0;
        case '+': case '-': 
            return 1;
        case '*': case '/': case '%':
            return 2;
        case '^': 
            return 3;
        default: 
            return 4;
    }
}
 
void init(stack *s)
{
    s->top=-1;
}
 
int empty(stack *s)
{
    if(s->top==-1)
        return(1);
 
    return(0);
}
 
int full(stack *s)
{
    if(s->top==MAX-1)
        return(1);
 
    return(0);
}
 
void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}
 
int pop(stack *s)
{
    int value;
    value = s->data[s->top];
    s->top = s->top-1;
    return(value);
}
 
int top(stack *p)
{
    return (p->data[p->top]);
}
