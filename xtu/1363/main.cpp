/*#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000+10;
int n,targe[maxn];
int main()
{
   while(scanf("%d",&n)==1)
   {
       int stack[maxn],top;
       int A=1,B=1;
       for(int i=1;i<=n;i++)
        scanf("%d",&targe[i]);
        int ok=1;
        while(B<=n)
        {
            if(A==targe[B])
            {
                A++;
                B++;
            }
            else if(top&& stack[top]==targe[B])
            {
                top--;
                B++;
            }
            else if(A<=n)
                stack[++top]=A++;
            else
            {
                ok=0;
                break;
            }
        }
        printf("%s\n" ,ok ?"Yes":"No");
   }
    return 0;
}
*/

