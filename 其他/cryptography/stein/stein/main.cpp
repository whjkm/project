/*#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int stein(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    if(a%2==0 && b%2==0) return 2*stein(a>>1,b>>1);
    else if(a%2==0)   return stein(a>>1,b);
    else if(b%2==0)   return stein(a,b>>1);
    else return stein(abs(a-b),min(a,b));
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",stein(a,b));
}
*/


/*#include <iostream>
#include <cstdio>
int ext_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=ext_gcd(b,a%b,x,y);
    int t=y;
    y=x-(a/b)*y;
    x=t;
    return r;
}
bool modular_linear_equation(int a,int b,int n)
{
    int x,y,x0,i;
    int d=exgcd(a,n,x,y);
    if(b%d)
        return false;
    x0=x*(b/d)%n;   //ль╫Б
    for(i=1;i<d;i++)
        printf("%d\n",(x0+i*(n/d))%n);
    return true;
}
int main()
{
    int a,b,x,y;
    scanf("%d%d",&a,&b);
    ext_gcd(a,b,x,y);
    printf("%d %d\n",x,y);
    return 0;
}
*/



/*#include <cstdio>
#include <cstring>
using namespace std;
int x,y,d,a,b;//a*x + b*y=GCD(a,b)

void exgcd(int a, int b, int &d, int &x, int &y)
{
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b, a%b, d, y, x); y-=x*(a/b);}
}
int main()
{
    scanf("%d%d",&a,&b);
    exgcd(a,b,d,x,y);
    printf("x=%d y=%d d=%d\n",x,y,d);
    return 0;
}
*/
#include<stdio.h>              //求模逆运算的stein算法
int qiumoni(int v,int u)
{
    int x1,x3,y1,y3;
    x1=1;
    x3=v;
    y1=0;
    y3=u;
    while(x3!=1&&y3!=1)
    {
        if(x3%2==0)
        {
            if(x1%2==0)
            {
                x1>>=1;             // x1=x1/2;
                x3>>=1;             // x3=x3/2;
            }
            else
                x1+=u;
        }
        else if(y3%2==0)
        {
            if(y1%2==0)
            {
                y1>>=1;         //y1=y1/2;
                y3>>=1;         //y3=y3/2;
            }
            else
                y1=y1+u;
        }
        else if(x3>y3)
        {
            x1-=y1;
            x3-=y3;
        }
        else
        {
            y1=y1-x1;
            y3=y3-x3;
        }
    }
    if(x3==1)
        return x1;
    else
        return y1;
}
int main()
{
    int v,u;
    while(scanf("%d%d",&v,&u)!=EOF)
        printf("%d\n",qiumoni(v,u));
    return 0;
}
