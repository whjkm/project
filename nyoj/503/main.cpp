#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double left=0,right=100,x,num,k;
        scanf("%lf",&k);
        while(1)
        {
            x=(left+right)/2;
            num=8*pow(x,4)-7*pow(x,3)+2*pow(x,2)+3*x+6;
            if(x<=0||x>=100)
            {
                printf("No solution!\n");
                break;
            }
            if(fabs(num-k)<=0.0001)
            {
                printf("%.4lf\n",x);
                break;
            }
            if(num>=k)
                right=x;
            else
                left=x;
            x=(left+right)/2;
        }
    }
    return 0;
}
