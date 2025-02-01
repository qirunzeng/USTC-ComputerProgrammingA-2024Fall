#include <stdio.h>
#include <math.h>

void decimalReverse(unsigned decimal){
    if(decimal/10==0){
        printf("%d",decimal);
    }
    else{
        printf("%d",decimal%10);
        decimalReverse(decimal/10);
    }
}

int main(){
    int zushu,i;
    scanf("%d",&zushu);
    int decimal[10000];
    for(i=0;i<zushu;i++)
        scanf("%d",&decimal[i]);
    for(i=0;i<zushu;i++){
        // printf("%c",decimal[i]>0?'\0':'-');
        if (decimal[i] < 0) {
            printf("-");
        }
        decimalReverse(decimal[i] > 0 ? decimal[i] : -decimal[i]);
        printf("\n");
    }
}