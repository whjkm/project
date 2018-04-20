/*#include <stdio.h>
int main()
{
    int n,m,count,i;
    int num[4]={1,3,7,8};
    scanf("%d",&n);
    while(n--)
    {
        count=0;
        scanf("%d",&m);
        for(i=3;i>=0;i--)
        {
            if(m-num[i]>=0)
            {
                count++;
                if(m==0)
                 break;
                m=m-num[i];
            }
        }
        if(count%2==0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
*/
#include<stdio.h>
int main()
{
    int num[16]={1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1};
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",num[n%15]);
    }
    return 0;
}
