/*#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,sum,s;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     scanf("%lld %lld",&n,&m);
      sum=0;
      s=1;
      for(int i=1;i<=n;i++)
       {
           if(i==m)
            break;
           s=s*i%m;
           sum=s+sum;
           sum=sum%m;
       }
       sum++;
       sum=sum%m;
       printf("%lld\n",sum);
   }
   return 0;
}
*/


#include <cstdio>
#include <cstring>
char s[120];
long long m,n,sum,ans;
int main()
{
   int t,len;
   scanf("%d",&t);
   while(t--)
   {
       sum=ans=1;
       scanf("%s%I64d",s,&m);
       len=strlen(s);
       /*if(m==1)
       {
           printf("0\n");
           continue;
       }*/
       if(len>7)
       {
           n=m-1; //当n>=m时，n！对m取余为0
       }
       else
       {
           n=0;
           for(int i=0;i<len;i++)//把字符串转化为数字
           n=n*10+s[i]-'0';
       }
       //求阶乘取余
       for(int i=1;i<=n;i++)
       {
           sum=(sum*i)%m;
           ans=(sum+ans)%m;
       }
       printf("%I64d\n",ans);
   }
}
