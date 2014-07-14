/*#include <stdio.h>
#include <string.h>
int main()
{
   int n,m,i;
   char a[10];
   scanf("%d",&n);
   while(n--)
   {
      char b[10]="zzzzz";
       scanf("%d",&m);
       getchar();
       for(i=0;i<m;i++)
        {gets(a);
        if(strcmp(a,b)<0)
            strcpy(b,a);
        }
       puts(b);
       printf("\n");
   }
    return 0;
}
*/

#include<stdio.h>
#include<string.h>
main()
{int n;
scanf("%d",&n);
while(n--)
    {int m;
char a[6],c[6];
scanf("%d",&m);
getchar();
gets(c);
while(--m)
    {gets(a);
if(strcmp(a,c)<0)
    strcpy(c,a);
    }
puts(c);
}
}
