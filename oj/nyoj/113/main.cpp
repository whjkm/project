/*#include<stdio.h>
#include<string.h>
int main()
{
    char s[1002];
    int i,l;
    while(gets(s))
    {
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u')
            {
                s[i]='w';
                s[i+1]='e';
                s[i+2]='#';
            }
        }
        for(i=0;i<l;i++)
            if(s[i]!='#')
             putchar(s[i]);
    }
    printf("\n");
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1002];
    int i,j,l;
    while(gets(s))
    {
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u')
            {
                s[i]='w';
                s[i+1]='e';
                for(j=i+2;j<l;j++)
                    s[j]=s[j+1];
            }
        }
     puts(s);
    }
    return 0;
}
