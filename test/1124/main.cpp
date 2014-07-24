/*#include <cstdlib>
#include <cstdio>
#include <cstring>
typedef struct node //�ڵ�Ľṹ��
{
    int count;//����
    struct node * next[10];
}node;
node * newnode() //�����½ڵ�
{
    node *q;
    q=(node*)malloc(sizeof(node));
    q->count=0;
    for(int i=0;i<10;i++)
        q->next[i]=NULL;
    return q;
}
int build(node *T,char *s) //�����ֵ���
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
           tag=1;  // �������½ڵ�
       }
       q=q->next[k];
       if(q->count) //�����˽����Ľڵ�
             return 0;
   }
   q->count=1; //��ǽ����Ľڵ�
   if(!tag)  return 0;
   return 1;
}
int del(node *p)  //�ͷ��ֵ����ռ䣬����ռ�ÿռ�̫��
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
typedef struct node //�ڵ�Ľṹ��
{
    bool end;//�����ı�־
    int  a[10];
}node;
node phonelist[100000];
int x;
int flag;
void Init()
{
    flag=1;
    x=0; //��ʼλ�ã�
    for(int i=0;i<100000;i++)
    {
        phonelist[i].end=false;
        for(int j=0;j<10;j++)
            phonelist[i].a[j]=-1;
    }
}
int build(char *s) //�����ֵ���
{
    int k,now=0,tag=0;// ��ʼλ��
    int len=strlen(s);
    for(int i=0;i<len;i++)
   {
       k=s[i]-'0';
       if(phonelist[now].a[k]==-1)
       {
           tag=1;//˵������һ���µ�λ��
           phonelist[now].a[k]=++x; //��һ��λ��
           now=x;
       }
       else
       {
          now=phonelist[now].a[k];
          if(phonelist[now].end)
            return 0;  //���ʵĽ�����־
       }
   }
    phonelist[now].end=true; //��ǽ����Ľڵ�
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
    node(){  //���캯���������ʼ������
        memset(next,NULL,sizeof(next));
        end=0;  //end=0��ʾһ��ڵ㣬end=1��־һ���绰�ŵĽ���
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
            flag=1;   //��ǽ�����һ���½ڵ�
        }
        p=p->next[k];
        if(p->end) return 0; //����������־���򷵻�0
    }
    p->end=1;  //һ���绰�ŵĽ�����־
    if(!flag) return 0;//�ַ����������δ�����½��ڵ�Ĳ���������0
    return 1;
}
int del(node *p)  //�ͷ��ֵ����ռ䣬����ռ�ÿռ�̫��
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
            if(flag) flag=insert(s);//������ֹ�������������ٽ��в������
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
