#include<stdio.h>
#include<algorithm>
using namespace std;
struct rectangle
{
    int num;
    int l;
    int w;
};
bool cmp(rectangle x,rectangle y)
{
   if(x.num>y.num)
   return false;
  else if(x.num==y.num&&x.l>y.l)
    return false;
  else if(x.num==y.num&&x.l==y.l&&x.w>y.w)
    return false;
return true;
}
int main()
{
   int n,m,temp,i;
   struct rectangle a[1000];
   scanf("%d",&n);
   while(n--)
   {
       temp=0;
       scanf("%d",&m);
       for(i=0;i<m;i++)
      {
          scanf("%d%d%d",&a[i].num,&a[i].l,&a[i].w);
       if(a[i].l<a[i].w)
       {
          temp=a[i].l;
          a[i].l=a[i].w;
          a[i].w=temp;
       }
      }
       sort(a,a+m,cmp);
       for(i=0;i<m;i++)
        if(a[i].num!=a[i+1].num||a[i].l!=a[i+1].l||a[i].w!=a[i+1].w)
            printf("%d %d %d \n",a[i].num,a[i].l,a[i].w);
   }
    return 0;
}
