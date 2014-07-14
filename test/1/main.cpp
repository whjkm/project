#include <cstdio>
int main()
{
    int n,temp;
    while(scanf("%d",&n)&&n!=0)
    {
        int sum=0;
        while(n>=3)
        {
            sum+=n/3;
            temp=n%3;
            n/=3;
            n=temp+n;
        }
        if(n==2)
            sum++;
        printf("%d\n",sum);
    }
    return 0;
}
