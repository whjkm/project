#include <stdio.h>
#include <math.h>
int main()
{
    int x1,y1,x2,y2,x3,y3;
     double a,b,c,q,s;
    while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0)
            break;
        a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        q=(a+b+c)/2;
        s=sqrt(q*(q-a)*(q-b)*(q-c));
        printf("%.1f\n",s);
    }
    return 0;
}


/*#include<stdio.h>
#include<math.h>

int main()
{
int x1,y1,x2,y2,x3,y3;
while(~scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3))
{
double a,b,c,s,p;
if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0)
break;
a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
p=(a+b+c)/2;
s=sqrt(p*(p-a)*(p-b)*(p-c));
printf("%.1f\n",s);
}
return 0;
}*/
