#include <stdio.h>
int main()
{
    int a,b,c,sum;
    scanf("%d%d%d",&a,&b,&c);
    for(sum=10;sum<100;sum++)

      if(sum%3==a&&sum%5==b&&sum%7==c)
           {printf("%d",sum);break;}
      if(sum>=100)
            printf("No answer");

    return 0;
}
