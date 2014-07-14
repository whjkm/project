#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int fab(int n);
int main()
{
   int n,i;
   scanf("%d",&i);
   while(i--)
   {
       scanf("%d",&n);
       printf("%d",fab(n));
       printf("\n");
   }
    return 0;
}
int fab (int n)
{

    if(n==1||n==2)
        return 1;
    else
        return fab(n-1)+fab(n-2);
}
*/
#include<stdio.h>
int main()
{
    int n;
    char a,b,c,d;
    scanf("%d",&n);
    getchar();
    while(n--)
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
