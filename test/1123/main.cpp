#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef struct node //节点的结构体
{
    int count;//计数
    struct node * next[26];
}node;
node * newnode() //创建新节点
{
    node *q;
    q=(node*)malloc(sizeof(node));
    q->count=1;
    for(int i=0;i<26;i++)
        q->next[i]=NULL;
    return q;
}
void build(node *T,char *s) //建立字典树
{
    node *p;
    p=T;
    int len,k;
    len=strlen(s);
    for(int i=0;i<len;i++)
    {
        k=s[i]-'a';
        if(p->next[k]==NULL)
        {
            p->next[k]=newnode();
            p=p->next[k];
        }
        else
        {
            p=p->next[k];
            p->count++;
        }
    }
}
int search(node *T,char *c) //查询字典树
{
    node *q;
    int sum=0,len,k;
    q=T;
    len=strlen(c);
    for(int i=0;i<len;i++)
    {
        k=c[i]-'a';
        if(q->next[k]!=NULL)
          q=q->next[k];
        else
          return sum=0;
    }
    sum=q->count;
    return sum;
}
int main()
{
    char s[12];
    char c[12];
    node *T;
    T=(node *)malloc(sizeof(node));
    T->count=0;
    for(int i=0;i<26;i++)
        T->next[i]=NULL;
    memset(s,0,sizeof(s));
    memset(c,0,sizeof(c));
    while(gets(s))
    {
       if(strcmp(s,"")==0)
        break;
       build(T,s);
    }
    while(scanf("%s",c)!=EOF)
    {
        printf("%d\n",search(T,c));
    }
    return 0;
}
