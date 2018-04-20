#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int x,y,a,b,c,count,k=0;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        count=0;
         for(a=x;a<=1000&&a<=y;a++)
            for(b=x;b<=1000&&b<=y;b++)
         {
             int s=a*a*a+b*b*b;
             if(s%10!=3) continue;
              c=s/10;
              if(c>=x&&c<=y) count++;
         }
          printf("Case %d: %d\n", ++k, count);
    }
    return 0;
}
