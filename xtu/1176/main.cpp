#include <stdio.h>
#include <cstring>
int main()
{
    char a,b;
    while(scanf("%c %c",&a,&b)!=EOF)
    {
        getchar();
      if(a=='M' || a=='F')
       {
           printf("Error\n");
           continue;
       }
       else if(b=='F')
       {
           printf("Bingo\n");
           continue;
       }
       else if(a=='B'||b=='B')
        {
            printf("0\n");
            continue;
        }
       else if(b=='M')
       {
           if(a=='9')
           {
               printf("1\n");
               continue;
           }
           else if(a=='B')
           {
               printf("0\n");
               continue;
           }
           else
           {
               printf("-1\n");
               continue;
           }
       }
      else if(a>'0'&&a<'10'&&a<b)
        {
            printf("1\n");
            continue;
        }
     else if(a>'0'&&a<'10'&&a>b)
        {
            printf("-1\n");
            continue;
        }
     else if(a==b)
        {
            printf("0\n");
            continue;
        }
    }
    return 0;
}
