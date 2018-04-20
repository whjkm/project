#include <stdio.h>
#include <string.h>
#define N 12
long long sum[15]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int main()
{
    int n,i,j,id;
    long int m,temp;
    char s[N+1];
    char c[13]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
    scanf("%d",&n);
    while(n--)
    {
        scanf("%ld",&m);
        memset(s,0,sizeof(s));
        strcpy(s,c);
        temp=m-1;
        for(i=0;i<N;i++)
        {
            id=temp/sum[N-i-1];
            printf("%c",s[id]);
            for(j=id;j<N-i;j++)
                s[j]=s[j+1];
            temp-=id*sum[N-i-1];
        }
        printf("\n");
    }
    return 0;
}
