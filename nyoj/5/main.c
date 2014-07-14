#include <stdio.h>
#include <stdlib.h>
int max1(int m,int n);
int min1(int m,int n);
int main()
{
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    printf("%d ",min1(min1(min1(min1(a,b),c),d),e));
    printf("%d ",max1(e,max1(d,max1(c,max1(a,b)))));
    return 0;
}
int max1(int m,int n)
{
    if (m>n)
        return m;
    else
        return n;
}
int min1(int m,int n)
{
    if (m<n)
       return m;
    else return n;
}
