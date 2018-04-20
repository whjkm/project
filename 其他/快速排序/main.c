#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 20
int creatdata(int arr[],int n,int min,int max)//生成不重复随机数
{
    int i,j,flag;
    srand(time(NULL));
    if((max-min+1)<n) return 0;
    for(i=0;i<n;i++)
    {
        do
        {
            arr[i]=(max-min+1)*rand()/(RAND_MAX+1)+min;
            flag=0;
            for(j=0;j<i;j++)
            {
                if(arr[i]==arr[j])
                    flag=1;
            }
        }
        while(flag);
    }
    return 1;
}
int division(int a[],int left,int right)//分割函数
{
    int base=a[left];
    while(left<right)
    {
        while(left<right&&a[right]>base)
            --right;
        a[left]=a[right];
        while(left<right&&a[left]<base)
            ++left;
        a[right]=a[left];
    }
    a[left]=base;
    return left;
}
void quicksort(int a[],int left,int right)
{
    int i;
    if(left<right)
    {
        i=division(a,left,right);
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
    }
}
int main()
{
   int i,a[ARRAYLEN];
   for(i=0;i<ARRAYLEN;i++)
    a[i]=0;
   if(!creatdata(a,ARRAYLEN,1,200))
   {
       printf("生成随机数不成功！\n");
       getch();
       return 1;
   }
   printf("原数据：");
   for(i=0;i<ARRAYLEN;i++)
    printf("%d ",a[i]);
   printf("\n");
   quicksort(a,0,ARRAYLEN-1);
   printf("排序后：");
   for(i=0;i<ARRAYLEN;i++)
    printf("%d ",a[i]);
   printf("\n");
   getch();
    return 0;
}
