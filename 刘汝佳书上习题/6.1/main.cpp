/*#include <queue>
#include <stdio.h>
using namespace std;
queue<int>q;
int main()
{
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++) q.push(i+1);
  while(!q.empty())
  {
      printf("%d ",q.front());
      q.pop();
      q.push(q.front());
      q.pop();
  }
  return 0;
}
*/
#include<cstdio>
#include<stack>
using namespace std;
const int MAXN =1000+10;
int n,targe[MAXN];
int main()
{
    int i;
    while(scanf("%d",&n)==1)
    {
        stack<int> s;
        int A=1,B=1;
        for(i=1;i<=n;i++)
            scanf("%d",&targe[i]);
        int ok=1;
        while(B<=n)
        {
            if(A==targe[B]) {A++;B++;}
            else if(!s.empty()&&s.top()==targe[B]) {s.pop();B++;}
            else if(A<=n) s.push(A++);
            else {
                ok=0;break;
            }
        }
         printf("%s\n",ok?"Yes":"No");
    }
      return 0;
}
