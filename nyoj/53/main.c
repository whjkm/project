#include <stdio.h>
int main()
{
   int n,x,y,a[7],maxs,temp,i;
   scanf("%d",&n);
   while(n--)
   {
       maxs=0;temp=0;
       for(i=0;i<7;i++)
        {
            scanf("%d%d",&x,&y);
            a[i]=x+y;
        if(a[i]>maxs)
        {
            maxs=a[i];
            temp=i+1;
        }
        }
        if(maxs<=8)
            printf("0\n");
        else
            printf("%d\n",temp);
   }
    return 0;
}
