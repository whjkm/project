#include <stdio.h>
#include <string.h>
long long sum[15]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int main()
{
   int n;
   //char s[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
   char c[12];
   scanf("%d",&n);
   while(n--)
   {
   	   long long num=0;
  	   memset(c,0,sizeof(c)); 
       scanf("%s",c);
       for(int i=0;i<12;i++)
         {
             long long temp=0;
            for(int j=i+1;j<12;j++)
            {
                if(c[j]<c[i])temp++;
            }
         num+=temp*sum[12-i-1];
         }
        printf("%lld\n",num+1);
   }
    return 0;
}
