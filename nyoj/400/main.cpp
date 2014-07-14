#include <string.h>
#include <stdio.h>
int main()
{
   int t,len1,len2,i,sum;
   char a[100],b[100];
   scanf("%d",&t);
   while(t--)
   {
       sum=0;
       scanf("%s%s",a,b);
       len1=strlen(a);
       len2=strlen(b);
       for(i=0;i<len1;i++)
        sum+=(a[i]-'0');
        for(i=0;i<len2;i++)
        sum+=(b[i]-'0');
        printf("%d\n",sum);
   }
    return 0;
}
