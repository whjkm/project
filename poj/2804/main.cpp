/*#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef struct node //节点的结构体
{
    char eng[12];
    int count; //标记单词是否结束
    struct node * next[26];
}node;
int flag;
void Insert(node *T,char *f,char *e) //插入
{
    node *p,*q;
    p=T;
    int len,k;
    len=strlen(f);
    if(len==0) return ;
    for(int i=0;i<len;i++)
    {
        k=f[i]-'a';
        if(p->next[k]==NULL)
        {
            q=(node*)malloc(sizeof(node)); //增加新节点
            for(int i=0;i<26;i++)
            {
                q->count=0;
                strcpy(q->eng,e);
                q->next[i]=NULL;
            }
            p->next[k]=q;
            p=q;
        }
        else
            p=p->next[k];
    }
    p->count++;
}
void Search(node *T,char *s)//查找
{
     node *q;
     q=T;
     int k,i=0,len;
     int flag=0;
     for(i=0;i<26;i++)
     {
         k=s[i]-'a';
         q=q->next[k];
         if(q==NULL)
        {
            flag=1;
            printf("eh\n");
            break;
        }
         if(q->count>0)
        {
             printf("%s\n",q->eng);
             flag=1;
             break;
        }
     }
}
void Release(node *T)
{
    for(int i=0;i<26;i++)
        if(T->next[i]!=NULL)
            Release(T->next[i]);
        free(T);
}
int main()
{
     freopen("1.txt","r",stdin);
     char english[20],forigen[20];
     node *T;
     T=(node *)malloc(sizeof(node));
     T->count=0;
     for(int i=0;i<26;i++)
        T->next[i]=NULL;
    while(1)
    {
        english[0]=getchar();
        if(english[0]=='\n') break;
        scanf("%s %s",english+1,forigen);
        Insert(T,forigen,english);
        getchar();
    }
    while(scanf("%s",forigen)!=EOF)
    {
        flag=0;
        Search(T,forigen);
    }
    Release(T);
    return 0;
}
*/


/*#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
struct node //节点的结构体
{
    char eng[12];
    char fore[12];
};
node dictionary[maxn];
int cmp(const void *a,const void *b){ //比较函数
    return strcmp(((node *)a)->fore,((node *)b)->fore);
}
int search(const void *a,const void *b){ //二分查找函数
    return strcmp((char *)a,((node *)b)->fore);
}
bool Cmp(node one, node two)
{
    return strcmp(one.fore, two.fore) < 0;
}
int bsearch(char *s,int n)
{
    int mid,start,end;
    start=0;end=n-1;
    int flag=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        flag=strcmp(s,dictionary[mid].fore);
        if(flag==0)
            return mid;
        if(flag<0)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
int main()
{
     //freopen("1.txt","r",stdin);
     char english[30],forigen[20];
     int count=0,flag;
     node *p;
    while(fgets(english,29,stdin)&&english[0]!='\n')
    {
        sscanf(english,"%s%s",dictionary[count].eng,dictionary[count].fore);
        count++;
    }
    qsort(dictionary,count,sizeof(node),cmp);
    sort(dictionary,dictionary+count,Cmp);
    while(scanf("%s",forigen)!=EOF)
    {
        p=NULL;
        p=(node*)bsearch(forigen,dictionary,count,sizeof(node),search);
        if(p)
         printf("%s\n",p->eng);
        else
            printf("eh\n");
        flag=bsearch(forigen,count);
        if(flag!=-1)
        {
            printf("%s\n",dictionary[flag].eng);
        }
        else
            printf("eh\n");
    }
    return 0;
}
*/
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "algorithm"
#include "iostream"
using namespace std;
typedef struct  node
{
      struct node *next[26];
      char   ans[12];
}node;
char arr1[12],arr2[12],str[25];
node *T;
void Diction()
{
     node *q,*p=T;
     int i,j,k,len;
     len=strlen(arr2);
     for(i=0;i<len-1;i++)
     {
          k=arr2[i]-'a';
          if(p->next[k]==NULL){
                q=(node*)malloc(sizeof(node));
                p->next[k]=q;q->ans[0]=0;
                for(j=0;j<26;j++)
                   q->next[j]=NULL;
                p=q;
          }else{
                p=p->next[k];
          }
     }
     k=arr2[i]-'a';
     if(p->next[k]==NULL){
         q=(node*)malloc(sizeof(node));
         p->next[k]=q;strcpy(q->ans,arr1);
           for(j=0;j<26;j++)
              q->next[j]=NULL;
     }else{
           p=p->next[k];
           strcpy(p->ans,arr1);
     }
}
void search()
{
       node *p=T;
       int i,len,k;
       len=strlen(str);
       for(i=0;i<len-1;i++)
       {
              k=str[i]-'a';
              if(p->next[k]==NULL){
                   printf("eh\n");
                   break;
              }else{
                   p=p->next[k];
              }
       }
       if(i==len-1)
       {
             k=str[i]-'a';
             if(p->next[k]==NULL){
                   printf("eh\n");
             }else{
                   p=p->next[k];
                   if(p->ans[0]!=0)
                       puts(p->ans);
                   else
                       printf("eh\n");
             }
       }
}
int main()
{
     freopen("1.txt","r",stdin);
     int i;
     T=(node*)malloc(sizeof(node));
     for(i=0;i<26;i++)
         T->next[i]=NULL;
     while(1)
     {
          gets(str);
          if(strcmp(str,"")==0)
             break;
          sscanf(str,"%s %s",arr1,arr2);
          Diction();
     }
     while(scanf("%s",str)!=EOF)
              search();
         return 0;
}
