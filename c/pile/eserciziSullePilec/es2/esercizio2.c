#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse: (,),[,],{,} e
che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/
typedef struct carattere{
    char car;
    struct carattere* next;
}Carattere;

int isEmpty(Carattere *struttura){
    if(struttura == NULL) return 1;
    return 0;
}
void push(Carattere** testa,Carattere* elemento){
    if(isEmpty(*testa)){
        *testa = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *testa;
        *testa = elemento;
    }
}
Carattere* pop(Carattere** testa){
    Carattere* ret = *testa;
    if(isEmpty(*testa)) return NULL;
    *testa = ret->next;
    return ret;
}
void pushModificato(Carattere** testa,char carattere){
    if(isEmpty(*testa)){
        *testa = (Carattere*) malloc(sizeof(Carattere));
        (*testa)->car= carattere;
        (*testa)->next = NULL;
    }else{
        Carattere* temp = (Carattere*) malloc(sizeof(Carattere));
        temp->next = *testa;
        temp->car = carattere;
        *testa = temp;
    }
}
void rigiraPila(Carattere **pila){
    Carattere* pilaModificata;
    while ((*pila)!=NULL){
        push(&pilaModificata,pop(pila));   
    }
    *pila = pilaModificata;
    return;    
}
void stampaPila(Carattere* pila){
    while (isEmpty(pila) == 0){
        printf("%d ",pop(&pila)->car);
    }
    return;

}
void main(){
    char parola[100];
    int cnt=0;
    bool corretta=true;
    Carattere* caratteri;
    Carattere* aperte;
    printf("inserire equazione");
    scanf("%s",parola);
    while (parola[cnt] != '\0'){
        if(parola[cnt] == '(' || parola[cnt] == ')' || parola[cnt] == '[' || parola[cnt] == ']' || parola[cnt] == '{' || parola[cnt] == '}')
            pushModificato(&caratteri,parola[cnt]);
        cnt++;
    }
    rigiraPila(&caratteri);
    //stampaPila(caratteri);


    
    
    char temp;
    while (isEmpty(caratteri) == 0 && corretta){
        temp = pop(&caratteri)->car;
        if(temp == '(' || temp == '[' || temp == '{'){
            pushModificato(&aperte,temp);
        }else{
            if(aperte==NULL) corretta = false;
            else{
                switch(temp){
                    case ']':
                        if(pop(&aperte)->car != '[') corretta = false;
                        break;
                    case '}':
                        if(pop(&aperte)->car != '{') corretta = false;
                        break;
                    case ')':
                        if(pop(&aperte)->car != '(') corretta = false; 
                        break;
                }
            }
        }
    }
    if(corretta && aperte == NULL) printf("giusta");
    else printf("non è giusta");

}