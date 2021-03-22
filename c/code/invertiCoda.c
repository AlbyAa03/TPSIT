#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int val;
    struct nodo* next;
}Nodo;


int isEmpty(Nodo *struttura){
    if(struttura == NULL) return 1;
    return 0;
}
void enqueue(Nodo** head,Nodo** tail,Nodo* element){
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

Nodo* dequeue(Nodo** head, Nodo** tail){
    Nodo* ret = *head;

    if(isEmpty(*head)) return NULL;
    else    *head = ret->next;

    if(*head == NULL) *tail = NULL;
    return ret;
}
/*
non funziona
void giraCoda(Nodo** head,Nodo** tail){
    Nodo* temp = (Nodo*) malloc(sizeof(Nodo));
    Nodo* tempCoda = temp;
    while (isEmpty(*head) == 0){
        enqueue(&temp,&tempCoda,dequeue(head,tail)); ;
        printf("%d\n",tempCoda->val);
        
    }
    *tail = tempCoda;    
    *head = temp;
}
*/

void main(){
    Nodo* testa = (Nodo*) malloc(sizeof(Nodo));
    Nodo* coda = testa;

    
    Nodo* temp;
    for(int i = 1;i<100;i++){
        temp = (Nodo*) malloc(sizeof(Nodo));
        temp->val = i;
        enqueue(&testa,&coda,temp);
    }

//    giraCoda(&testa,&coda); // non funziona

    while(isEmpty(coda) == 0 ){
        printf("%d\n",(dequeue(&testa,&coda))->val);
    }
/*
*/
}
