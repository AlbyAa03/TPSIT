#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
typedef struct struttura{
    int val;
    struct struttura* next;
}Struttura;
/////////////////////
//////FUNZIONE3//////
void deallocaLista(Struttura* lista){
    if(lista->next != NULL) deallocaLista(lista->next);
    free(lista);
    return;
}
/////////////////////



Struttura* ordinaLista(Struttura* lista){
    //ORE COMPLESSIVE: 10 ... 2 venerdì sera, 2 sabato mattina, 5 sabato pomeriggio, 1 domenica mattina.
    printf("\n");
    Struttura *tempEsterno=lista,*tempInterno=lista,*posMax=lista,*temp=lista;//tutti i puntatoti a Struttura puntato alla prima della lista
    //prende la struttura con il val minore e la mette all'inizio
    while(tempInterno->next->next!=NULL){
        if(tempInterno->next->val<posMax->next->val){
            posMax=tempInterno;
        }
        tempInterno=tempInterno->next;
    }//FUNZIONANTE//

    if(lista->val>posMax->next->val){//se il minore non è al primo posto ( se lo è allora non devo cambiare niente)
        if(tempInterno != posMax->next){//se il minore non è l'ultimo
            lista=posMax->next;//la prima della lista punta ora a quella minore
            posMax->next=posMax->next->next;//la cella prima di quella che ho "spostato" punta a quella successiva, quindi si toglie il "buco" "logico".
            lista->next=temp; //il secondo della lista diventa quello che prima era all'inizio
        }else{
            lista=posMax->next;
            posMax->next=NULL;
            lista->next=temp;
        }
    }
    /*
    TENTATIVO 1:
    while(tempEsterno->next !=NULL){
        
        tempInterno=lista;//tempInterno punta al primo della lista
        temp=lista;//serve a scambiare poi ( rimane una struttura indietro rispetto a tempInterno)
        //quindi temp->next = tempInterno
        while(tempInterno->next->next!=NULL){ //fino a quando rimangono ancora 2 strutture
            if(tempInterno->val>tempInterno->next->val){//se il valore è maggiore di quello della prossima struttura
                */
                /*
                temp=                   prima struttura
                temp->next=tempInterno= seconda struttura
                temp->next->next=tempInterno->next           = terza struttura
                t2=temp->next->next->next=tempInterno->next->next
             //  t2=tempInterno->next->next;
                */
               /*
                temp->next=tempInterno->next;//la struttura successiva è la seconda
                tempInterno->next=temp->next->next;//la successiva della prima è la terza
                temp->next->next=tempInterno;
                
            }     
            tempInterno=tempInterno->next;
            temp=temp->next;
            printf("%d ",tempInterno->val);
        }
        printf("\n");
        tempEsterno=tempEsterno->next;
    }
    */







   //TENTATIVO 2:
   /*
    while(tempEsterno->next !=NULL){
        
        tempInterno=lista;//tempInterno punta al primo della lista
        while(tempInterno->next->next!=NULL){ //fino a quando rimangono ancora 2 strutture
            if(tempInterno->next->val>tempInterno->next->val){//se il valore è maggiore di quello della prossima struttura
               */
               /*temp=tempInterno->next;
               tempInterno->next=tempInterno->next->next;
               temp->next=tempInterno->next->next->next;
               tempInterno->next->next=temp;*/
             /* 
            }
            //printf("%d",tempInterno->next->val);
            tempInterno=tempInterno->next;
            
        }
        printf("\n");
        tempEsterno=tempEsterno->next;
    }

    */


    //TENTATIVO 3:
    /*
    

    tempEsterno=lista->next;
    //tempInternoPunta Allultimo della lista;
    bool cambiato=true;
    while(cambiato==true){
        posMax=tempInterno;//la posizione è quella allultimo posto
        cambiato=false;
        tempEsterno=lista;
        while(tempEsterno->next->next!=NULL){
            if(posMax->val<tempEsterno->next->next->val){
                posMax=tempEsterno;
            }
        }
        if(posMax!=tempInterno){
            cambiato=true;
            tempInterno->next=posMax->next;
            tempInterno=posMax->next;
            posMax->next=posMax->next->next;
        }
    }

    
    */

    return lista; 
}

int main(){
    srand(time(NULL));
    Struttura* primoStruttura, *temp;
    primoStruttura=(Struttura*)malloc(sizeof(Struttura));
    temp=primoStruttura;
    for(int i=0;i<5;i++){
        temp->val=(int)(rand()%100);
        temp->next=(Struttura*)malloc(sizeof(Struttura));
        printf("%d ",temp->val);
        temp=temp->next;
        temp->next=NULL;        
    } 


    primoStruttura= ordinaLista(primoStruttura);
    
    printf("\n\n");
    temp=primoStruttura;
    for(int i=0;i<5;i++){
        printf("%d",temp->val);
        temp=temp->next;
    }
    deallocaLista(primoStruttura);
    return 0;
}