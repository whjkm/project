#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main()
{
   int n,a,b,c;
   while( scanf("%d",&n)&&n!=0)
   {
       a=n/100;
       b=(n-a*100)/10;
       c=n%10;
      if(n==a*a*a+b*b*b+c*c*c)
        printf("Yes\n");
      else
        printf("No\n");
   }
   return 0;
}*/
int main()
{
   int n,i,j;
   char a[100];
   scanf("%d",&n);
   getchar();
   while(n--)
  {
       gets(a);
       j=strlen(a);
       for(i=0;i<j;i++)
       {
           if(a[i]>='a'&&a[i]<='z')
            a[i]=a[i]-32;
           else if(a[i]>='A'&&a[i]<='Z')
            a[i]=a[i]+32;
       }
    puts(a);
   }
   return 0;
}
