#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
   int t,a[1000],i;
   char s[1000];
   while(scanf("%d",&t)!=EOF)
   {
       for(i=0;i<t;i++)
       scanf("%d",&a[i]);
       sort(a,a+t);
      for(i=0;i<t;i++)
        s[i]=a[i]%26+'A';
      for(i=0;i<t;i++)
        printf("%c ",s[i]);
      printf("\n");
   }
    return 0;
}
