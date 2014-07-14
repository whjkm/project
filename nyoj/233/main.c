#include <stdio.h>
int main()
{
    int n,a[1000],t,m,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        m=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                m++;
            }
        }
        printf("%d\n",m);
    }
    return 0;
}
