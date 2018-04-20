#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int length1,length2,d;
    char a[1001],b[1001];
    while(scanf("%s%s",a,b)&&a[0]!='0'&&b[0]!='0')
    {
        length1=strlen(a);
        length2=strlen(b);
        if(a[0]=='-'&&b[0]!='-') printf("a<b\n");
        else if(a[0]!='-'&&b[0]=='-') printf("a>b\n");
        else if(a[0]!='-'&&b[0]!='-')
        {
            if(length1>length2)  printf("a>b\n");
            else if(length1<length2)  printf("a<b\n");
            else
            {
                d=strcmp(a,b);
                if(d>0) printf("a>b\n");
                else if(d==0) printf("a==b\n");
                else printf("a<b\n");
            }
        }
        else
        {
             if(length1>length2)  printf("a<b\n");
            else if(length1<length2) printf("a>b\n");
           else
           {
                d=strcmp(a,b);
                if(d>0) printf("a<b\n");
                else if(d==0) printf("a==b\n");
                else printf("a>b\n");
           }
        }
    }
    return 0;
}




 #include<iostream>
 #include<stdio.h>
 #include<string>
 using namespace std;
 int main()
 {
 int m,n,f,d;
 char a[1001],b[1001];
 while(cin>>a>>b)
 {
 m=strlen(a);
 n=strlen(b);
 if(a[0]=='0'&&b[0]=='0')break;
 if(a[0]=='-'&&b[0]!='-') printf("a<b\n");
 else if(a[0]!='-'&&b[0]=='-' )printf("a>b\n");
 else if(a[0]!='-'&&b[0]!='-')
 {
if(m>n) printf("a>b\n");
 else if(m<n) printf("a<b\n");
 else
 {
 d=strcmp(a,b);
 if(d>0)printf("a>b\n");
 else if(d==0) printf("a==b\n");
 else printf("a<b\n");
 }
 }
 else
 {
 if(m<n) printf("a>b\n");
 else if(m>n) printf("a<b\n");
 else
 {
 d=strcmp(a,b);
 if(d>0)printf("a<b\n");
 else if(d==0) printf("a==b\n");
else printf("a>b\n");
 }
 }
 }
 return 0;
 }
