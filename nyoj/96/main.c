#include <stdio.h>
#include <string.h>
#define N 1000000
int main()
{
    int m,l,i,k,n;
    char a[N];
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        k=0;
        n=1;
       gets(a);
       l=strlen(a);
       if(k==l-1)
            printf("0");

      else
      {
       for(i=1;i<l-1;i++)
       {
           if(a[i]!='0')
           {
           n=i;
           break;
           }
           }
           if(a[1]=='0'&&n==1)
              printf("%c\n",a[l-1]);
           else
           {
           for(i=n;i<l-1;i++)
            printf("%c",a[i]);
           printf("%c\n",a[l-1]);
            }
       }
}
    return 0;
}

