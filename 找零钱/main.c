#include <stdio.h>
#define MAXN 9
int parvalue[MAXN]={10000,5000,2000,1000,500,200,100,50,20,10};
int num[MAXN]={0};
int exchange(int n)
{
    int i;
    for(i=0;i<MAXN;i++)
        if(n>parvalue[i])  break;
       while(n>0&&i<MAXN)
       {
           if(n>=parvalue[i])
            {
                n-=parvalue[i];
                num[i]++;
            }
       else if(n<10&&n>=5)
       {
           num[MAXN-1]++;
           break;
       }
       else i++;
       }
    return 0;
}
int main()
{
    int i;
    float m;
    printf("请输入要找零的金额：");
    scanf("%f",&m);
    exchange((int)100*m);
    printf("\n%.2f元零钱的组成：\n",m);
    for(i=0;i<MAXN;i++)
        if(num[i]>0)
        printf("%6.2f:%d张\n",(float)parvalue[i]/100.0,num[i]);
    getch();
    return 0;
}
