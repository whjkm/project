#include <stdio.h>
#include <string.h>
#define N 1020
int main()
{
   int num[28]={0},t,i,l,max;
   char a[N];
   scanf("%d",&t);
   while(t--)
   {
       max=0;
       scanf("%s",a);
       l=strlen(a);
       for(i=0;i<l;i++)
        if(a[i]>='a'&&a[i]<='z')
          num[a[i]-'a']++;
          for(i=0;i<=26;i++)
        {
            if(num[i]>num[max])
              max=i;
        }
          printf("%c\n",char(max+'a'));
   }
    return 0;
}
/*#include<iostream>
 #include<string.h>
 using namespace std;
 int main()
 {
 int n;
 cin>>n;
 while(n--)
 {
 char b[1020];int a[28]={0};int m,max=0,i;
 cin>>b;
 m=strlen(b);
 for(i=0;i<m;i++)
 a[b[i]-'a']++;

 for(int j=0;j<=26;j++)
 {
 if(a[j]>a[max])
 max=j;
 }

 cout<<(char)(max+'a')<<endl;
 }
 return 0;
 }
 */




#include<stdio.h>
int main()
{int t,i,j;
scanf("%d",&t);
getchar();
while(t--)
    {
        int a[26]={0};
char c;
while((c=getchar())!=10)
    a[c-97]++;
  for(j=0,i=1;i<26;++i)
    if(a[j]<a[i])j=i;
  printf("%c\n",j+97);
}
return 0;}
