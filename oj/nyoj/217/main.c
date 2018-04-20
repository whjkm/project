#include <stdio.h>
int main()
{
   int t,y;
   char x;
   scanf("%d",&t);
   while(t--)
   {
       getchar();
       scanf("%c%d",&x,&y);
       if(x>='A'&&x<='Z')
        printf("%d\n",x-64+y);
        if(x>='a'&&x<='z')
         printf("%d\n",y+96-x);
   }
    return 0;
}
