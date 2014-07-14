#include <stdio.h>
#include <string.h>
typedef struct node
{
    int count;
    struct node *next[10];
}node;
int main()
{
    int t,n;
    char s[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s",s);
    }
}
