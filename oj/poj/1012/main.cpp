//暴力+枚举
#include <cstdio>
#include <cstring>
int main()
{
    int k;
    int ans[20];
    int Joseph[20]={0};
    for(k=1;k<14;k++)
    {
        int m=1;
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=k;i++)
        {
            ans[i]=(ans[i-1]+m-1)%(2*k-i+1); //递推公式
            if(ans[i]<k)
            {
                i=0;
                m++;
            }
        }
        Joseph[k]=m;
    }
  while(scanf("%d",&k)&&k!=0)
   {
       printf("%d\n",Joseph[k]);
   }
   return 0;
}
//直接枚举 0ms
#include <cstdio>
#include <cstring>
int main()
{
    int k;
  int Joseph[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,1245064};
  while(scanf("%d",&k)&&k!=0)
   {
       printf("%d\n",Joseph[k]);
   }
   return 0;
}



#include <cstdio>
#include <cstring>
bool Joseph(int k,int m)
{
    int n=2*k,x=0;
    while(n>k)
    {
        x=(x+m-1)%n;//递推公式，算出当前出局的位置
        if(x<k) //判别条件
            return false;
        n--;
    }
    return true;
}
int main()
{
    int k;
    int result[20]={0};
    for(k=1;k<14;k++)
    {
        for(int i=k+1;;i+=k+1) //对m枚举进行优化
        {
            if(Joseph(k,i)) //m是k+1的倍数或者倍数+1
            {
                result[k]=i;
                break;
            }
            else if(Joseph(k,i+1))
            {
                result[k]=i+1;
                break;
            }
        }
    }
    while(scanf("%d",&k)&&k)
    {
        printf("%d\n",result[k]);
    }
}


