#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a,int b)//euclid
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void extend_euclid(int f,int d)
{
    int x1,x2,x3;
    int y1,y2,y3;
    int q,t1,t2,t3,flag=0;
    x1=1,x2=0,x3=f;
    y1=0,y2=1,y3=d;
    while(1)
    {
        if(flag==1) break;
        if(y3==0)  x3=gcd(f,d);
        else if(y3==1)
        {
            y3=gcd(f,d);
            printf("%d\n",y2);
            flag=1;
        }
        q=x3/y3;
        t1=x1-q*y1;
        t2=x2-q*y2;
        t3=x3-q*y3;
        x1=y1,x2=y2,x3=y3;
        y1=t1,y2=t2,y3=t3;
    }
}
int main()
{
    int a,b;
    printf("输入要进行模逆运算的两个数:\n");
    scanf("%d%d",&a,&b);
    extend_euclid(a,b);
    return 0;
}





/*#include<stdio.h>              //求模逆运算的stein算法
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
*/


/*#include <iostream>
#include <cstdio>
using namespace std;
int x,y,q;
void extend_Eulid(int a,int b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        q = a;
    }
    else
    {
        extend_Eulid(b,a%b);
        int temp = x;
        x = y;
        y = temp - a/b*y;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    extend_Eulid(a,b);
    printf("%d=(%d)*%d+(%d)*%d\n",q,x,a,y,b);
    return 0;
}
*/


/*#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int stein(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    if(a%2==0 && b%2==0) return 2*stein(a>>1,b>>1);
    else if(a%2==0)   return stein(a>>1,b);
    else if(b%2==0)   return stein(a,b>>1);
    else return stein(abs(a,b),min(a,b));
}
int main()
{
    printf("%d\n",stein(18,12));
}
*/
