#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct regione{
    char* data;
    char* stato;
    int codice_regione;
    char* denominazione_regione;
    float lat;
    float longit;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    bool temp;
}Regione;
/*data,stato,codice_regione,denominazione_regione,lat,long,ricoverati_con_sintomi,terapia_intensiva,totale_ospedalizzati,isolamento_domiciliare,totale_positivi,variazione_totale_positivi,
nuovi_positivi,dimessi_guariti,
deceduti,casi_da_sospetto_diagnostico,casi_da_screening,totale_casi,tamponi,casi_testati
*/
int contaRegioni(FILE* fp){
    int cnt=0;
    char* reg = (char*) malloc (200 * sizeof(char));
    while(fgets(reg,200,fp)){
        cnt++;
        free(reg);
        reg = (char*) malloc (200 * sizeof(char));
    }
    
    return cnt;
}

void settaRegioni(Regione* regioni,int cnt){
    for(int i=0;i<cnt;i++){
        (regioni+i)->data = (char*) malloc(sizeof(char)*19);
        (regioni+i)->stato = (char*) malloc(sizeof(char)*19);
        (regioni+i)->denominazione_regione = (char*) malloc(sizeof(char)*19);
    }
    return;
}

void prendiDati(Regione* regioni, FILE* fp){
    char* reg = (char*) malloc(sizeof(char)*200);
    int cnt=0;
    while(fgets(reg,200,fp)){
        strcpy((regioni+cnt)->data ,strtok(reg,","));
        strcpy((regioni+cnt)->stato ,strtok(NULL,","));
        (regioni+cnt)->codice_regione=atoi(strtok(NULL,","));
        strcpy((regioni+cnt)->denominazione_regione,strtok(NULL,","));
        (regioni+cnt)->lat=atof(strtok(NULL,","));
        (regioni+cnt)->longit=atof(strtok(NULL,","));
        (regioni+cnt)->ricoverati_con_sintomi=atoi(strtok(NULL,","));
        (regioni+cnt)->terapia_intensiva=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_ospedalizzati=atoi(strtok(NULL,","));
        (regioni+cnt)->isolamento_domiciliare=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_casi=atoi(strtok(NULL,","));
        (regioni+cnt)->variazione_totale_positivi=atoi(strtok(NULL,","));
        (regioni+cnt)->nuovi_positivi=atoi(strtok(NULL,","));
        (regioni+cnt)->dimessi_guariti=atoi(strtok(NULL,","));
        (regioni+cnt)->deceduti=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_da_sospetto_diagnostico=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_da_screening=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_casi=atoi(strtok(NULL,","));
        (regioni+cnt)->tamponi=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_testati=atoi(strtok(NULL,","));
        (regioni+cnt)->temp=true;
        cnt++;
    }
    return;
}

void topTreTerapiaIntensiva(Regione* regioni,int cnt){
    printf("Top 3 per numeri di terapia intensiva\n");
    int magg=0;
    int* temp = (int*)malloc(sizeof(int)*3);
    for(int i=0;i<3;i++){
        magg=0;
        while(!((regioni+magg)->temp)){//se era già nelle maggiori
            magg += 1;
        }
        for(int j=0;j<cnt;j++){
            if((regioni+magg)->terapia_intensiva < (regioni+j)->terapia_intensiva && (regioni+j)->temp){
                magg=j;
            }
        }
        (regioni+magg)->temp = false;
        printf("%d -> %s, %d\n",i+1,((regioni+magg)->denominazione_regione),(regioni+magg)->terapia_intensiva);
        *(temp+i) = magg;
    }
    for(int l=0;l<3;l++){//va a mettere i booleani cambiati su true;
        (regioni+(*(temp+l)))->temp = true;
    }
    free(temp);
}

void topTrePerMenoCasi(Regione* regioni,int cnt){
    printf("Top 3 per minor numero di casi:\n");
    int magg=0;
    int* temp = (int*)malloc(sizeof(int)*3);
    for(int i=0;i<3;i++){
        magg=0;
        while(!((regioni+magg)->temp)){//se era già nelle maggiori
            magg += 1;
        }
        for(int j=0;j<cnt;j++){
            if((regioni+magg)->totale_casi > (regioni+j)->totale_casi && (regioni+j)->temp){
                magg=j;
            }
        }
        (regioni+magg)->temp = false;
        printf("%d -> %s, %d\n",i+1,((regioni+magg)->denominazione_regione),(regioni+magg)->totale_casi);
        *(temp+i) = magg;
    }

    for(int l=0;l<3;l++){//va a mettere i booleani cambiati su true;
        (regioni+(*(temp+l)))->temp = true;
    }
    free(temp);
}

int totaleTerapiaIntensiva(Regione* regioni,int cnt){
    int tot=0;
    for(int i=0;i<cnt;i++){
        tot += (regioni+i)->terapia_intensiva;
    }
    return tot;
}

int main(){
    FILE* fp;
    
    if((fp=fopen("contagi.csv","r"))==NULL){
        printf("il file non esiste");
    }else{
        int cnt = contaRegioni(fp);
        Regione* regioni = (Regione*) malloc(sizeof(Regione)*cnt);
        settaRegioni(regioni,cnt);
        fclose(fp);
        fp=fopen("contagi.csv","r");
        prendiDati(regioni,fp);
        topTreTerapiaIntensiva(regioni,cnt);
        int totTerapiaIntensiva =totaleTerapiaIntensiva(regioni,cnt);
        printf("totale dei casi di terapia intensiva: %d\n",totTerapiaIntensiva);
        topTrePerMenoCasi(regioni,cnt);
        free(regioni);
    }
    return 0;
}