/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   int n,i,j;
   char a[3],t=0;
   scanf("%d",&n);
   getchar();
   while(n--)
   {
        for(i=0;i<3;i++)
        scanf("%c",&a[i]);
        getchar();
        for(i=0;i<2;i++)
        {
         for(j=1;j<3;j++)
         {
           if(a[i]>a[j])
           {t=a[i];
            a[i]=a[j];
           a[j]=t;}
         }
        }
        for(i=0;i<3;i++)
        printf("%c ",a[i]);
        printf("\n");
     }
   return 0;
}*/
#include "stdio.h"

int main()

{

char a,b,c,d;

int i;

scanf("%d",&i);

getchar();

while(i--)
{

scanf("%c%c%c",&a,&b,&c);

getchar();

if (a>b) {d=a;a=b;b=d;}

if (a>c) {d=a;a=c;c=d;}

if (b>c) {d=b;b=c;c=d;}

printf("%c %c %c\n",a,b,c);



}

return 0;

}
