#include <stdio.h>
int to(int n)
{
    int i,sum=0;
    if(n<=4) return n;
    if(n>4)
        for(i=0;i<=n-4;i++)
            sum+=i;
        return sum+5;
}
int main()
{
   int n;
   while(scanf("%d",&n)&&n!=0)
   {
       printf("%d\n",to(n));
   }
    return 0;
}

#include <stdio.h>
int main()
{
	int n,a[60]={0,1,2,3,4,5};
	for(int i=5; i<60;i++)
	a[i]=a[i-1]+a[i-3];
	while(scanf("%d",&n),n)
	{
		printf("%d\n",a[n]);
	}
}
#include<stdio.h>
 int main()
 {
 int f1,f2,f3,f4,i,n;
 while(scanf("%d",&n)&&n)
 {
 f1=1;
 f2=f3=f4=0;
 for(i=0;i<=n;i++)
 {

 f4=f4+f3;
 f3=f2;
 f2=f1;
 f1=f4;
 }
 printf("%d\n",f1+f2+f3+f4);
 }
 return 0;
 }
