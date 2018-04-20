#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        n++;
        while(n%2==0)
        {
            n=n/2;
        }
        if(n==1)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
