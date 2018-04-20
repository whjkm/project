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
