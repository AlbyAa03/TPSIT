#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct canzone{
    int numero;
    char autore[100];
    char nome[100];
    int val;
}Canzone;

void leggiFile(Canzone playlist[],FILE *fp,int *cnt){
    char lettera;
    char parola[100];
    int indice=0;
    while(fscanf(fp,"%c",&lettera)!=EOF){
        if(lettera==','){
            parola[strlen(parola)]='\0';
            switch (indice)
            {
            case 0:
                playlist[*cnt].numero=(*cnt)+1;
                break;
            case 1:
                strcpy(playlist[*cnt].nome,parola);
            break;
            case 2:
                strcpy(playlist[*cnt].autore,parola);
            break;
            }
            indice=(indice+1)%3;
            memset(&parola[0],0,sizeof(parola));
            if(indice==0)
                *cnt = *cnt + 1;
        }else{
            parola[strlen(parola)]=lettera;
        }
    }
    return;
}

void canzoniRandom(Canzone playlist[],int cnt){
    srand(time(NULL));
    for(int i=0;i< cnt;i++)
        playlist[i].val=rand()%10000000;
    int max=0;
    for(int i=0;i<cnt;i++){
        max=i;
        for(int j=0;j<cnt;j++){
            if(playlist[max].val<playlist[j].val){
                max=j;
            }
        }
        printf("%d %s %s %d\n",playlist[max].numero,playlist[max].nome,playlist[max].autore,playlist[max].val);
        playlist[max].val=-100+i;
    }
    return;
}

void main(){
    Canzone playlist[100];
    FILE *fp;
    if((fp=fopen("spotify.csv","r"))==NULL){
        printf("il file non esiste");
    }else{
        int cnt=0;
        leggiFile(playlist,fp,&cnt);
        canzoniRandom(playlist,cnt);
    }
    
    /*for(int i=0;i<cnt;i++){
        printf("numero: %d %s %s\n",playlist[i].numero,playlist[i].nome,playlist[i].autore);
    }*/
    return;
}
