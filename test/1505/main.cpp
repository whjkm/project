#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n,len,count,flag,k=1;
    char s[32];
    int a[26];
    while(scanf("%d",&n)!=EOF)
    {
       count=0;
       while(n--)
        {
            flag=1;
            memset(a,0,sizeof(a));
            scanf("%s",s);
            len=strlen(s);
            for(int i=0; i<len; i++)
            {
                a[s[i]-'a']++;
            }
            for(int i=0; i<26; i++)
            {
                for(int j=i+1; j<26; j++)
                {
                    if(a[i]==a[j]&&a[i]!=0)
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1&&len!=1)
            {
                count++;
            }
        }
        printf("Case %d: %d\n",k++,count);
    }
    return 0;
}
