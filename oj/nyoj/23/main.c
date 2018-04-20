#include <stdio.h>
int main()
{
  int n,N,M;
  scanf("%d",&n);
  while(n--)
  {
      scanf("%d%d",&N,&M);
      printf("%s\n",N%(M+1)?"Win":"Lose");
  }
    return 0;
}
