#include <stdio.h>
int main()
{
    char a[20];
    double num ,money,sum=0;
    while(scanf("%s%lf%lf",a,&num,&money)!=EOF)
        sum+=num*money;
        printf("%0.1lf",sum);
    return 0;
}
