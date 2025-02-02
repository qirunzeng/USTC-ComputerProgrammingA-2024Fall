#include<stdio.h>
#include<string.h>
int seek(int,char[]);
int main(void)
{
    int t,n;
    char s[7]={'\0'};
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %s",&n,s);
        printf("%d\n",seek(n,s));
    }
}
int seek(int n,char s[])
{
    int k=0,m1,h=-1,p=0;
    char temp;
    float m2;
    char m3[11]={'\0'};
    int i[2048]={0};
    float f[2048]={0.0};
    char r[2048][11]={'\0'};
    char a[7]={'s','t','r','i','n','g','\0'};//字符串比较时需要以\0结尾
    char b[7]={'f','l','o','a','t','\0'};
    char c[7]={'i','n','t','\0'};
    if(!strcmp(s,a))
        k=1;
    if(!strcmp(s,b))
        k=2;
    if(!strcmp(s,c))
        k=3;
    switch(k)
    {
        case 3:
            for(int j=0;j<n;j++)
                scanf("%d",&i[j]);
            scanf("%d",&m1);
            for(int j=0;j<n;j++){
                if(i[j]==m1){
                    h=j;
                    break;
                }
            }
            break;
        case 2:
            for(int j=0;j<n;j++)
                scanf("%f",&f[j]);
            scanf("%f",&m2);
            for(int j=0;j<n;j++){
                if(f[j]==m2){
                    h=j;
                    break;
                }
            }
            break;
        case 1:
            getchar();
            for(int j=0;j<n;j++)
            {
                p=1;
                temp=getchar();
                if(temp==' '||temp=='\n'){
                    r[j][0]='\0';
                    }
                else
                {
                    r[j][0]=temp;
                    while(1)
                    {
                        temp=getchar();
                        if(temp!=' '&&temp!='\n')
                        {r[j][p]=temp;
                            p++;}
                        else
                        {//r[j][p]='\0';
                            break;}
                    }
                }
            }
            for(int j=0;j<10;j++)
            {
                temp=getchar();
                if(temp!='\n')
                    m3[j]=temp;
                else
                    break;
            }
            for(int j=0;j<n;j++){
                if(!strcmp(r[j],m3)){
                    h=j;
                    break;}
            }
            break;
    }
    return h;
}
