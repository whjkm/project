#include <stdio.h>
#include <string.h>
void change(char *s,int n,int m)
{
    char bit[]={"0123456789ABCDEF"};
    int len ;
    if(n==0)
    {
        strcpy(s,"");
        return;
    }
    change(s,n/m,m);
    len=strlen(s);
    s[len]=bit[n%m];
    s[len+1]='\0';
}
int main()
{
    char s[80];
    int i,n,base;
    printf("������ʮ������:");
    scanf("%d",&n);
    printf("������Ҫת��������:");
    scanf("%d",&base);
    change(s,n,base);
    printf("%s\n",s);
    getch();
    return 0;
}

