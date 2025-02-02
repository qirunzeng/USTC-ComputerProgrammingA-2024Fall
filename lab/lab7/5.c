#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.141592657
struct point
{
    double x;
    double y;
};
void translation(struct point pt[],float tl_x,float tl_y,int num)
{
    for(int i=0;i<num;i++)
    {
        pt[i].x=pt[i].x+tl_x;
        pt[i].y=pt[i].y+tl_y;
    }
}
void scale(struct point pt[],float s_x,float s_y,int num)
{
    for(int i=0;i<num;i++)
    {
        pt[i].x=pt[i].x*s_x;
        pt[i].y=pt[i].y*s_y;
    }
}
void rotation(struct point pt[],float angle,int num)
{
    float a[2][2];
    struct point temp;
    angle=angle*PI/180;
    a[0][0]=cos(angle);
    a[0][1]=-sin(angle);
    a[1][0]=sin(angle);
    a[1][1]=cos(angle);
    for(int i=0;i<num;i++)
    {
        temp.x=pt[i].x;
        temp.y=pt[i].y;
        pt[i].x=temp.x*a[0][0]+temp.y*a[0][1];
        pt[i].y=temp.x*a[1][0]+temp.y*a[1][1];
    }
}
int main(void)
{
    int i=0,num=0;
    int mode;
    float angle,tl_x,tl_y,s_x,s_y;
    struct point pt[10000];
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%lf%lf",&pt[i].x,&pt[i].y);
    }
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:
            scanf("%f%f",&tl_x,&tl_y);
            translation(pt,tl_x,tl_y,num);
            break;
        case 2:
            scanf("%f%f",&s_x,&s_y);
            scale(pt,s_x,s_y,num);
            break;
        case 3:
            scanf("%f",&angle);
            rotation(pt,angle,num);
            break;
    }
    for(i=0;i<num;i++)
    {
        printf("%.4lf %.4lf\n",pt[i].x,pt[i].y);
    }
    return 0;
}
