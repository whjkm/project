#include <iostream>
#include <cstdio>
using namespace std;
bool flag;
bool compete(int w,int h)
{
    if(w%2==1&&h%2==1)
        flag=false;
    if(w%2==0)
    {
        w/=2;
        compete(w,h);
    }
    if(h%2==0)
    {
        h/=2;
        compete(w,h);
    }
    else
        flag=true;
    return flag;
}
int main()
{
     int t,i;
     int w,h;
     scanf("%d",&t);
     for(i=1;i<=t;i++)
     {
         //cout<< "Case " << i <<':'<<" "<<endl;
         scanf("%d%d",&w,&h);
         bool flag=true;
         compete(w,h);
         printf("Case %d: ",i);
         if(flag)
           printf("Alice\n");
         else
          printf("Bob\n");
     }
    return 0;
}
