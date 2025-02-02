#include<stdio.h>
void two(long long num,long long s)
{
    if (s==1)
    {    
        printf("%lld",num);
        return;
    }
    else
    {
        printf("%lld",(num-num%s)/s);
        two(num%s,s/2);
    }
}
void eight(long long num,long long s)
{
    if (s==1)
    {    
        printf("%lld",num);
        return;
    }
    else
    {
        printf("%lld",(num-num%s)/s);
        eight(num%s,s/8);
    }
}
void sixteen(long long num,long long s)
{
    if (s==1)
    {
        if (num>=0 && num<10)
            printf("%lld",num);
        else if (num==10)
            printf("a");
        else if (num==11)
            printf("b");
        else if (num==12)
            printf("c");
        else if (num==13)
            printf("d");
        else if (num==14)
            printf("e");
        else if (num==15)
            printf("e");
        return;
    }
    else
    {
        int k=(num-num%s)/s;
        if (k>=0 && k<10)
            printf("%d",k);
        else if (k==10)
            printf("a");
        else if (k==11)
            printf("b");
        else if (k==12)
            printf("c");
        else if (k==13)
            printf("d");
        else if (k==14)
            printf("e");
        else if (k==15)
            printf("e");
        sixteen(num%s,s/16);
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        long long num,base;
        scanf("%lld%lld",&num,&base);
        if (num<0)
        {
            printf("-");
            num=-num;
        }
        if (base==2)
        {
            if (num==0)
                printf("0");
            else
            {
                long long a=1,b=2,i=1;
                for (i=1;i<32;i++)
                {
                    if (num>=a && num<b)
                        break;
                    a*=2;
                    b*=2;
                }
                two(num,a);
            }
            printf("\n");
        }
        if (base==8)
        {
           if (num==0)
                printf("0");
            else
            {
                long long a=1,b=8,i=1;
                for (i=1;i<20;i++)
                {
                    if (num>=a && num<b)
                        break;
                    a*=8;
                    b*=8;
                }
                eight(num,a);
            }
            printf("\n"); 
        }
        if (base==16)
        {
            if (num==0)
                printf("0");
            else
            {
                long long a=1,b=16,i=1;
                for (i=1;i<20;i++)
                {
                    if (num>=a && num<b)
                        break;
                    a*=16;
                    b*=16;
                }
                sixteen(num,a);
            }
            printf("\n");
        }
    }
    return 0;
}