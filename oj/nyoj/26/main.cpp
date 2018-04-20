/*#include <stdio.h>
#define MAXN 1000010
int s[MAXN],temp[MAXN];
int main()
{
   int n,m,i,j,count,k;
   for(i=2;i<MAXN;i++)
     s[i]=0;
   for(i=2;i<MAXN;i++)
   {
       if(s[i]==0)
        for(j=i+i;j<MAXN;j+=i)
         s[j]=1;
   }
    scanf("%d",&n);
   while(n--)
   {
       count=0;
       scanf("%d",&m);
       for(i=2,k=0;i<=m;i++)
       {
           if(s[i]==0)
            temp[k++]=i;
       }
       for(i=0;i<k;i++)
       {
           if(temp[i+1]-temp[i]==2||temp[i+1]-temp[i]==1)
              count++;
       }
       printf("%d\n",count);
   }
    return 0;
}
*/
#include <stdio.h>
#define MAXN 1000010
int s[MAXN];
int main()
{
   int n,m,i,j,count;
   for(i=2;i<MAXN;i++)
     s[i]=0;
   for(i=2;i<MAXN;i++)
   {
       if(s[i]==0)
        for(j=i+i;j<MAXN;j+=i)
         s[j]=1;
   }
    scanf("%d",&n);
   while(n--)
   {
       count=0;
       scanf("%d",&m);
       for(i=2;i<=m;i++)
       {
           if((s[i]==0&&s[i+2]==0&&i+2<=m)||(s[i]==0&&s[i+1]==0&&i+1<=m))
            count++;
       }
       printf("%d\n",count);
   }
    return 0;
}
