/*#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,n,m;
   int rab,che;
   scanf("%d",&a);
   while(a--)
   {
       scanf("%d%d",&n,&m);
      for(che=0;che<=n;che++)
      {
          rab=n-che;
          if(che*2+rab*4==m)
             printf("%d %d\n",che,rab);
      }

   }
   return 0;
}
*/
/*#include<stdio.h>
 int main()
 {
 int c,j,t,tui,zhi;
 scanf("%d",&c);
 while(c--)
 {
 scanf("%d%d",&zhi,&tui);
 j = (4*zhi - tui) /2;
 t = (tui- 2*zhi) /2;
 if( j<0 || t<0 || zhi%2==1)
 printf("No answer\n");
 else
 printf("%d %d\n",j,t);

 }
 return 0;
 }
*/
/*#include <stdio.h>
 int main()
 {
 int a;
 int n, m;
 int chicken, rabbit;

 scanf("%d", &a);
 while(a--) {
 scanf("%d %d", &n, &m);
 chicken = (4*n - m)/2;
 rabbit = (m - 2*n)/2;
 if ( ((4*n - m)%2==0)
 && ((m - 2*n)%2 ==0)
 && chicken>=0 && rabbit>=0)
 printf("%d %d \n", chicken, rabbit);
 else
 printf("No answer\n");
 }

 return 0;
 }
*/
#include<stdio.h>
int main()
{
    int t,a,b,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        q=(b-2*a)/2;
        p=a-q;
        if(p<0 ||q<0 || b%2)
            printf("NO answer\n");
        else
            printf("%d %d\n",p,q);
    }
    return 0;
}

