#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
   int n,m,s,n1,n2;
   int x[4];
   scanf("%d",&n);
   while(n--)
   {
    scanf("%d",&m);
    s=1;
    while(m!=6174)
    {
        x[0]=m%10;
        x[1]=m/10%10;
        x[2]=m/100%10;
        x[3]=m/1000;
        sort(x,x+4);
        n1=x[0]+x[1]*10+x[2]*100+x[3]*1000;
        n2=x[0]*1000+x[1]*100+x[2]*10+x[3];
        m=n1-n2;
        s++;
    }
    printf("%d\n",s);
   }
    return 0;
}

