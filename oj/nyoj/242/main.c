#include <stdio.h>
#define PI 3.1415926
int main()
{
    double v, r;
    while(scanf("%lf",&r)!=EOF)
    {
        v=4.0/3.0*PI*r*r*r;
        printf("%.0lf\n",v);
    }
    return 0;
}
