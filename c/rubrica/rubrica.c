#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct contatto{
    int numero;
    char* nome;
    char* cognome;
}Contatto;

void copiaRubrica(Contatto* rub1,Contatto* rub2,int cnt){
   /* for(int i=0;i<1000;i++){
            printf("%d",i);
    }*/
    
    for(int i=0;i<cnt;i++){
        (rub1+i)->numero = (rub2+i)->numero;
        strcpy((rub1+i)->nome,(rub2+i)->nome);
        strcpy((rub1+i)->cognome,(rub2+i)->cognome);
    }
    return;
}

void settaChar(Contatto* rubrica,int cnt){
    for(int i = 0;i<cnt+1;i++){
        (rubrica+i)->nome = (char*) malloc(sizeof(char)*20);
        (rubrica+i)->cognome = (char*) malloc(sizeof(char)*20);
    }

    return;
}

void aggiungi(Contatto* rubrica,int cnt){
    Contatto* temp = (Contatto*) malloc(sizeof(Contatto)*cnt);
    settaChar(temp,cnt);
    settaChar(rubrica,cnt);
    copiaRubrica(temp,rubrica,cnt);
    free(rubrica);
    rubrica = (Contatto*) malloc(sizeof(Contatto)*cnt+1);
    
    copiaRubrica(rubrica,temp,cnt);
    printf("\ninserire nome: ");
    scanf("%s",(rubrica+cnt)->nome);
    printf("inserire cognome: ");
    fflush(stdin);
    scanf("%s",(rubrica+cnt)->cognome);
    printf("inserire numero: ");
    fflush(stdin);
    scanf("%d",&((rubrica+cnt)->numero));
    
    free(temp);
    
}
void stampaRubrica(Contatto* rubrica,int cnt){
    for(int i=0;i<cnt;i++){
        printf("\nnome: %s,cognome: %s,numero %d",(rubrica+i)->nome,(rubrica+i)->cognome,(rubrica+i)->numero);
    }
    return;
}

void inputRubrica(Contatto* rubrica,int *cnt){
    char* stringa = (char*) malloc(sizeof(char)* 20);   
    do{        
        printf("\ncomandi:\n1-> aggiungi (write: 'add')\n2->stampa tutti i contatti salvati(write: 'print')\n3-> esci (write: 'esci')\n");
        free(stringa);
        stringa = (char*) malloc (sizeof(char)* 20);
        
        fflush(stdin);
        scanf("%s",stringa);
        
        if(strcmp(stringa,"add")==0){
            aggiungi(rubrica, *cnt);
            *cnt += 1;
            
            
        }else{
            if(strcmp(stringa,"print")==0){
                stampaRubrica(rubrica,*cnt);
            }
        }
        
    }while(strcmp(stringa,"esci") != 0);
    free(stringa);
    return;
}

void main(){    
    int cnt=0;
    Contatto* rubrica= (Contatto*) malloc(sizeof(Contatto)*1);
    
    
    inputRubrica(rubrica,&cnt);
    FILE *fp;/*
    fopen("rubrica.txt","w");
    //stampaRubrica;
    fclose(fp);*/
    free(rubrica);
    return;
}