#include <stdio.h>
int a[1001];
int find(int x)
{
    while(x!=a[x])
        x=a[x];
    return x;
}
void merge(int x,int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx!=fy)
        a[fx]=fy;
}
int main()
{
  int N,M,i,x,y,cnt;
  while(scanf("%d%d",&N,&M)!=EOF&&N!=0)
  {
    for(i=1;i<=N;i++)
          a[i]=i;
      for(i=0;i<M;i++)
        {
            scanf("%d%d",&x,&y);
             merge(x,y);
        }
     for(cnt=0,i=1;i<=N;i++)
        if(a[i]==i)
          cnt++;
    printf("%d\n",cnt-1);
  }
    return 0;
}

/*#include<stdio.h>
#include<string.h>
#define MAX 1005
int parent[MAX],N,M;
int find(int r)
{
int p=r;
while(parent[p]>0) p=parent[p];
while(r!=p)
{int temp=parent[r];parent[r]=p;r=temp; }
return p;
}
void unionn(int r1,int r2)
{
 r1=find(r1);r2=find(r2);
 if(r1!=r2)
 {
  if(parent[r1]<parent[r2])
   {parent[r1]+=parent[r2];parent[r2]=r1; }
  else
   {parent[r2]+=parent[r1];parent[r1]=r2; }
 }
}

int main()
{

 while(scanf("%d",&N)&&N)
 {
 memset(parent,-1,sizeof(parent));
 scanf("%d",&M);
 for(int i=0;i<M;i++)
 {int x,y;
 scanf("%d%d",&x,&y);
 unionn(x,y);
 }
 int contect=0;
 for(int i=1;i<=N;i++)
    if(parent[i]<=-1)
       contect++;
 if(contect<=1)
   printf("0\n");
 else
   printf("%d\n",contect-1);

 }

return 0;
}
*/
