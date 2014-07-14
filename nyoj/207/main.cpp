#include <stdio.h>
#define MAXN 10000
struct node
{
    int father;
    int relation;
};
node s[MAXN];
int find(int x)
{
    int temp;
    if(x==s[x].father)
        return x;
    temp=s[x].father;
    s[x].father=find(temp);
    s[x].relation=(s[x].relation+s[temp].relation)%3;
    return s[x].father;
}
int main()
{
   int n,k,d,x,y,i,sum=0;
   int root1,root2;
   scanf("%d%d",&n,&k);
   for(i=0;i<n;i++)
   {
       s[i].father=i;
       s[i].relation=0;
   }
   for(i=0;i<k;i++)
   {
       scanf("%d%d%d",&d,&x,&y);
       if(x>n||y>n)
       {
           sum++;
           continue;
       }
       if(d==2&&x==y)
       {
             sum++;
             continue;
       }
       root1=find(x);
       root2=find(y);
       if(root1!=root2)
       {
           s[root2].father=root1;
           s[root2].relation=(3+(d-1)+s[x].relation-s[y].relation)%3;
       }
       else
       {
           if(d==1&&s[x].relation!=s[y].relation)
           {
             sum++;
             continue;
           }
           if(d==2&&((3-s[x].relation+s[y].relation)%3!=d-1))
           {
                sum++;
                continue;
           }
       }
   }
   printf("%d\n",sum);
    return 0;
}
