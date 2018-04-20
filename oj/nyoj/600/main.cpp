/*#include <stdio.h>
using namespace std;
int x[100001],y[100001];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&m,&n);
       for(i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]);
       for(i=0;i<m;i++)
       {
           scanf("%d",&q);

       }
   }
    return 0;
}
*/
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define lowbit(a) a&(-a)
#define MAX 400005
using namespace std;
int n,m,num[MAX],N,deal[MAX];
typedef struct data
{
int num;
int flag;
}data;
data a[MAX];
int cmp(data a,data b)
{
if(a.num<b.num)
return 1;
return 0;
}
void updata(int i,int a)
{
 while(i<=N)
 {
 num[i]+=a;
 i+=lowbit(i);
 }
}
int getnum(int i)
{int sum=0;
while(i>0)
{
 sum+=num[i];
 i-=lowbit(i);
}
return sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    memset(num,0,sizeof(num));
    scanf("%d%d",&n,&m);
    N=2*n+m;
    for(int i=0;i<N;i++)
    {
    int t;
    scanf("%d",&t);
    a[i].flag=i;
    a[i].num=t;
    }
    sort(a,a+N,cmp);
    int temp=a[0].num,coun=1;
    for(int i=0;i<N;i++)
    {
      if(temp!=a[i].num)
      {
          temp=a[i].num;
          deal[a[i].flag]=++coun;
      }
      else
      {
          deal[a[i].flag]=coun;
      }
    } //离散化
    for(int i=0;i<2*n;i+=2)
    {
    updata(deal[i],1);//插线
    updata(deal[i+1]+1,-1);//去线
    }
    for(int i=2*n;i<N;i++)
    {
     printf("%d\n",getnum(deal[i]));
    }

}

return 0;}
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowbit(a) a&-a
#define MaxN 300005
int m[MaxN], real[MaxN], N;
typedef struct
{
    int val, pos;
}S;

S mm[MaxN];

bool cmp(S a, S b)
{
    if(a.val==b.val) return a.pos>b.pos;
    return a.val<b.val;
}

void Add(int i, int num)
{
    while(i<=N)
    {
        m[i]+=num;
        i+=lowbit(i);
    }
}

int Sum(int i)
{
    int res=0;
    while(i>0)
    {
        res+=m[i];
        i-=lowbit(i);
    }
    return res;
}

int main()
{
	int T, temp, k, n;
	scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        N=2*n+k;
        memset(m,0,sizeof(m));
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&temp);
            mm[i].pos=i;
            mm[i].val=temp;
        }
        sort(mm+1,mm+N+1,cmp);
        int x=0;
        for(int i=1;i<=N;i++)              //离散化+去重
        {
            if( mm[i].val != mm[i-1].val)
                real[mm[i].pos]=++x;
            else
                real[mm[i].pos]=x;
        }
        for(int i=1;i<=2*n;i+=2)            //插线
        {
            Add(real[i],1);
            Add(real[i+1]+1,-1);
        }
        for(int i=2*n+1;i<=N;i++)           //问点
            printf("%d\n",Sum(real[i]));
    }
	return 0;
}
