/*
Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue().
*/

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




void push(Nodo** testa,Nodo* elemento){
    Nodo* head = elemento;
    Nodo* tail = head;
    
    while (isEmpty((*testa)->next) == 0){
        enqueue(&head,&tail,dequeue(testa,NULL));
    }
    enqueue(&head,&tail,dequeue(testa,testa));
    
    Nodo* temp = (*testa);
    while(isEmpty(head) == 0){
        enqueue(testa,&temp,dequeue(&head,&tail));

    }
}


Nodo* pop(Nodo** testa){
    return dequeue(testa,testa);
}

void main(){
    Nodo* pila = (Nodo*) malloc(sizeof(Nodo));
    pila->val = -1;
    
    Nodo* temp;
    for(int i = 0;i<10;i++){//inserisce 100 numeri di valore crescente nella coda
        temp = (Nodo*) malloc(sizeof(Nodo));
        temp->val = i;
        push(&pila,temp);
    }
    
    
    while (isEmpty(pila) == 0){
        printf("%d ",(pop(&pila))->val);
    }
    
    

}