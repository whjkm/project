#include<stdio.h>
int main()
{
	int n,k,i,j;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		for(i=k+1;i<=2*k;i++)
            if(k*i%(i-k)==0)
        {
            j=k*i/(i-k);
            printf("1/%d=1/%d+1/%d\n",k,j,i);
        }
	}
	return 0;
}
