#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t,n,a,b;
    ll ans,pos,sum,temp;
    ll len[200],dp[20000];
    cin>> t;
    while(t--)
    {
        pos=0,ans=0,sum=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            if(b==2) ans=ans+a;
            else
            {
                len[pos++]=a;
            }
        }
        sort(len,len+pos-1);
        for(int i=0; i<pos; i++)
        {
            sum=sum+len[i];
        }
        temp=sum;
        sum=sum/2;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<pos; i++)
        {
            for(int k=sum; k-len[i]>0; k--)
            {
                dp[k]=max(dp[k],dp[k-len[i]]+len[i]);
            }
        }
        ans=ans+max(dp[sum-1],temp-dp[sum-1]);
        cout<<ans<<endl;
    }
    return 0;
}
