/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int main()
{
   int a,b,l,i;
   int sum;
   char shu[N],x[i];
   scanf("%d %s %d",&a,&shu,&b);
   l=strlen(shu);
   sum=change_1(a,shu[N]);
    x[i]=change_2(sum,b,x[i]);
   for(i=0;i<l;i++)
    printf("%s",x[i]);
   printf("\n");
    return 0;
}
int change_1(int a,char c[N]) //把a进制转化为十进制数
{
    int l,i,sum=0,t;
    l=strlen(c);
    for(i=0;i<l;i++)
    {
        if(c[i]>='0'&&c[i]<='9')
			t=c[i]-'0';
		else if(c[i]>='a'&&c[i]<='z')
			t=c[i]-'a'+10;
		else t=c[i]-'A'+10;
		sum=sum*a+t;

    }
    return sum;
}
char change_2(int sum,int b,char m[N]) //把十进制转化为b进制
{
      int t,i,j,c;
        t=sum%b;
		if(t<=9)
			m[i]=t+'0';
		else m[i]=t+'A'-10;
		sum/=b;
		if(sum==0)
			break;
		i++;

		for(j=0;j<=i/2;j++)
		{
			c=m[j];
			m[j]=m[i-j];
			m[i-j]=c;
		}
		m[i+1]='\0';
	return m;
}
*/
# include<stdio.h>
# include<string.h>
int main()
{
	char shu[20],c,x[20];
	int a,b,i,j,l;
	long t,sum;
	scanf("%d %s %d",&a,shu,&b);
	sum=0;
	l=strlen(shu);
	for(i=0;i<l;i++)
	{
		if(shu[i]>='0'&&shu[i]<='9')
			t=shu[i]-'0';
		else if(shu[i]>='a'&&shu[i]<='z')
			t=shu[i]-'a'+10;
		else t=shu[i]-'A'+10;
		sum=sum*a+t;
	}
	i=0;
	while(1)
	{
		t=sum%b;
		if(t<=9)
			x[i]=t+'0';
		else x[i]=t+'A'-10;
		sum/=b;
		if(sum==0)
			break;
		i++;
	}
		for(j=0;j<=i/2;j++)
		{
			c=x[j];
			x[j]=x[i-j];
			x[i-j]=c;
		}
		x[i+1]='\0';
		puts(x);
		return 0;

}
int change_1(int a,char c[N])
{
    for(i=0;i<l;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
			t=c[i]-'0';
		else if(c[i]>='a'&&c[i]<='z')
			t=c[i]-'a'+10;
		else t=c[i]-'A'+10;
		sum=sum*a+t;
	}
}
