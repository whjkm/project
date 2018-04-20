/*#include <cstdio>
#include <cstring>
bool judge(int n)
{
     if( !(n % 7) ) return true;
     while(n)
    {
        if( n % 10 == 7 )
            return true;
        n /= 10;
    }
    return false;
}
int main()
{
    int n,m,k,i;
    while(scanf("%d%d%d",&n,&m,&k)&&n&&m&&k)
    {
        int count=0;
        for(i=7;;i++)
        {
            if(judge(i))
            {
                int x=i%(2*n-2);
                if(x==0)
                 x=2*n-2;
                if(x==m || (x>=n && 2*n-x==m ))
                    count++;
                if(count==k)
                    break;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
bool judge(int n)
{
     if( !(n % 7) ) return true;
     while(n)
    {
        if( n % 10 == 7 )
            return true;
        n /= 10;
    }
    return false;
}
int main()
{
    int n,m,k,i;
    while(scanf("%d%d%d",&n,&m,&k)&&n&&m&&k)
    {
        int pos=0,count=0,flag=0;
        for(i=1;i<=n;i++)
        {
            pos++;
            if(i==m)
            {
                if(judge(pos))
                    count++;
                if(count==k)
                {
                   printf("%d\n",pos);
                   break;
                }
            }
            if(i==n)
            {
                i=n-1;
                for(;i>=1;i--)
                {
                    pos++;
                    if(i==m)
                    {
                        if(judge(pos))
                            count++;
                        if(count==k)
                        {
                            flag=1;
                            printf("%d\n",pos);
                            break;
                        }
                    }
                }
             if(flag)  break;
             i=1;
           }
        }
    }
    return 0;
}
