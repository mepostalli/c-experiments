#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack * next;
    
};

typedef struct stack stack;

stack *p=NULL;

void push(int data){
//      Stack yapısına eleman ekleme işlemini gerçekleştiren fonksiyon
    if(p==NULL){
        p =(stack*) malloc(sizeof(stack));
        p -> next=NULL;
    }
    p->data = data;
    stack *new =(stack*) malloc(sizeof(stack));
    new -> next = p;
    p = new;
    printf("%d Stack'e eklendi\n",data);
}

int pop(){
//      Stack yapısından eleman silme işlemini gerçekleştiren fonksiyon    
    if(p->next==NULL){
        return -1;
    }
    int result = p->next->data;
    stack *tmp = p;
    p = p->next;
    printf("%d Stack'ten silindi\n",*p);
    free(tmp);
    return result;
}

void dispStack(){
//      Stack yapısının içeriğini görüntüleme işlemini gerçekleştiren fonksiyon.

    printf("\nStack:\n");
    stack *tmp = p -> next;
    while (tmp != NULL){
        printf("|%d|\n",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int main() {

    
    printf("STACK\n---------------------\n");

    push(50);
    push(60);
    push(70);
    
    dispStack();
    
    pop();
    pop();
    
    push(40);
    push(90);
    dispStack();

    return 0;

}
