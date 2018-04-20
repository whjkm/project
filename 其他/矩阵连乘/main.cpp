#include <stdio.h>
#define N 100
void matrixChain (int p[],int m[N+1][N+1],int s[N+1][N+1])
{
    int n=N;
    for (int i=1; i<=n; i++)
        m[i][i]=0;
    for (int r=2; r<=n; r++)
    {
        for (int i=1; i<=n-r+1; i++)
        {
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for (int k=i+1; k<j; k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
void traceback (int i,int j,int s[][N+1])
{
    if (i==j)
    {
        printf ("A%d",i);
    }
    else
    {
        printf ("(");
        traceback (i,s[i][j],s);
        traceback(s[i][j]+1,j,s);
        printf (")");
    }
}
int main ()
{
    int n;
    int q[2*N];
    int p[N+1],flag=1;
    int m[N+1][N+1];
    int s[N+1][N+1];
    printf ("���������ĸ���:");
    scanf ("%d",&n);
    for (int i=0; i<=2*n-1; i++)
    {
        if (i%2==0)
        {
            printf ("***************\n");
            printf ("������A%d����:",(i/2)+1);
        }
        else
        {
            printf ("��***********:");
        }
        scanf ("%d",&q[i]);
    }
    for (int i=1; i<=2*n-2; i++)
    {
        if (i%2!=0&&q[i]!=q[i+1])
        {
            flag=0;
            break;
        }
    }
    for (int j=1; j<=n-1; j++)
    {
        p[j]=q[2*j];
    }
    if (flag!=0)
    {
        p[0]=q[0];
        p[n]=q[2*n-1];
        matrixChain (p,m,s);
        printf ("ʽ������:\n");
        traceback(1,n,s);
        printf ("\n");
        printf ("��С���˴���Ϊ%d\n",m[1][n]);
    }
    else
    {
        printf ("��%d������������!\n",n);
    }
    return 0;
}
