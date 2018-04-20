#include <stdio.h>
int main()
{int n,a[10],i,j,t;
    scanf("%d",&n);
    while(n--)
    {t=0;for(i=0;i<10;i++)scanf("%d",&a[i]);
       for(i=0;i<9;i++)
        for(j=i+1;j<10;j++)
       {if(a[i]<a[j])
            {t=a[i];a[i]=a[j];a[j]=t;}
       }
       printf("%d\n",a[2]);
    }
    return 0;
}

/*#include<cstdio>
int main(){int n;scanf("%d",&n);while(n--){int r,a[4]={0,0,0,0};for(int j=0;j<10;j++){scanf("%d",a);for(int i=0;i<3;i++)a[i+1]<a[i]?r=a[i],a[i]=a[i+1],a[i+1]=r:0;}printf("%d\n",a[1]);}}*/


#include<stdio.h>
#include<algorithm>
int main()
{
	int n,i,a[15];
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<10;i++)
			scanf("%d",&a[i]);
		std::sort(a,a+10);
		printf("%d\n",a[7]);
	}
	return 0;
}
