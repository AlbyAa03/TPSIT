#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encoding(){
    printf("inserire una stringa: ...");//input string
    char stringa[100];//declaration of string variable
    fflush(stdin);//clean keyboard' buffer 
    scanf("%s",stringa);//input string

    int cnt=0, consec=1;//declaration of two variables

    while(stringa[cnt]!='\0'){//condizione while. Cicla se non ha finito di passare lettera per lettera la stringa
        if(stringa[cnt]== stringa[cnt+1]){
            consec++;
        }
        else{
            printf("%d%c",consec,stringa[cnt]);
            consec=1;
        }
        cnt++;
    }

}

void decoding(){

    printf("inserire una stringa: ...");
    char stringa[100];
    fflush(stdin);
    scanf("%s",stringa);


    for(int i=0;i<strlen(stringa);i++){
        if(stringa[i]>'0' && stringa[i]<='9'){
            for(int j=0;j<stringa[i]-48;j++)
                printf("%c",stringa[i+1]);
        }

    }

}

void main(){
        printf"scelte:\n0: esci dal programma\n1: codifica di una stringa\n2: decodifica di una stringa");
        int scelta;
    do{
        printf("\n\ninserire scelta: ...");
        scanf("%d",&scelta);
        switch(scelta){
            case 1:
                encoding();
            break;
            case 2:
                decoding();
            break;
            default:
            break;
        }

    }while(scelta!=0);
    printf("\n\nsei uscito");
    
}
