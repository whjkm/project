/*#include <cstdio>
using namespace std;
const int maxn=1000+5;
int a[maxn],b[maxn];
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)&&n)
    {
        while(scanf("%d",&b[0])&&b[0])
        {
            for(i=1;i<n;i++)
                scanf("%d",&b[i]);
           for(i=1,j=0,k=0;i<=n&&j<n;i++,j++)
           {
               a[j]=i;
               while(a[j]==b[k])
               {
                   if(j>0) j--;
                   else
                   {
                       a[j]=0;
                       j--;
                   }
                   k++;
                   if(j==-1) break;
               }
           }
           if(k==n) printf("Yes\n");
           else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
*/
#include <cstdio>
#include <stack>
using namespace std;
const int maxn=1000+5;
int a[maxn];
int main()
{
    int n,i,k;
    while(scanf("%d",&n)&&n)
    {
        stack<int>s;
        while(scanf("%d",&a[0])&&a[0])
        {
            for(i=1;i<n;i++)
                scanf("%d",&a[i]);
            for(i=1,k=0;i<=n;i++)
            {
                s.push(i);
                while(s.top()==a[k])
                {
                    if(!s.empty()) s.pop();
                    k++;
                    if(s.empty()) break;
                }
            }
            if(k==n) printf("Yes\n");
           else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
