#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;
ll gcd( ll a,ll b) //求最大公约数
{
    ll r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
ll square(ll x) //求平方
{
    return x*x;
}
ll distance(ll x1,ll y1,ll x2,ll y2) //两点之间的距离
{
    return square(x1-x2)+square(y1-y2);
}
int main()
{
    ll x1,y1,r1,x2,y2,r2,w,v1,temp;
    while(cin>>x1>>y1>>r1>>x2>>y2>>r2>>w)
    {
        v1=w*r1;
        ll dis=distance(x1,y1,x2,y2);
        if(dis>square(r1+r2) || dis<square(r1-r2) ||w==0)//相离
        {
            printf("0\n");
        }
        else if(dis==square(r1+r2))//外切
        {
            if(w>0) printf("-");
            if(v1%r2==0) printf("%lld\n",(ll)abs(v1)/r2);
            else
            {
                temp=gcd((ll)abs(v1),r2);
                printf("%lld/%lld\n",(ll)abs(v1)/temp,r2/temp);
            }
        }
        else if(dis==square(r1-r2))//内切
        {
            if(w<0) printf("-");
            if(v1%r2==0) printf("%lld\n",(ll)abs(v1)/r2);
            else
            {
                temp=gcd((ll)abs(v1),r2);
                printf("%lld/%lld\n",(ll)abs(v1)/temp,r2/temp);
            }
        }
    }
    return 0;
}
