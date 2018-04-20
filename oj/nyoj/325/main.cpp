 #include<stdio.h>
 #include<math.h>
 #include<stdlib.h>
 int dp[100001];
 int main()
 {
     int n,w[25],i,v,tv,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0,v=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            v+=w[i];
        }
        tv=v/2;  //思路：最大差值--》一半总重量为容量的背包最多能装多少重量的西瓜
        for(i=0;i<=tv;i++)
        dp[i]=0;
        for(i=0;i<n;i++)
            for(j=tv;j>=w[i];j--)
        {
            dp[j]=dp[j]>dp[j-w[i]]+w[i]?dp[j]:dp[j-w[i]]+w[i];
        }
        printf("%d\n",abs(v-dp[tv]*2));
    }
     return 0;
 }

