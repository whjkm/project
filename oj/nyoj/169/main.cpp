/*#include <stdio.h>
#include <math.h>
using namespace std;
int prime(int x)
{
    int i;
    for(i=2;i<=sqrt(x);i++)
        if(x%i==0)
         return 0;
        if(x==1)
         return 2;
    return 1;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    while(n--)
    {
        int i=0;
        scanf("%d",&x);
        if(prime(x)==2)
            printf("2\n");
            else{
            while(prime(x+i)==0&&prime(x-i)==0)
                i++;
            if(prime(x+i))
                printf("%d\n",x+i);
            else
                printf("%d\n",x-i);
            }
    }
    return 0;
}
*/
#include<stdio.h>
int a[1010];
void prime()
{
    int i,j;
    a[0]=1;
    a[1]=1;
    for(i=2;i<1010;i++)
        if(a[i]==0)
        for(j=i+i;j<1010;j+=i)
        a[j]=1;
}
int main()
{
    int n,i,t;
    prime();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
    for(i=0;i<1010;++i)
     {
     if(t+i<1010 && a[t+i]==0)
     {
      printf("%d\n",t+i);
     break;
     }
     if(t-i>=0 && a[t-i]==0)
     {
      printf("%d\n",t-i);
      break;
    }
    }
    }
   return 0;
 }

