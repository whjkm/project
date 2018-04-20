#include <iostream>
#include <cstdio>
using namespace std;
long long  Calculation(long long a,long long b,int c)
{
    int ans=1;
    a=a%c;
    while(b>0)
    {
        if(b%2==1)
            ans=(ans*a)%c;
        b=b/2;
        a=(a*a)%c;
    }
    return ans;
}
int main()
{
    int t;
    long long n,sum;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lld",&n);
       sum=Calculation(n,n,10);
       printf("%d\n",sum);
    }
    return 0;
}
