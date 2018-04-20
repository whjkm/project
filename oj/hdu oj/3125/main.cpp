#include <cstdio>
#include <cstring>
using namespace std;
char s[55];
int main()
{
    int t,len,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        if(s[0]==47|| s[0]==92)
        {
            printf("It's a path in Unix-like systems!\n");
            for(i=0;i<len;i++)
                if(s[i]==92)
                   s[i]=47;
        }
        for(i=0;i<len;i++)
        {
            if((s[i]==':')&&(s[i+1]==47 || s[i+1]==92)&&(s[i+2]==47 ||s[i+2]==92))
            {
                printf("It's a URL!\n");
                for(i=0;i<len;i++)
                    if(s[i]==92)
                    s[i]=47;
            }
            if((s[i]==':')&&(s[i+1]==47 || s[i+1]==92)&&(s[i+2]!=47 ||s[i+2]!=92))
            {
                printf("It's a path in Windows system!\n");
                for(i=0;i<len;i++)
                    if(s[i]==47)
                      s[i]=92;
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
