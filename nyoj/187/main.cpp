#include <stdio.h>
bool prime[2000001];
void screen()
{
    int i,j;
    for(i=2;i<2000001;i++)
        prime[i]=1;
    for(i=2;i<2000001;i++)
    {
        if(prime[i])
        {
            for(j=i+i;j<2000001;j+=i)
                prime[j]=0;
        }
    }
}
int main()
{
    int n,i;
    screen();
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=2;i<=n;i++)
            if(prime[i]==1)
            printf("%d ",i);
        printf("\n");
    }
    return 0;
}
