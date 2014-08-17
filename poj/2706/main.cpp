/*#include <cstdio>
#include <cstring>
#include <cmath>
const int maxn=125;
void mutiply(int *a,int *b)
{
    int i,j;
    int carry;
    int temp;
    int c[maxn];
    memset(c,0,sizeof(c));
    for(i=0;i<maxn;i++)
    {
        carry=0;
        for(j=0;j<maxn;j++)
        {
            temp=c[i+j]+a[i]*b[j]+carry;
            c[i+j]=temp%10000;
            carry=temp/10000;
        }
    }
    memcpy(a,c,maxn*sizeof(int));
}
int main()
{
    int p;
    int pow[maxn];
    int result[maxn];
    scanf("%d",&p);
    printf("%d\n",(int)(p*log10(2))+1); //计算位数
    pow[0]=2;
    result[0]=1;
    for(int i=1;i<maxn;i++)
    {
        pow[i]=0;
        result[i]=0;
    }
    while(p>0)
    {
        if(p&1)
            mutiply(pow,result);
        p>>=1;
        mutiply(pow,pow);
    }
    result[0]--;
    for(int i=maxn-1;i>=0;i--)
    {
        if (i%25==12)
            printf("%02d\n%02d", result[i]/100, result[i]%100);
        else {
                printf("%04d", result[i]);
        if (i%25==0)
            printf("\n");
        }
    }
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define N 100   //压5位
using namespace std;
int ans[N];
void  mult(int t)
{
  int i,temp,last=0;
      for ( i=N-1; i>=0; i--)
    {
        temp=(ans[i]<<t)+last;   //乘2^t，加进位
        last=temp/100000;
        ans[i]=temp-last*100000;  //temp%100000
    }
}
void output()
{
   int i;
   for(i=1;i<=N;i++)
   {     printf("%05d",ans[i-1]);
        if (i%10==0)cout<<endl;
   }
}
int main()
{
  int P,times;
  while(cin>>P)
  {
      memset(ans,0,sizeof(ans));
      ans[N-1]=1;
      cout<<(int)(P*log10(2)+1)<<endl;
      times=P/14;
      while(times--)
          mult(14);
       mult(P%14);
       --ans[99];
      output();
  }
return 0;
}
