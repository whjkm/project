#include <stdio.h>
int main()
{
   int a,b;
   __int64 temp;//long long
   while(scanf("%d%d",&a,&b)!=EOF)
   {
       __int64 max=a;//long long
       int count=0;
       for(int i=a;i<=b;i++)
       {
           temp=i;
           while(temp!=1)
           {
               if(temp%2==0)
                temp=temp/2;
               else
                temp=3*temp+1;
               count++;
               if(max<temp)
                 max=temp;
           }
       }
       printf("%d %I64d\n",count,max);
   }
    return 0;
}
