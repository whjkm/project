#include <cstdio>
#include <cstring>
char s[101];
char c[6]={'X','T','C','P','C'};
int main()
{
    int t,i,j,id;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        id=0;
        scanf("%s",s);
        for(j=0;j<strlen(s);j++)
        {
            if(s[j]==c[id])
                id++;
        }
        if(id==5)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
}
