/*#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
 int n,i,j,q[400]={0},k;
 while(scanf("%d",&n)!=EOF)
 {
 	k=0;
     for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
     {
         if(i*j==n)
         {
            q[k++]=i*10+j;
         }
     }
     sort(q,q+k);
    if(q[0]==0)
        printf("-1\n");
    else
        printf("%d\n",q[0]);
}
    return 0;
}
*/
#include <stdio.h>
int main()
{
    int n,k,s,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;;i++)
        {
            k=1;
            s=i;
            while(s)
            {
                k*=(s%10);
                s/=10;
            }
          if (k==n) {printf("%d\n",i);break;}
          if(i>3555) {printf("-1\n");break;}
        }
    }
    return 0;
}
