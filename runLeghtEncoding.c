#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encoding(){
    printf("inserire una stringa: ...");
    char stringa[100];
    fflush(stdin);
    scanf("%s",stringa);

    int cnt=0, consec=1;

    while(stringa[cnt]!='\0'){
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
    encoding();
    decoding();
    
}
