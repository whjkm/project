
/*#include <stdio.h>
#include <algorithm>
#include<string.h>
using namespace std;
struct num
{
    int number;
    int flag;
};
 struct num a[200005];
 int c[200005]={0};
 int cmp(struct num a,struct num b)
 {
  if(a.number<b.number)
  return 1;
  return 0;
 }
int main()
{
   int t,i,n,j,temp;
   scanf("%d",&t);
   while(t--)
   {
       int maxs=0;
       memset(c,0,sizeof(c));
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
       a[i].number=0;
       a[i].flag=0;
       }
       for(i=0;i<n;i++)
        scanf("%d",&a[i].number);
        sort(a,a+n,cmp);
        temp=a[0].number;
       for(i=0;i<n;i++)
      {
        if(c[i]==0)
        {
        for(j=i+1;j<n;j++)
        {
         if(a[i].number==a[j].number)
           { a[i].flag++;
             c[j]++;
           }
         else
            break;
        }
        if(maxs<a[i].flag)
              {maxs=a[i].flag;
              temp=a[i].number;
              }
              else if(a[i].flag==maxs)
              {
               if(temp>a[i].number)
               temp=a[i].number;
              }
        }
      }
      printf("%d\n",temp);

}
    return 0;
}
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200001];
int main()
{
    int t,n,count,max,temp,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        max=1,count=1,temp=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                count++;
            else
            {
                if(count>max)
                {
                    max=count;
                    temp=a[i-1];
                }
                count=1;
            }
        }
        if(count>max)
            temp=a[i-1];
        printf("%d\n",temp);
    }
}


#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct num
{
    int number;
    int flag;
};
struct num a[200001];
int b[200001];
int cmp(struct num a,struct num b)
{
if(a.number<b.number)
return 1;
return 0;
}
int main()
{
   int t,i,n,j;
   scanf("%d",&t);
   while(t--)
   {
       memset(b,0,sizeof(b));
       int maxs=0;
       scanf("%d",&n);
       for(i=0;i<n;i++)
        {
            a[i].number=0;
            a[i].flag=0;
            scanf("%d",&a[i].number);
        }
        int temp=a[0].number;
         sort(a,a+n,cmp);
      for(i=0;i<n;i++)
      {
          if(b[i]==0)
      {
        for(j=i+1;j<n;j++)
            {
            if(a[i].number==a[j].number)
                 {
                     a[i].flag++;
                     b[j]++;
                 }
            else
                break;
            }
      }
      if(maxs<a[i].flag)
        {
            maxs=a[i].flag;
           temp=a[i].number;
        }
   else if(a[i].flag==maxs)
     {
       if(temp>a[i].number)
        temp=a[i].number;
     }
    }
    printf("%d\n",temp);
   }
    return 0;
}
