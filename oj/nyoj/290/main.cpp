#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int count;
    struct node *next[26];
}node;
node *T;
int max;
char pre[20];
node *newnode()
{
    node *q;
    int i;
    q=(node*)malloc(sizeof(node));
    for(i=0;i<26;i++)
        q->next[i]=NULL;
    q->count=0;
    return q;
}
void search(char *s)
{
    node *p;
    int i,len,k;
    p=T;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        k=s[i]-'a';
        if(p->next[k]==NULL)
        {
            p->next[k]=newnode();
        }
        p=p->next[k];
    }
    p->count++;
    if(p->count>max)
    {
        max=p->count;
        strcpy(pre,s);
    }
}
int main()
{
    int t,i;
    char s[15];
    max=0;
    memset(pre,0,sizeof(pre));
    T=(node*)malloc(sizeof(node));
    T->count=0;
    for(i=0;i<26;i++)
        T->next[i]=NULL;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        search(s);
    }
    printf("%s %d\n",pre,max);
}
