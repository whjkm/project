/*#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50050;
struct node
{
    int l,r,val;
}t[maxn*3];
int a[maxn];
void build(int root,int l,int r)
{
    int m;
    t[root].l=l;
    t[root].r=r;
    if(l==r)
    {
        t[root].val=a[l];
        return ;
    }
    m=(l+r)/2;
    build(root*2,l,m);
    build(root*2+1,m+1,r);
    t[root].val=t[root*2].val+t[root*2+1].val;
}
int query(int root,int l,int r)
{
    int m;
    if(t[root].l==l && t[root].r==r) return t[root].val;
    m=(t[root].l+t[root].r)/2;
    if(r<=m) return query(root*2,l,r);
    else if(l>m) return query(root*2+1,l,r);
    else return query(root*2,l,m)+query(root*2+1,m+1,r);
}
void update(int root,int id,int num)
{
    if(t[root].l==t[root].r)
    {
        t[root].val+=num;
        return ;
    }
    else
    {
        t[root].val+=num;
        if(id<=t[root*2].r) update(root*2,id,num);
        else update(root*2+1,id,num);
    }
}
int main()
{
    int t,n,i,id,num;
    char s[10];
    int k=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
         build(1,1,n);
         printf("Case %d:\n",k++);
        while(1)
        {

            scanf("%s",s);
            if(strcmp(s,"End")==0) break;
            scanf("%d%d",&id,&num);
            if(strcmp(s,"Query")==0)
            {
                printf("%d\n",query(1,id,num));
            }
            if(strcmp(s,"Add")==0)
            {
                update(1,id,num);
            }
            if(strcmp(s,"Sub")==0)
            {
                update(1,id,-num);
            }
       }
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
const int maxn=50005;
int n,a[maxn];
char s[10];
int lowbit(int i)
{
    return i&(-i);
}
void update(int i,int val)
{
    while(i<=n)
    {
        a[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=a[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    int t,i,val,k=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&val);
            update(i,val);
        }
        printf("Case %d:\n", k++);
        while(scanf("%s",s))
        {
            if(s[0]=='E') break;
            scanf("%d%d",&x,&y);
            if(s[0]=='A') update(x, y);
            else if(s[0]=='S') update(x,-y);
            else
                printf("%d\n", sum(y)-sum(x-1));
        }
    }
}
