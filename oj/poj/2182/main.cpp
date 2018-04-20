/*#include <stdio.h>
#define N 8002
int num[N],ans[N];
struct segment
{
    int l,r,len;
}s[N];
void build(int root,int l,int r)
{
   s[root].l=l;
   s[root].r=r;
   s[root].len=r-l+1;
   if(l==r)return;
   build(2*root,l,(l+r)/2);
   build(2*root+1,(l+r)/2+1,r);
}
int query(int root,int k)
{
    s[root].len--;
    if(s[root].l==s[root].r) return s[root].l;
    else if(k<=s[2*root].len)
    {return query(2*root,k);}
    else
    {return query(2*root+1,k-s[2*root].len);}
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=2;i<=n;i++)
     scanf("%d",&num[i]);
    num[1]=0;
    build(1,1,n);
    for(int i=n;i>=1;i--)
        ans[i]=query(1,num[i]+1);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
*/
#include <stdio.h>
int main()
{

}
