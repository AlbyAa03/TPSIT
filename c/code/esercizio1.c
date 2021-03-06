/*
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
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

void main(){
    Nodo* head = NULL;
    Nodo* tail = NULL;
    
    Nodo* temp;
    /*for(int i = 1;i<100;i++){//inserisce 100 numeri di valore crescente nella coda
        temp = (Nodo*) malloc(sizeof(Nodo));
        temp->val = i;
        enqueue(&head,&tail,temp);
    }*/

    printf("INSERIRE I VALORI IN CODA FINO A QUANDO NON SI INSERISCE 0\n");

    int num = 0;
    do{
        temp = (Nodo*) malloc(sizeof(Nodo));
        scanf("%d", &(temp->val));
        enqueue(&head,&tail,temp);
    }while(tail->val != 0);

    printf("VALORI NELLA CODA: ");
    while(isEmpty(head) == 0 ){
        printf("%d ",(dequeue(&head,&tail))->val);
    }

}