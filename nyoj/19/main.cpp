/*#include <cstdio>
#include <cstring>
#include <algorithm>
char a[10]={'1','2','3','4','5','6','7','8','9','\0'};
using namespace std;
int main()
{
  int t,n,m;
  char b[10],c[10];
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d%d",&n,&m);
      strcpy(b,a);
      b[m]='\0';
      printf("%s\n",b);
      while(next_permutation(a,a+n))
      {
          strcpy(c,a);
          c[m]='\0';
          if(strcmp(b,c))
          {
              strcpy(b,c);
              b[m]='\0';
              printf("%s\n",b);
          }
      }
  }
  return 0;
}
*/
/*#include <cstdio>
#include <cstring>
int visit[20],a[20];
int n,m;
void dfs(int pos)
{
    if(pos==m)
    {
        for(int i=0;i<m;i++)
            printf("%d",a[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            visit[i]=1;
            a[pos]=i;
            dfs(pos+1);
            visit[i]=0;
        }
    }
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
      memset(visit,0,sizeof(visit));
      scanf("%d%d",&n,&m);
      dfs(0);
  }
  return 0;
}
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
//int a[] = {3,1,2};
int a[]={1,2,3};
do{
      cout << a[0] << " " << a[1] << " " << a[2] << endl;
}
while (next_permutation(a,a+3));
//while (prev_permutation(a,a+3));
return 0;
}
