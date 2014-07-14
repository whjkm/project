#include <iostream>
#include <cstdio>
//#include <cmath>
inline int fabs(int k)
{
    return k<0?-k:k;
}
using namespace std;
//const int maxn=110;
#define maxn 110
int a[maxn];
int main()
{
    int t,n,m,front,rear;
    scanf("%d",&t);
    while(t--)
    {
        int cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        front=0,rear=n;
        a[m]=-a[m];
        while((rear+1)%maxn!=front)
        {
            int k=a[front];
            front=(front+1)%maxn;
            bool print=true;
            for(int i=front;i!=rear;i=(i+1)%maxn)
                if(fabs(k)<fabs(a[i]))
                {
                    print=false;
                    a[rear]=k;
                    rear=(rear+1)%maxn;
                    break;
                }
            if(print)
            {
                ++cnt;
                if(k<0)
                {
                    cout<< cnt <<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
