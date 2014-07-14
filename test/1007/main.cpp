/*#include <cstdio>
#include <cstring>
int main()
{
    int a,b,c,i;
    char op,s[10];
    int count=0;
    while(scanf("%s",s)!=EOF)
    {
      i=0;
      a=0;
      b=0;
      while(s[i]>='0'&&s[i]<='9')
      {
         a=a*10+(s[i]-'0');
         i++;
      }
      op=s[i];
      i++;
      while(s[i]>='0'&&s[i]<='9')
      {
          b=b*10+(s[i]-'0');
          i++;
      }
      i++;
      if(s[i]>='0'&&s[i]<='9')
      {
          c=0;
          while(s[i]>='0'&&s[i]<='9')
          {
              c=c*10+(s[i]-'0');
              i++;
          }
      }
      else
        c=-1;//错误标记
      if((op=='+'&&c==a+b)||(op=='-'&&c==a-b))
        count++;
    }
     printf("%d\n",count);
    return 0;
}
*/
#include <cstdio>
#include <cstring>
int main()
{
    int a,b,c,i;
    char op,s[10];
    int count=0;
    while(scanf("%d%c%d=%s",&a,&op,&b,s)!=EOF)
    {
      i=0;
      if(s[i]>='0'&&s[i]<='9')
      {
          c=0;
          while(s[i]>='0'&&s[i]<='9')
          {
              c=c*10+(s[i]-'0');
              i++;
          }
      }
      else
        c=-1;//错误标记
      if((op=='+'&&c==a+b)||(op=='-'&&c==a-b))
        count++;
    }
     printf("%d\n",count);
    return 0;
}
