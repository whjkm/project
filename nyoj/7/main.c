#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   int n,i,j,m,z;
   char a[200];
   scanf("%d",&n);
   getchar();
   while(n--)
   {
       m=0;
       gets(a);
     i=strlen(a);
     for(j=0;j<i;j++)
     {
         if(a[j]>='a'&&a[j]<='z')
           m++;
     }
      z=m%26;
      if(z==0)
     printf("z\n");
     else
     {  z=z+96;
        printf("%c",z);
        printf("\n");
     }
   }
   return 0;
}

/*int main()
{
    int a[3],i,j,t;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
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
        printf("%d ",a[i]);
    return 0;
}*/
