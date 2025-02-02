#include <stdio.h>
#define N 500000
void get(int[]);
void print(int[],int[],int[],int,int);
int main(void)
{
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    int a[N]={0},b[N]={0},c[N]={0};
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int j=0;j<n;j++)
        scanf("%d",&b[j]);
    print(a,b,c,m,n);
    return 0;
}
void print(int a[],int b[],int c[],int m,int n)
{
    int k=0,p=0;
    for(int j=0;j<n;j++)
    {
        while(1)
        {
            if(b[j]>=a[k]&&k<m)
            {
                c[p]=a[k];
                p++;
                k++;}
            else
                break;
        }
        c[p]=b[j];
        p++;
    }
    if(k<m)
        for(int j=k;j<m;j++)
            c[j+n]=a[j];
    for(int i=0;i<m+n-1;i++)
        printf("%d ",c[i]);
    printf("%d",c[m+n-1]);
}
