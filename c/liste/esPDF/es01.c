#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

struct El* push(struct El* lista,struct El* l,int n){
    if (lista == NULL){ /* se lista non punta a niente */
            
                /* alloca una struct El in memoria, assegna l'indirizzo della struttura allocata a lista. Assegna poi a l'indirizzo puntato ada lista */

        lista = (struct El *)malloc(sizeof(struct El));

        l = lista;
    }else{ /* se la lista punta a qualcosa */
            
        /* next di l (l sarebbe l'offset) viene allocato (allocazione di una struct El), e l punterà a next di l.   */

        l->next = (struct El *)malloc(sizeof(struct El));
        l = l->next;
    }

    l->valore = n;  /* il valore di "valore" della struttura corrente (l), viene assegnato n (preso in input) */
    l->next = NULL; /* cancella il contenuto del puntatore alla prossima struttura (l->next) */
    return;
}

void stampaLista(struct El* l){
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* fa puntare all'offset la prossima struttura */
    }
    return;
}
int main(){
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; /* svuota il contenuto di lista, quidi non punta a niente (punta alla cella 0000...) */

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0){
            l=push(lista,l,n);
        }
    } while (n >= 0);

    l = lista; /* fa puntare all'offset la prima struttura */
    printf("numeri inseriti: ");
    stampaLista(l);
    printf("\n");
    return 0;
}