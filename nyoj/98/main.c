/*#include <stdio.h>
int main()
{
   int n,m;
   scanf("%d",&n);
   while(n--)
   {
       scanf("%d",&m);
       if(m>=90&&m<=100)
        printf("A\n");
       else if(m>=80&&m<=89)
        printf("B\n");
        else if(m>=70&&m<=79)
        printf("C\n");
         else if(m>=60&&m<=69)
        printf("D\n");
        else if(m>=0&&m<=59)
            printf("E\n");
   }
    return 0;
}
*/
#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        switch(m/10)
        {
            case 10 :printf("A\n");break;
            case 9 :printf("A\n");break;
            case 8 :printf("B\n");break;
            case 7 :printf("C\n");break;
            case 6 :printf("D\n");break;
            default:printf("E\n");break;
        }
    }
    return 0;
}
