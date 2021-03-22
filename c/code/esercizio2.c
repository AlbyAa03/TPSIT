/*
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
*/
#include <stdbool.h
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

void pushModificato(Nodo** testa,int numero){
    if(isEmpty(*testa)){
        *testa = (Nodo*) malloc(sizeof(Nodo));
        (*testa)->val= numero;
        (*testa)->next = NULL;
    }else{
        Nodo* temp = (Nodo*) malloc(sizeof(Nodo));
        temp->next = *testa;
        temp->val = numero;
        *testa = temp;
    }
}

void giraCoda(Nodo** head,Nodo** tail){
    Nodo* pila = (Nodo*) malloc(sizeof(Nodo));
    Nodo* tempCoda = pila; 
    while (isEmpty(*head) == 0){
        pushModificato(&pila,dequeue(head,tail)->val);
    }
    
    
    *tail = tempCoda;    
    *head = pila;

}


void main(){
    Nodo* head = NULL;
    Nodo* tail = NULL;
    
    Nodo* temp;
    for(int i = 1;i<10;i++){//inserisce 100 numeri di valore crescente nella coda
        temp = (Nodo*) malloc(sizeof(Nodo));
        temp->val = i;
        enqueue(&head,&tail,temp);
    }

    giraCoda(&head,&tail); // i valori con la dequeue non vanno piu da 0 a 99 ma da 99 a 0

    printf("VALORI NELLA CODA: ");
    while(isEmpty(head) == 0 ){
        printf("%d ",(dequeue(&head,&tail))->val);
    }

}