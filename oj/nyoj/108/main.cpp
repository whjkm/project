
/*#include <stdio.h>
int s[1000001],x[1000001];
int main()
{
    int n,m,i,a,b;
    int  sum=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
      scanf("%d",&s[i]);
    for(i=0;i<n;i++)
      {
          sum+=s[i];
          x[i]=sum;
      }
      while(m--)
      {
          scanf("%d%d",&a,&b);
          printf("%d\n",x[b-1]-x[a-2]);
      }
    return 0;
}
*/

/*#include<stdio.h>
 int a[1000000],b[1000000];
 int main()
 {

 int n,m,i,p,q,sum=0;
 scanf("%d %d",&n,&m);
 for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
sum=sum+a[i];
 b[i]=sum;}
 while(m--)
 {
 scanf("%d %d",&p,&q);
 printf("%d\n",b[q-1]-b[p-2]);
 }
 return 0;
 }
*/


#include<stdio.h>
int s[1000001]={0};
int main()
{
     int n,m,i,a,b;
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;i++)
      {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
      }
      while(m--)
      {
          scanf("%d%d",&a,&b);
          printf("%d\n",s[b]-s[a-1]);
      }
      return 0;
}
