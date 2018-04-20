#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef struct node
{
    int count;
    struct node * next[26];
}node;
//char s[1010][10010];
char s[1000001];
node * newnode()
{
    node *q;
    q=(node*)malloc(sizeof(node));
     q->count=1;
    for(int i=0;i<26;i++)
        q->next[i]=NULL;
    return q;
}
void build(node *T,char *s)
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
           // p->count=1;
            p=p->next[k];
            /*node *NewNode = (node*) malloc (sizeof (node));
            NewNode->count = 1;
            for (int j = 0;j<26;j++) NewNode->next[j] = NULL;
            p->next[k] = NewNode;
            p = NewNode;*/
        }
        else
            {
                p=p->next[k];
                p->count++;
            }
    }
}
int search(node *T)
{
    node *q;
    int sum=0;
    q=T;
    for(int i=0;i<26;i++)
    {
        if(T->next[i]!=NULL)
        {
            q=T->next[i];
            sum+=q->count;
            if(q->count>1)
            {
                sum+=search(q);
            }
        }
    }
    return sum;
}
void Release(node *T)
{
    for(int i=0;i<26;i++)
        if(T->next[i]!=NULL)
            Release(T->next[i]);
        //delete T;
        free(T);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        node *T;
        T=(node *)malloc(sizeof(node));
        T->count=0;
        for(int i=0;i<26;i++)
            T->next[i]=NULL;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            build(T,s);
            //gets(s[i]);
            //build(T,s[i]);
        }
        printf("%d\n",search(T));
        Release(T);
    }
}
