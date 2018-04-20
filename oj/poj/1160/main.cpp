#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    long long x;
    scanf("%d",&t);
    while(t--)
    {
        long long count=0;
        scanf("%I64d",&x);
        while(x)
        {
            if(x%2==0)
            {
                x/=2;
                count++;
            }
            else
            {
                x-=1;
                count++;
            }
        }
        printf("%I64d\n",count);
    }
    return 0;
}
