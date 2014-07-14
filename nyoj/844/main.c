
#include<stdio.h>
#include<string.h>
#define  N  10
int main ()
{
    int c[N]={0};
    char s1[N],s2[N];
    int lenth1,lenth2,i,n=0;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        if(s1[0]=='0'&&s2[0]=='0')
        {break;}
    lenth1=strlen(s1);
    lenth2=strlen(s2);
    n=lenth1>lenth2?lenth1:lenth2;
    for(i=0;i<n;i++)
       {
     c[i]=(s1[i]-'0')+(s2[i]-'0');
       for(i=0;i<n;i++)
	   {
		if(c[i]>=10)
        {
			c[i] %= 10;
			c[i+1]++;
        }
	   }
       }
   while(n>=0 && !c[n]) n--;		//È¥Ç°µ¼Áã
	while(n>=0) printf("%d", c[n--]);
     printf("\n");
    }
   return 0;
}
