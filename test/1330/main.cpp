#include <cstdio>
using namespace std;
char s[5][20],c[5][4];
int main()
{
    int n,i,j,k,x;
    scanf("%d",&n);
    for(i=0;i<5;i++)
        scanf("%s",s[i]);
    for(k=0;k<n;k++)
    {
        for(i=0;i<5;i++)
            for(j=k*4,x=0;j<(k+1)*4&&x<4;j++,x++)
            c[i][x]=s[i][j];
        for(i=0;i<5;i++)
        if(c[i][1]=='*'&&i==4)  printf("1");
        if(c[1][0]=='.'&&c[3][0]=='*') printf("2");
        if(c[0][0]=='*'&&s[1][0]=='.'&&s[3][0]=='.') printf("3");
    }
    return 0;
}
