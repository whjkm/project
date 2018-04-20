/*#include <stdio.h>
int main()
{
    int a[10],i,j,t=0;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<9;i++)
        for(j=i+1;j<10;j++)
    {
        if(a[i]<a[j])
            {
                t=a[i];
            a[i]=a[j];
             a[j]=t;
          }
    }
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
*/



#include <stdio.h>
#define N 300
int main()
{
    int s,w,n,a[N],i,j,t,k;
    scanf("%d",&s);
    while(s--)
    {   t=0;k=0;
        scanf("%d%d",&w,&n);
        for(i=0;i<n;i++)
              scanf("%d",&a[i]);
        /*for(i=0;i<n-1;i++)
              for(j=i+1;j<n;j++)
                  if(a[i]<a[j])
                 {
                   t=a[i];
                  a[i]=a[j];
                  a[j]=t;
              }*/
          for(i=0;i<n;i++)
              for(j=i+1;j<n;j++)
               if(a[i]+a[j]<=w)
                 {
                    k++;
                    a[j]=w;
                      break;
                }
                 printf("%d\n",n-k);
      }
  return 0;
}
 /*i=0;j=n;m=0;
        while(i<=j)
        {
            if(a[i]+a[j]>w)
            {
                i++;
                m++;
            }
            else
            {
                i++;
                j--;
                m++;
            }
        }
        printf("%d\n",m);
    }*/
