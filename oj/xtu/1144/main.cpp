#include <stdio.h>
#include <string.h>
int main()
{
   int t,l;
   char s[4100];
   scanf("%d",&t);
   getchar();
   while(t--)
   {
       gets(s);
       l=strlen(s);
       printf("%s\n",s);
       for(int i=0;i<l;i++)
       {
           if(s[i]==' ')
           {
               for(int j=i;j>=0;j--)
                   s[j]=' ';
                  printf("%s\n",s);
                continue;
           }
       }
     printf("\n");
   }
    return 0;
}
