#include <stdio.h>
#include <ctype.h>
int main()
{
	int n,i,j=0,ye=0,k;
	char ch,cha[17]={0};
	scanf("%d",&n);
    getchar();
	for (i=0;i<n;i++) {
		while((ch=getchar())!='\n')	{
			cha[j++]=ch;
		}
        cha[j]='\0';
        if (isalpha(cha[0])!=0||cha[0]==95) {
            for (k = 1; k < j; k++) {
                if (isalnum(cha[k]) == 0 && cha[k] != 95) {
                    printf("%d %c 2\n",k,cha[k]);
                    ye = 1;
                    break;
                }
            }
            if(ye == 0) {
                printf("True\n");
            }
        }
        else {
            printf("0 %c 1\n",cha[0]);
        }
        j=0;
        ye=0;
	}
	return 0;
}
