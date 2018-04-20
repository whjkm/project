
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 500002
typedef struct node
{
    int order;
    struct node *next[26];
}node;
int father[MAXN];
int visit[MAXN];
int m;
int find(int x)
{
  if(father[x]==-1) return x;
  return father[x]=find(father[x]);
}
void Union(int x,int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx!=fy)
     father[fy]=fx;
}
int search(char *s,node *T)
{
    int len,i,j,flag=0,id;
    node *q,*p;
    len=strlen(s);
    q=T;
    for(i=0;i<len;i++)
    {
        id=s[i]-'a';
       if(q->next[id]==NULL)
        {
            flag=1;
            p=(node *)malloc(sizeof(node));
            for(j=0;j<26;j++)
                p->next[j]=NULL;
            q->next[id]=p;
        }
        q=q->next[id];
    }
    if(flag)
    {
        q->order=m++;
        visit[q->order]=!visit[q->order];
        return q->order;
    }
    else
    {
         visit[q->order]=!visit[q->order];
        return q->order;
    }
}
int main()
{
    int t,n,i,num1,num2;
    char s1[20],s2[20];
    node *T;
    scanf("%d",&t);
    while(t--)
    {
        m=1;
        memset(father,-1,sizeof(father));
        memset(visit,0,sizeof(visit));
        T=(node*)malloc(sizeof(node));
        T->order=0;
        for(i=0;i<26;i++)
            T->next[i]=NULL;
        scanf("%d",&n);
        if(n==0) { printf("Possible\n"); continue ;}
        for(i=1;i<=n;i++)
        {
            scanf("%s%s",s1,s2);
            num1=search(s1,T);
            num2=search(s2,T);
            Union(num1,num2);
        }
        int ans=0,sum=0;
        for(i=1;i<m;i++)
        {
            if(father[i]==-1) ans++;
            if(visit[i]) sum++;
        }
        if(ans>1) printf("Impossible\n");
        else
        {
            if(sum==2||sum==0)
               printf("Possible\n");
            else
                printf("Impossible\n");
        }
    }
    return 0;
}
