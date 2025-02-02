#include <stdio.h>
int main(void)
{
    int t,h=-1;
    int num[10]={1,3,5,7,9,11,13,15,17,19};
    scanf("%d",&t);
    int low=0;int high=9;int b;
    while(low<=high)
    {
        b=(low+high)/2;
        if(t>num[b])
            low=b+1;
        else if(t<num[b])
            high=b-1;
        else{
            h=b;
            break;}
    }
    if(h!=(-1))
    {
        for(int p=h;p<9;p++)
            num[p]=num[p+1];
        for(int p=0;p<9;p++)
            printf("%d ",num[p]);
        printf("\n");
    }
    else
        printf("error");
    return 0;
}
