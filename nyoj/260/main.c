#include <stdio.h>
int main()
{
    int n,m,sum,i,t;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        t=0;
        scanf("%d",&m);
        for(i=0;i<=m;i++)
            sum=sum+i;
            t+=sum;
        printf("%d\n",t);
    }
    return 0;
}
