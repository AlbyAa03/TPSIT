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
    Carattere* pilaModificata = (Carattere*) malloc(sizeof(Carattere));
    while (*pila!=NULL){
        push(&pilaModificata,pop(pila));   
    }
    *pila = pilaModificata->next;
    return;    
}

void main(){
    char parola[100];
    int cnt;
    bool corretta;
    Carattere* caratteri;
    do{
        printf("inserire stringa");
        scanf("%s",parola);
        caratteri = (Carattere*) malloc(sizeof(Carattere));
        cnt=0;
        corretta = true;
        while(parola[cnt] != '\0' && corretta){
            pushModificato(&caratteri,parola[cnt]);
            if(!(parola[cnt] == '(' || parola[cnt] == ')' || parola[cnt] == '[' || parola[cnt] == ']' || parola[cnt] == '{' || parola[cnt] == '}')){
                corretta = false;
            }
            cnt++;
        }
    }while(corretta == false);
    
    Carattere* tempCarattere;
    while (caratteri->car == ')' || caratteri->car == ']'  || caratteri->car == '}' ){
        push(&tempCarattere,pop(&caratteri));
    }
    
    corretta = true;
    char temp;
    while (caratteri->next != NULL && corretta){
        if(tempCarattere == NULL) corretta = false;
        else{       
            switch (pop(&caratteri)->car){
                case '(':
                    if(pop(&tempCarattere)->car != ')') corretta = false;
                    break;
                case '[':
                    if(pop(&tempCarattere)->car != ']') corretta = false;
                    break;
                case '{':
                    if(pop(&tempCarattere)->car != '}') corretta = false;
                    break;    
            }  
            printf("\n%d, %p",corretta,caratteri); 
        }
    }
            printf("\n%d",corretta); 
    if(tempCarattere != NULL) corretta = false;
            printf("\n%d",corretta); 
    if(corretta) printf("giusto");
    else{printf("non è giusto");}
}