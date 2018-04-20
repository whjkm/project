#include<stdio.h>
 int main()
 {
 int n,m,sum,i;
 int a[10001];
 scanf("%d",&n);
 while(n--)
 {
 scanf("%d",&m);
 sum=-100;
 for(i=0;i<m;i++)
 {
 scanf("%d",&a[i]);
 if(a[i-1]>0) a[i]+=a[i-1];
 if(a[i]>sum) sum=a[i];
 }
 printf("%d\n",sum);
 }
 return 0;
 }



#include<stdio.h>
 int main()
 {
 int n,m,i,max,sum;
 scanf("%d",&n);
 while(n--)
 {
 max=0;
 scanf("%d",&m);
 scanf("%d",&sum);
 max=sum;
 while(--m)
 {
 scanf("%d",&i);
 if(sum<0) sum=i;
 else sum+=i;
 if(sum>max) max=sum;
 }
 printf("%d\n",max);
 }
 }
