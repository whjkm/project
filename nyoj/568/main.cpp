#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int a[maxn];
int index[maxn];
struct node
{
    int l,r,val;
}t[maxn*3];
void build(int root,int l,int r)
{
    t[root].l=l;
    t[root].r=r;
    if(l==r)
    {
        t[root].val=a[l];
        return ;
    }
    int m=(l+r)>>1;
    build(root<<1,l,m);
    build(root<<1|1,m+1,r);
    t[root].val=min(t[root<<1].val,t[root<<1|1].val);
}
void update(int root,int l,int r,int val)
{
    if(t[root].l==l && t[root].r==r)
    {
        t[root].val=val;
        return ;
    }
    int m=(t[root].l+t[root].r)>>1;
    if(m>=r) update(root<<1,l,r,val);
    else
        update(root<<1|1,l,r,val);
    t[root].val=min(t[root<<1].val,t[root<<1|1].val);
}
int query(int root,int l,int r)
{
    if(t[root].l==l && t[root].r==r)
        return t[root].val;
    int m=(t[root].l+t[root].r)>>1;
    if(m>=r) return query(root<<1,l,r);
    else if(l>m) return query(root<<1|1,l,r);
    else
        return min(query(root<<1,l,m),query(root<<1|1,m+1,r));
}
int main()
{
     int n,q,l,r;
     char s[100];
     scanf("%d%d",&n,&q);
     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
     build(1,1,n);
     for(int i=0;i<q;i++)
     {
         scanf("%s",s);
         if(s[0]=='q')
         {
            sscanf(s+5,"(%d,%d)",&l,&r);
            printf("%d\n",query(1,l,r));
         }
         else
         {
             int k,l=0,t=0;
             for(k=0;s[k];k++)  if(s[k]=='(') break;
             for(int j=k+1;s[j];j++)
             {
                 while(s[j]!=',' && s[j]!=')')
                 {
                     t=t*10+s[j]-'0';
                     j++;
                 }
                 index[l++]=t;
                 t=0;
             }
            t=a[index[0]];
            for(int k=0;k<l;k++)
            {
                if(k==0) update(1,index[l-1],index[l-1],a[index[0]]);
                else
                update(1,index[k-1],index[k-1], a[index[k]]) ;
            }
             for(int k=0;k<l-1;k++)
                a[ index[k]]=a[index[k+1]];
            a[index[l-1]]=t;
         }
     }
    return 0;
}
