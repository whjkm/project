#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char a,b;
    scanf("%d",&n);
    while(n--)
    {   getchar();
        scanf("%c %c",&a,&b);
        if(a>b)
        printf("%c<%c\n",a,b);
        else if(a==b)
         printf("%c=%c\n",a,b);
        else if(a<b)
         printf("%c>%c\n",a,b);
    }
    return 0;
}
