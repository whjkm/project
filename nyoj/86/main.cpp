#include <stdio.h>
#include<algorithm>
using namespace std;
 int num[1000000];
 int k[100000];
int main()
{
  int m,n,i,begin,end,mid,flag;
     scanf("%d%d",&m,&n);
      for(i=0;i<m;i++)
        scanf("%d",&num[i]);
        sort(num,num+m);
      for(i=0;i<n;i++)
        scanf("%d",&k[i]);
      for(i=0;i<n;i++)
      {
          begin=0,end=m-1,flag=0;
          while(begin<=end)
          {
              mid=(begin+end)/2;
              if(k[i]==num[mid]){flag=1;break;}
              else if(k[i]>num[mid]) begin=mid+1;
              else  end=mid-1;
          }
          if(flag) printf("YES\n");
          else printf("NO\n");
      }
    return 0;
}
