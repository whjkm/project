/*#include<stdio.h>
#include<string.h>
char s[301],b[4];
int n=strlen("你");
int main()
{
    int i,j;
    while(scanf("%s",s)&&strcmp(s,"0"))
    {
        for(i=0;i<strlen(s);)
        {
            for(j=0;j<n;j++)
                b[j]=s[i+j];
            b[j]='\0';
            if(!strcmp(b,"你"))
            {
                printf("我");
                i+=n;
            }
            else if(!strcmp(b,"我"))
            {
                printf("你");
                i+=n;
            }
            else
            {
                printf("%c",s[i]);
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}
*/

#include<string>
#include<iostream>
using namespace std;
int main()
{
    string str,model="我";
    int l=model.size(),i;
    while(cin>>str,str!="0")
    {
        for(i=0;i<str.size();i++)
        {
            if(str.substr(i,l)=="你")
                str.replace(i,l,"我");
            else if(str.substr(i,l)=="我")
              str.replace(i,l,"你");
        }
        cout<<str<<endl;
    }
    return 0;
}
