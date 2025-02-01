#include <stdio.h>
void trans_16(int num,int base);
void trans(int num,int base);
int main()
{
    int num,n,base;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&num,&base);
        if(base==16)
            trans_16(num,base);
        else
            trans(num,base);
        putchar('\n');
    }
    return 0;
}

void trans_16(int num,int base)
{
    printf("------\n");
    int temp;
        if(0<num&&num<base)
            printf("%x",num);
        else 
        {
            temp=num%base;
            num=(num-temp)/base;
            trans(num,base);
            printf("%x",temp);
        }
}

void trans(int num,int base)
{
    printf("------\n");
    int temp;
        if(0<num&&num<base)
            printf("%d",num);
        else 
        {
            temp=num%base;
            num=(num-temp)/base;
            trans(num,base);
            printf("%x",temp);
        }
}