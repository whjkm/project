/*#include <stdio.h>    //233´úÂëÃ°ÅİÊµÏÖ
int main()
{
   int t,i,j,temp,count,n;
   int a[1000001];
   scanf("%d",&t);
   while(t--)
   {
       count=0;
       scanf("%d",&n);
       for(i=0;i<n;i++)
        scanf("%d",&a[i]);
       for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
           if(a[i]>a[j])
           {
               temp=a[j];
               a[j]=a[i];
               a[i]=temp;
               count++;
           }
       printf("%d\n",count);
   }
    return 0;
}
*/

#include <stdio.h>
int a[1000001],temp[1000001];
int  mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i=first,j=mid+1;
    int m=mid,n=last;
    int k=0,count=0;
    while(i<=m&&j<=n)
    {
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else
        {
        temp[k++]=a[j++];
        count+=(mid-i+1);
        }
    }
    while(i<=m)
        temp[k++]=a[i++];
    while(j<=n)
        temp[k++]=a[j++];
    for(i=0;i<k;i++)
        a[first+i]=temp[i];
        return count;
}
int sort(int a[],int first,int last)
{
     int x,y,z;
     int mid=(first+last)/2;
     if(first>=last)
     {
         return 0;
     }
     x=sort(a,first,mid);
     y=sort(a,mid+1,last);
     z=mergearray(a, first, mid, last,temp);
     return (x+y+z);
}
int main()
{
   int t,i,n;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",sort(a,0,n-1));
   }
   return 0;
}
