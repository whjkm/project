#include <string.h>
#include <stdio.h>
int main()
{
   int t,i,l,x,k;
   char a[1000],b[1000];
   scanf("%d",&t);
   while(t--)
   {
       x=0,k=0;
      scanf("%s",a);
      l=strlen(a);
      if(a[0]>='A'&&a[0]<='Z')  //实现字母转换成数字,相当于26进制转换成10进制
      {
          for(i=0;i<l;i++)
          x = x* 26 + a[i] - 'A' + 1;
          printf("%d\n",x);
      }
      else
      {
        for(i=0;i<l;i++)
        x=x*10+(a[i]-'0');
        while(x)
        {
             b[k++] = (x- 1) % 26 + 'A';
             x= (x- 1) / 26;
        }
             for(i=k-1;i>=0;i--)
                printf("%c",b[i]);
        printf("\n");
      }
   }
    return 0;
}
