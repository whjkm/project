#include <stdio.h>
int main()
{
    int m,n,i;
    scanf("%d",&m);
    while(m--)
    {
       scanf("%d",&n);
       for(i=1;n-i>0;i++)
        n=n-i;
       if(i%2)
        printf("%d/%d\n",i+1-n,n);
       else
        printf("%d/%d\n",n,i+1-n);
    }
    return 0;
}
