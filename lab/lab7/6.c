#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    double *top;
    double *base;
    int listsize;
}List;
typedef struct
{
    char *top;
    char *base;
    int nodesize;
}Node;
int InitList(List *p)
{
    p->base=(double *)malloc(100*sizeof(double));
    if(!p->base)
        return 0;
    p->top=p->base;
    p->listsize=100;
    return 1;
}
int PushList(List *p,double e)
{
    if(p->top-p->base>=p->listsize)
    {
        p->base=realloc(p->base,(p->listsize+10)*sizeof(double));
        if(!p->base)
            return 0;
        p->top=p->base+p->listsize;
        p->listsize+=10;
    }
    *(p->top++)=e;
    return 1;
}
double PopList(List *p)
{
    double e;
    if(p->base==p->top)
        return 0;
    else
        e=*(--p->top);
    return e;
}
double getTopList(List *p)
{
    double e;
    if(p->base==p->top)
        return 0;
    e=*(p->top-1);
    return e;
}
void print(List *p)
{
    double *p1;
    if(p->base==p->top)
    {
        printf("数字空栈！！！！\n");
        exit(0);
    }
    p1=p->top;
    while(p1!=p->base)
    {
        printf("%.2lf\n",*(p1-1));
        p1--;
    }
}
void printNode(Node *p)
{
    char *p1;
    if(p->base==p->top)
    {
        printf("字符空栈！！！！\n");
        exit(0);
    }
    p1=p->top;
    while(p1!=p->base)
    {
        printf("%c\n\n",*(p1-1));
        p1--;
    }
}

int InitNode(Node *p)
{
    p->base=(char *)malloc(100*sizeof(char));
    if(!p->base)
        return 0;
    p->top=p->base;
    p->nodesize=100;
    return 1;
}
int PushNode(Node *p,char e)
{
    if(p->top-p->base>=p->nodesize)
    {
        p->base=realloc(p->base,(p->nodesize+10)*sizeof(char));
        if(!p->base)
            return 0;
        p->top=p->base+p->nodesize;
        p->nodesize+=10;
    }
    *(p->top++)=e;
    return 1;
}
char PopNode(Node *p)
{
    char e;
    if(p->base==p->top)
        return 0;
    else
        e=*(--p->top);
    return e;
}
char getTopNode(Node *p)
{
    char e;
    if(p->base==p->top)
        exit(0);
    e=*(p->top-1);
    return e;
}
int Length(char *s)
{
    int i=0,b=0;
    while(*(s+i)!='\0')
    {
        b++;
        i++;
    }
    return b;
}
int empty(Node *p)
{
    if(p->base==p->top)
    {
        return 1;
    }
    else
        return 0;
    return 1;
}
int compare(char ch)
{
    if(ch=='(')return 1;
    else if(ch=='#') return 0;
    else if(ch=='+'||ch=='-')return 2;
    else if(ch=='*'||ch=='/')return 3;
    else return 4;
}
double add(double num2,char op,double num1)
{
    double c=0;
    switch(op)
    {
        case '+':c=num2+num1;break;
        case '-':c=num2-num1;break;
        case '*':c=num2*num1;break;
        case '/':c=num2/(num1*1.0);break;
    }
    return c;
}
int isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='#')
        return 1;
    if(c=='('||c==')')
        return 2;
    return 0;
}
double calculate(void)
{
    double a,result=0,x,y,b;
    int i=0,j=0,k=0;
    char ch,s[100];
    Node p1;
    List p2;
    InitList(&p2);
    InitNode(&p1);
    scanf("%s",s);
    while(s[i]!='\0'&&i<Length(s))
    {
        k=0;
        b=0;
        a=0;
        j=i;
        if(s[j]>='0'&&s[j]<='9')
        {
    
            while(s[j]>='0'&&s[j]<='9')

            {
                a=(double)((s[j]-'0')+a*10);
                j++;
            }
            if(s[j]=='.')
            {
                j++;
                if(s[j]>='0'&&s[j]<='9')
                {
    
                    while(s[j]>='0'&&s[j]<='9')
                    {
                        b=(double)((s[j]-'0')+b*10);
                        k++;
                        j++;
                    }
                    for(i=0;i<k;i++)
                        b=b/(10.0);
                    a=a+b;
                }
            }
                
            i=--j;
            PushList(&p2,a);
        }
        
        else if(isop(s[i])==1)
        {
            if(empty(&p1))
                PushNode(&p1,s[i]);
            else
            {
                while(!empty(&p1))
                {
                    ch=getTopNode(&p1);
                    if(compare(ch)>=compare(s[i]))
                    {
                        x=PopList(&p2);
                        y=PopList(&p2);
                        result=add(y,ch,x);
                        PopNode(&p1);
                        PushList(&p2,result);
                    }
                    else break;
                }
                if(s[i]!='#')
                PushNode(&p1,s[i]);
            }
        }
        else if(isop(s[i])==2)
        {
            if(s[i]=='(')
                PushNode(&p1,s[i]);
            else
            {
                while(getTopNode(&p1)!='(')
                {
                    ch=getTopNode(&p1);
                    x=PopList(&p2);
                    y=PopList(&p2);
                    result=add(y,ch,x);
                    PopNode(&p1);
                    PushList(&p2,result);
                }
                PopNode(&p1);
            }
        }
        i++;
    }
    while(!empty(&p1))
    {
        ch=getTopNode(&p1);
        x=PopList(&p2);
        y=PopList(&p2);
        result=add(y,ch,x);
        PopNode(&p1);
        PushList(&p2,result);
    }
    return getTopList(&p2);
}

int main(void)
{
    printf("%.4lf\n",calculate());
    return 0;
}
