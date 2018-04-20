/*#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char str[100];
    while(~scanf("%s", str)) {
        int ans = 0;
        for(int i = 0; str[i]; i++) {
            if(str[i] >= '0' && str[i] <= '9') {
                ans += str[i] - '0';
            }
        }
        printf("%d\n", ans);
    }
}
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        int sum=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]>='0' && s[i] <='9')
                sum+=s[i]-'0';
        }
        printf("%d\n",sum);
    }
}
