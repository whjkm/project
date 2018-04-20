#include<stdio.h>
#include<string.h>
#define N 10
int main()
{
    int t,a[N]={0},l,i,j;
    char b[N],c[N]={'O','O','T','T','F','F','S','S','E','N'};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&b);
        l=strlen(b);
        for(i=l-1,j=0;i>=0;i--)
            a[j++]=b[i]-'0';
        for(i=0;i<l;i++)
            printf("%c",c[a[i]]);
        printf("\n");
    }
    return 0;
}
