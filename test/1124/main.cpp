/*#include <cstdlib>
#include <cstdio>
#include <cstring>
typedef struct node //节点的结构体
{
    int count;//计数
    struct node * next[10];
}node;
node * newnode() //创建新节点
{
    node *q;
    q=(node*)malloc(sizeof(node));
    q->count=0;
    for(int i=0;i<10;i++)
        q->next[i]=NULL;
    return q;
}
int build(node *T,char *s) //建立字典树
{
   node *q;
   q=T;
   int i,k,tag,len;
   len=strlen(s);
   for(tag=i=0;i<len;i++)
   {
       k=s[i]-'0';
       if(q->next[k]==NULL)
       {
           q->next[k]=newnode();
           tag=1;  // 产生了新节点
       }
       q=q->next[k];
       if(q->count) //遇到了结束的节点
             return 0;
   }
   q->count=1; //标记结束的节点
   if(!tag)  return 0;
   return 1;
}
int del(node *p)  //释放字典树空间，否则占用空间太大
{
    if(p==NULL) return 0;
    for(int i=0;i<10;i++)
        if(p->next[i]) del(p->next[i]);
       free(p);
    return 0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    node *T;
    int n,m,flag;
    char s[12];
    scanf("%d",&n);
    while(n--)
    {
        T=(node *)malloc(sizeof(node));
        T->count=0;
        for(int i=0;i<10;i++)
        T->next[i]=NULL;
        flag=1;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
          {
              scanf("%s",s);
               if(flag)
                flag=build(T,s);
          }
          del(T);
          if(!flag)
            printf("NO\n");
          else
            printf("YES\n");
    }
    return 0;
}
*/


#include <cstdlib>
#include <cstdio>
#include <cstring>
typedef struct node //节点的结构体
{
    bool end;//结束的标志
    int  a[10];
}node;
node phonelist[100000];
int x;
int flag;
void Init()
{
    flag=1;
    x=0; //初始位置；
    for(int i=0;i<100000;i++)
    {
        phonelist[i].end=false;
        for(int j=0;j<10;j++)
            phonelist[i].a[j]=-1;
    }
}
int build(char *s) //建立字典树
{
    int k,now=0,tag=0;// 初始位置
    int len=strlen(s);
    for(int i=0;i<len;i++)
   {
       k=s[i]-'0';
       if(phonelist[now].a[k]==-1)
       {
           tag=1;//说明进入一个新的位置
           phonelist[now].a[k]=++x; //下一个位置
           now=x;
       }
       else
       {
          now=phonelist[now].a[k];
          if(phonelist[now].end)
            return 0;  //单词的结束标志
       }
   }
    phonelist[now].end=true; //标记结束的节点
   if(!tag) return 0;
   return 1;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;
    char s[12];
    scanf("%d",&n);
    while(n--)
    {
        Init();
        scanf("%d",&m);
        for(int i=0;i<m;i++)
          {
               scanf("%s",s);
               if(flag)
               flag=build(s);
          }
          if(flag)
            printf("YES\n");
          else
            printf("NO\n");
    }
    return 0;
}



/*#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
    node *next[10];
    int end;
    node(){  //构造函数，方便初始化数据
        memset(next,NULL,sizeof(next));
        end=0;  //end=0表示一般节点，end=1标志一个电话号的结束
    }
};
node *root;
bool insert(char *s)
{
    int i,k,flag;
    node *p=root;
    for(flag=i=0;s[i];++i){
        k=s[i]-'0';
        if(p->next[k]==NULL){
            p->next[k]=new node();
            flag=1;   //标记建立过一个新节点
        }
        p=p->next[k];
        if(p->end) return 0; //碰到结束标志，则返回0
    }
    p->end=1;  //一个电话号的结束标志
    if(!flag) return 0;//字符串插入完毕未出现新建节点的操作，返回0
    return 1;
}
int del(node *p)  //释放字典树空间，否则占用空间太大
{
    if(p==NULL) return 0;
    for(int i=0;i<10;i++)
        if(p->next[i]) del(p->next[i]);
    delete p;
    return 0;
}
int main()
{
    freopen("1.txt","r",stdin);
    int n,T;
    char s[11];
    scanf("%d",&T);
    while(T--){
        bool flag=1;
        root=new node();
        scanf("%d",&n);
        while(n--){
            scanf("%s",s);
            if(flag) flag=insert(s);//假如出现过混乱情况，则不再进行插入操作
        }
        del(root);
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
*/
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

char phone[10000][11];
int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,n;
        bool flag=false;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",phone[i]);
        }
        qsort(phone,n,sizeof(phone[0]),cmp);
        for(i=0;i<n-1;i++)
        {
            if(strncmp(phone[i],phone[i+1],strlen(phone[i]))==0)
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
*/
