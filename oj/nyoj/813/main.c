
#include <stdio.h>
int main()
{
    int n,k,a;
    while(scanf("%d%d",&n,&k)!=EOF&&n!=0&&k!=0)
    {
        for(a=1;a<=n/2;a++)
                if(a*(n-a)==k)
                {printf("YES\n");break;}
               if(a*(n-a)!=k)
                printf("NO\n");
    }
    return 0;
}
/*#include<stdio.h>
int main()
{
int n,m,i;
while(~scanf("%d%d",&n,&m) && (n + m))
{
int flag = 0;
for(i = 1; i <= n / 2; i++)
if(i * (n - i) == m)
{
flag = 1;
break;
}
printf("%s\n",flag ? "YES" : "NO");
}
return 0;
}
*/
/* #include <cstdio>

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)&&(n||k))
    {
        int ok=0;
        for(int i=1;i<=n/2;i++)
        {
            if(i*(n-i)==k)
                ok=1;continue;
        }
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}   */


