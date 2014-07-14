#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string sum(string a,string b)
{
    if(a.length()<b.length())
    {
        string temp=a;
        a=b;
        b=temp;
    }
    int i,j;
    for(i=a.length()-1,j=b.length()-1;i>=0;i--,j--)
    {
        a[i]=char(a[i]+(j>=0?b[j]-'0':0));
        if(a[i]-'0'>=10)
        {
            a[i]=char((a[i]-'0')%10+'0');
            if(i)
                a[i-1]++;
            else
                a='1'+a;
        }
    }
    return a;
}
int main()
{
   int n;
   scanf("%d",&n);
   while(n--)
   {
       string s;
       cin>>s;
       if(s.size()==1)
       {
           printf("1\n");
           continue;
       }
      else if(s.size()==2)
       {
           printf("2\n");
           continue;
       }
       string temp,a,b;
       a="1",b="2";
       for(int i=3;i<=s.size();i++)
       {
           temp=sum(a,b);
           a=b;
           b=temp;
       }
       cout<<b<<endl;
   }
    return 0;
}
