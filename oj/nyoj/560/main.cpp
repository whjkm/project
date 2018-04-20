#include <cstdio>
#include <cstring>
using namespace std;
char map[10][10],s[10][10];
int x1,y1,x2,y2,n,m;
void get_big()
{
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]=='*')
            {
                x1=i;
                y1=j;
                flag=false;
                break;
            }
        }
         if(!flag) break;
    }
}
void get_small()
{
    bool flag=true;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]=='*')
            {
                x2=i;
                y2=j;
                flag=false;
                break;
            }
        }
        if(!flag) break;
    }
}
bool judge()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(s[i][j]=='*')
        return false;
    return true;
}
int sovle()
{
    get_small();
    while(!judge())
    {
        get_big();
        for(int i=x2;i<m;i++)
            for(int j=0;j<m;j++)
        {
            if(map[i][j]=='*')
            {
                 if(s[x1+i-x2][y1+j-y2]=='*')
                        s[x1+i-x2][y1+j-y2]='.';
                else
                    return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        for(i=0;i<n;i++)
          scanf("%s",s[i]);
        for(j=0;j<m;j++)
          scanf("%s",map[j]);
        printf("%d\n",sovle());
    }
    return 0;
}
