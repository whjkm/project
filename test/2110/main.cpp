/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef struct node
{
    ll x,y;
} node;
node star[120];
int main()
{
    int t,n,count,i,j,k;
    ll a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        for (i=0; i<n; i++)
        {
            cin >> star[i].x >> star[i].y;
        }
        for(i=0; i<n-2; i++)
        {
            for(j=i+1; i<n-1; j++)
            {
                for(k=j+1; k<n; k++)
                {
                    a=(star[i].x-star[j].x)*(star[i].x-star[j].x)+(star[i].y-star[j].y)*(star[i].y-star[j].y);
                    b=(star[i].x-star[k].x)*(star[i].x-star[k].x)+(star[i].y-star[k].y)*(star[i].y-star[k].y);
                    c=(star[k].x-star[j].x)*(star[k].x-star[j].x)+(star[k].y-star[j].y)*(star[k].y-star[j].y);
                    if(a+b>c && a+c>b && b+c>a)
                    {
                        count++;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct Point
{
    double x,y;
}Point;
Point point[160];
int main()
{
    int ans, t, i, j, k, n;
    double a,b,c;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i=0; i<n; i++)
        {
            cin >> point[i].x >> point[i].y;
        }
        ans = 0;
        for (i=0; i<n-2; i++)
        {
            for (j=i+1; j<n-1; j++)
            {
                for (k=j+1; k<n; k++)
                {
                    a = (point[i].x-point[j].x)*(point[i].x-point[j].x) + (point[i].y-point[j].y)*(point[i].y-point[j].y);
                    b = (point[i].x-point[k].x)*(point[i].x-point[k].x) + (point[i].y-point[k].y)*(point[i].y-point[k].y);
                    c = (point[k].x-point[j].x)*(point[k].x-point[j].x) + (point[k].y-point[j].y)*(point[k].y-point[j].y);

                    if (a+b>c && a+c>b && c+b>a)
                    {
                        ans++;
                    }

                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
