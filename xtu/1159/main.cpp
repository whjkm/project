#include<stdio.h>
typedef struct node
{
__int64 v;
int num;
int flag;
int l,r;
}node;
node man[400000];
int t;
int resu[100000],rt;
void build(int l,int r,int p)
{
  man[p].v=0;//喜欢度
  man[p].num=0;
  man[p].flag=1;
  man[p].l=l;
  man[p].r=r;
  if(l==r){ return; }
  int mid=(l+r)/2;
  build(l,mid,2*p);
  build(mid+1,r,2*p+1);
}
void update(int p)   //与2个子节点比较，取好感度最大的，往上传到根节点
{                           //相等的就取num最大的
   if(((man[p].v<man[2*p].v)||(man[p].v==man[2*p].v&&man[p].num<man[2*p].num))&&man[2*p].flag )
      {
          man[p].v=man[2*p].v;
          man[p].num=man[2*p].num;
      }
   if(((man[p].v<man[2*p+1].v)||(man[p].v==man[2*p+1].v&&man[p].num<man[2*p+1].num))&&man[2*p+1].flag)
      {
          man[p].v=man[2*p+1].v;
          man[p].num=man[2*p+1].num;
      }
}
void insert(int l,int r,__int64 v,int num,int p,int temp) //前面2个参数写了没使用。
{
  if(man[p].l==man[p].r)
  {
   if(temp)
    {
        man[p].v+=v;
       if(man[p].v<0)
        man[p].v=0;
       man[p].num=num;
    }
   else
    man[p].flag=0;
    //man[p].num=num;
    return ;
  }
  man[p].v=0;            //每次插入都把中途的最值清除，这样就可以重新从下面往上传最大的
  man[p].num=0;       //
  int mid=(l+r)/2;
  if(num<=man[2*p].r)
  {
     insert(l,r,v,num,2*p,temp);
  }
  else
  if(num>=man[2*p+1].l)
  {
     insert(l,r,v,num,2*p+1,temp);
  }
  update(p);  //这个地方更新最值
}
int main()
{
int T;
while(scanf("%d",&T)&&T)
{
  t=1;
  rt=0;
  build(1,T,1);
  for(int i=0;i<T;i++)
          {  char ctr[10];
             __int64 x,y;
             scanf("%s",ctr);
             if(ctr[0]=='N')
             {
                  scanf("%I64d",&x);
                  insert(0,0,x,t++,1,1);
             }
             else
             if(ctr[0]=='I')
             {
                  scanf("%I64d%I64d",&x,&y);
                  insert(0,0,y,x,1,1);
             }
             else
             if(ctr[0]=='D')
             {
                  scanf("%I64d%I64d",&x,&y);
                  insert(0,0,-y,x,1,1);
             }
             else
             if(ctr[0]=='E')
             {
                  scanf("%I64d",&x);
                  insert(0,0,0,x,1,0);
             }
             else
             if(ctr[0]=='S')
             {
                  resu[rt++]=man[1].num;

             }
          }
          printf("%d",resu[0]);
          for(int i=1;i<rt;i++)
            printf(" %d",resu[i]);
          printf("\n");

}
}



#include<cstdio>
const int maxn=100000+100;
struct node
{
    long long v;
    int num;
    int flag;
    int r,l;
}tree[4*maxn];
int resu[100000];
void build(int root,int l,int r)
{
    tree[root].v=0;
    tree[root].num=0;
    tree[root].l=l;
    tree[root].r=r;
    if(l==r) {return;}
    int mid=(l+r)/2;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
}
void update(int root)
{
    if(((tree[root].v<tree[2*root].v)||(tree[root].v==tree[2*root].v&&tree[root].num<tree[2*root].num))
        &&tree[2*root].flag)
    {
        tree[root].v=tree[2*root].v;
        tree[root].num=tree[2*root].num;
    }
    if(((tree[root].v<tree[2*root+1].v)||(tree[root].v==tree[2*root+1].v&&tree[root].num<tree[2*root+1].num))
        &&tree[2*root+1].flag)
        {
             tree[root].v=tree[2*root+1].v;
            tree[root].num=tree[2*root+1].num;
        }
}
void insert(int root,int num,long long v,int temp)
{
    if(tree[root].l==tree[root].r)
    {
        if(temp)
        {
            tree[root].v+=v;
            if(tree[root].v<0)
                tree[root].v=0;
             tree[root].num=num;
        }
        else
            tree[root].flag=0;
        return ;
    }
    tree[root].v=0;
    tree[root].num=0;
    if(num<=tree[2*root].r)
    {
        insert(2*root,num,v,temp);
    }
    else if(num>=tree[2*root+1].l)
    {
        insert(2*root+1,num,v,temp);
    }
    update(root);
}
int main()
{
   int N;
   int t,rt;
   char op[2];
   long long x,y;
   while(scanf("%d",&N)!=EOF&&N!=0)
   {
       t=1;
       rt=0;
       build(1,1,N);
       for(int i=0;i<N;i++)
       {
           scanf("%s",op);
           switch(op[0])
                  {
                     case 'N':
                     scanf("%I64d",&x);
                     insert(x,t++,1,1);
                     break;
                     case 'I':
                     scanf("%I64d%I64d",&x,&y);
                     insert(y,x,1,1);
                     break;
                     case 'D':
                     scanf("%I64d%I64d",&x,&y);
                     insert(-y,x,1,1);
                     break;
                     case 'E':
                     scanf("%I64d%I64d",&x,&y);
                     insert(0,x,1,0);
                     break;
                     case 'S':
                     resu[rt++]=tree[1].num;
                     break;
                  }
            printf("%d",resu[0]);
          for(int i=1;i<rt;i++)
            printf(" %d",resu[i]);
          printf("\n");
       }
   }
}
