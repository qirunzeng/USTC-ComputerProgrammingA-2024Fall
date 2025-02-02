#include <stdio.h>
int main()
{
    char ch,bef;
    long int flag=0,n=0;
    ch=getchar();
    while(flag==0)
    {
        bef=ch;   
        ch=getchar();
        if(!(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')||(ch=='\''))&&ch!='#'&&(('a'<=bef&&bef<='z')||('A'<=bef&&bef<='Z')))
            n++;
        if(ch=='#')
            flag=1;
    }
    printf("%ld",n);

    return 0;
}
