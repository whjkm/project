#include <cstdio>
#include <cstring>
int main()
{
   long long n;
   long long sum;
   while(scanf("%I64d",&n)&&n!=0)
   {
       sum=n/10-(n%10*5);
       if(sum%17==0)
        printf("1\n");
       else
        printf("0\n");
   }
    return 0;
}

/*#include<stdio.h>
int main()
{
	int i,sum;
	char str[105];
	while(scanf("%s",str)&&str[0]!='0')
	{
		sum=0;
		for(i=0;str[i]!='\0';i++)
		{
			sum=sum*10+str[i]-'0';
			sum=sum%17;
		}
		printf("%s\n",sum?"0":"1");
	}
	return 0;
}
*/
