#include <stdio.h>
int main()
{
    int n,sum,i,a,b;
    int c[20];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {  sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            c[i]=a+b;
            if(c[i]>sum)
            sum=c[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
