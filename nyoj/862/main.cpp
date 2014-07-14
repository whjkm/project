#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(char a,char b)
{
    if(a>b)
        return true;
    return false;
}
int main()
{
    int l,i;
    char s[102];
    while(scanf("%s",s)!=EOF)
    {
        int sum=0;
        l=strlen(s);
        sort(s,s+l,cmp);
        for(i=0;i<l;i++)
            sum+=s[i]-'0';
        if(sum%3==0)
            printf("%s\n",s);
        if(sum%3!=0)
        {

        }
        memset(s,0,sizeof(s));
    }
   return 0;
}
