/*#include<string.h>
#include <stdio.h>
int s[1000001]={0},q[1000001]={0};
void change(int s[],int q[],int N)
{
    int i,sum=0;
    for(i=0;i<N;i++)
    {
         sum+=s[i];
         q[i]=sum;
    }
}
int main()
{
   int M,N,i,m,n,I,A;
   char x[5];
   scanf("%d%d",&N,&M);
   for(i=0;i<N;i++)
    scanf("%d",&s[i]);
    change(s,q,N);
   while(M--)
   {
       memset(x,0,sizeof(x));
       scanf("%s",x);
       if(strcmp(x,"QUERY")==0)
       {
           scanf("%d%d",&m,&n);
           printf("%d\n",q[n-1]-q[m-2]);
       }
       if(strcmp(x,"ADD")==0)
       {
          scanf("%d%d",&I,&A);
          s[I-1]=s[I-1]+A;
           change(s,q,N);
       }
   }
    return 0;
}
*/
#include<string.h>
#include <stdio.h>
int s[1000001]={0},q[1000001]={0};
int lowbit(int i)
{
    return i&(-i);
}
void creat(int s[],int q[],int N)
{
    int i,j;
    for(i=1;i<=N;i++)
    for(j=(i-lowbit(i)+1);j<=i;j++)
    {
        q[i]+=s[j];
    }
}
int sum(int i)
{
    int temp=0;
    while(i>0)
    {
        temp+=q[i];
        i-=lowbit(i);
    }
    return temp;
}
void add(int i,int temp,int N)
{
    while(i<=N)
    {
        q[i]+=temp;
        i+=lowbit(i);
    }
}
int main()
{
   int M,N,i,m,n,I,A;
   char x[5];
   scanf("%d%d",&N,&M);
   for(i=1;i<=N;i++)
    scanf("%d",&s[i]);
    creat(s,q,N);
   while(M--)
   {
       memset(x,0,sizeof(x));
       scanf("%s",x);
       if(strcmp(x,"QUERY")==0)
       {
           scanf("%d%d",&m,&n);
           printf("%d\n",(sum(n)-sum(m-1)));
       }
       if(strcmp(x,"ADD")==0)
       {
          scanf("%d%d",&I,&A);
          add(I,A,N);
       }
   }
    return 0;
}

