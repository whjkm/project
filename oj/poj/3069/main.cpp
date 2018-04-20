#include <stdio.h>
#include <algorithm>
using namespace std;
int x[1001];
int main()
{
    int r,n;
    while(scanf("%d%d",&r,&n)&&r!=-1&&n!=-1)
    {
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    sort(x,x+n);
    int i=0,ans=0;
    while(i<n)
    {
        int s=x[i++];
        while(i<n&&x[i]<=s+r) i++;
        int p=x[i-1];
        while(i<n&&x[i]<=p+r) i++;
        ans++;
    }
    printf("%d\n",ans);
    }
    return 0;
}
