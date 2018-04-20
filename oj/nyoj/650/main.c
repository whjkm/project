#include <stdio.h>
int main()
{
    int n,a[100],sum,i;
    while(scanf("%d",&n)&&n!=0)
        {
            sum=0;
    for(i=0;i<n;i++)
           scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        sum+=a[i]*a[i];
    printf("%d\n",sum);
        }
    return 0;
}

#include<stdio.h>
main()
{
	int n,i,j,k;
	while(scanf("%d",&n),n)
	{
		j=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			j+=k*k;
		}
		printf("%d\n",j);
	}
}
