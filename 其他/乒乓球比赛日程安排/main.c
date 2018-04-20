#include <stdio.h>
#define MAXN 64
int a[MAXN+1][MAXN+1]={0};
void gamecal(int k,int n)
{
    int i,j;
    if(n==2)
    {
        a[k][1]=[k];
        a[k][2]=k+1;
        a[k+1][1]=k+1;
        a[k+1][2]=k;
    }else
    {
        gamecal(k,n/2);
        gamecal(k+n/2,n/2);
        for(i=k;i<k+n/2;i++)
        {
            for(j=n/2+1;j<=n;j++)
            {
                a[i][j]=a[i+n/2][j-n/2];
            }
        }
        for(i=k+n/2;i<k+n;i++)
        {
            for(j=n/2+1;j<=n;j++)
            {
                a[i][j]=a[i-n/2][j-n/2];
            }
        }
    }
}
