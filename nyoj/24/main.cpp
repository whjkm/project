#include <stdio.h>
#include <math.h>
using namespace std;
int prime(int n)
{
    int i,flag=1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
        flag=0;break;
        }
    }
    return flag;
}
int main()
{
    int n,m,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        if(m==1)
        {
            printf("2 1\n");
        }
        for(i=0;i<m/2;i++)
        {
            if(prime(m-i)&&prime(m+i))
            {
                printf("%d %d\n",m-i,i);break;
            }
            else if(prime(m-i)&&!prime(m+i))
            {
                 printf("%d %d\n",m-i,i);break;
            }
            else if (!prime(m-i)&&prime(m+i))
            {
                 printf("%d %d\n",m+i,i);break;
            }
        }
    }
    return 0;
}
