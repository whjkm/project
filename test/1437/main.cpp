#include <stdio.h>
#include <string.h>
char s[10002];
bool visit[10002];
int main()
{
    int t,len,i,j;
    long long count;
    scanf("%d",&t);
    while(t--)
    {
        count=1;
        memset(visit,false,sizeof(visit));
        scanf("%s",s);
        len=strlen(s);
        if(s[0]=='?')
        {
            for(int i=0; s[i]=='?'; i++)
                visit[i]=true;
        }
        if(s[len-1]=='?')
        {
            for(int i=len-1; s[i]=='?'; i--)
                visit[i]=true;
        }
        for(i=0;i<len;i++)
        {
            if(!visit[i] && s[i]=='?')
            {
                for(j=i;s[j]=='?';j++)
                    visit[j]=true;
                if(s[i-1]!=s[j])
                {
                    count=count*(j-i+1)%1000000007;
                }
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
