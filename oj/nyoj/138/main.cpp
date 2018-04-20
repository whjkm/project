/*#include <stdio.h>
#include <string.h>
const int maxn=1000002;
const int fib=111123;
int Hash[maxn],head[maxn],next[maxn];
int top;
void add(int m)
{
    int key=m%fib;
    next[top]=head[key];
    head[key]=top;
    Hash[top]=m;
    top++;
}
bool query(int m)
{
    int key=m%fib;
    for(int i=head[key];i>-1;i=next[i])
    {
        if(Hash[i]==m)
            return true;
    }
    return false;
}
int main()
{
    int n,m,num;
    char s[5];
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    top=0;
    while(n--)
    {
        scanf("%s %d",s,&m);
        if(s[0]=='A')
        {
           for(int i=0;i<m;i++)
           {
                scanf("%d",&num);
                add(num);
           }
        }
        else
        {
           for(int i=0;i<m;i++)
           {
               scanf("%d",&num);
               if(query(num)) printf("YES\n");
               else printf("NO\n");
           }
        }
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
int Hash[3125005]={0};
int main()
{
    int n,m,num;
    char s[5];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %d",s,&m);
        if(s[0]=='A')
        {
           for(int i=0;i<m;i++)
           {
                scanf("%d",&num);
                Hash[num / 32] |= 1 << (num % 32);
           }
        }
        else
        {
           for(int i=0;i<m;i++)
           {
               scanf("%d",&num);
               if(Hash[num / 32] & (1 << (num % 32))) printf("YES\n");
               else printf("NO\n");
           }
        }
    }
    return 0;
}
