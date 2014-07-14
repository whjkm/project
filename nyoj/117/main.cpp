/*#include <stdio.h>
int a[1000002],temp[1000002];
long long sum;
void mergearray(int a[],int first,int mid,int last,int temp[])
{
    int i=first,j=mid+1;
    int m=mid,n=last;
    int k=0,s=mid-first+1;
    while(i<=m&&j<=n)
    {
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else
        {
            temp[k++]=a[j++];
            sum+=(s-i+first);
        }
    }
    while(i<=m)
    temp[k++]=a[i++];
    while(j<=n)
    temp[k++]=a[j++];
    for(i=0;i<k;i++)
     a[first+i]=temp[i];
}
void sort(int a[],int first,int last)
{
    int mid;
    if(first<last)
    {
         mid=(first+last)/2;
         sort(a,first,mid);
         sort(a,mid+1,last);
         mergearray(a,first,mid,last,temp);
    }
}
int main()
{
   int t,n,i;
   scanf("%d",&t);
   while(t--)
   {
       sum=0;
       scanf("%d",&n);
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       sort(a,0,n-1);
       printf("%lld\n",sum);
   }
    return 0;
}
*/


#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAXN 1000001
//#define lowbit(x) x&(-x)
using namespace std;
long long c[MAXN],a[MAXN];
struct node
{
    int x;
    int id;
}Ai[MAXN];
int lowbit(int x)
{
    return x&(-x);
}
bool cmp(node n,node m)
{
    if(n.x!=m.x)
        return n.x<m.x;
    else
        return n.id<m.id;
}
void add(int x)
{
    while(x<MAXN)
    {
        c[x]+=1;
        x+=lowbit(x);
    }
}
int Sum(int x)
{
    int temp=0;
    while(x>0)
    {
        temp+=c[x];
        x-=lowbit(x);
    }
    return temp;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        long long sum=0;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
           {
               scanf("%lld",Ai[i].x);
                  Ai[i].id=i;
           }
           sort(Ai,Ai+n,cmp);
        for(int i=0;i<n;i++)
            a[Ai[i].id]=i;
        for(int i=0;i<n;i++)
        {
            add(a[i]);
            sum+=(i-Sum(a[i]));
        }
        printf("%lld\n",sum);
    }
    return 0;
}




/*#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 1000000
long long c[N+1],aaa[N+1];
struct sb
{
	int x;
	int y;
}yi[N+1];
bool cmp(struct sb t1,struct sb t2)
{
    if(t1.x!=t2.x)
	   return t1.x<t2.x;
    else
       return t1.y<t2.y;
}
int lowbit (int a)
{
	return a&(-a);
}
void add(int a)
{
	while(a<N+1)
	{
		c[a]+=1;
		a+=lowbit(a);
	}
}
int Sum(int a)
{
	int SUM=0;
	while(a>0)
	{
		SUM+=c[a];
		a-=lowbit(a);
	}
	return SUM;
}
int main()
{
	int a,b,n,m;
	scanf("%d",&n);
	while(n--)
	{
		long long sum=0;
		memset(c,0,sizeof(c));
		scanf("%d",&m);
		for(a=1;a<=m;a++)
		{
			scanf("%lld",&yi[a].x);
			yi[a].y=a;
		}
        std::sort(yi+1,yi+m+1,cmp);//ÀëÉ¢»¯¡£¡£¡£
		for(a=1;a<=m;a++)
			aaa[yi[a].y]=a;
		for(a=1;a<=m;a++)
		{
		    add(aaa[a]);
			sum+=(a-1-Sum(aaa[a]-1));

		}
		printf("%lld\n",sum);

	}
}
*/
