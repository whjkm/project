/*#include <stdio.h>
#define M 100001
long int a[M];
int main()
{
   int n;
   while(scanf("%d",&n)!=EOF)
   {
       int count=0;
       for(int i=0;i<n;i++)
             scanf("%ld",&a[i]);
       for(int i=0;i<n;i++)
        {
            if(a[i]!=1)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(a[j]==a[i]) break;
                    else if(a[j]%a[i]!=0)
                        count++;
                }
            }
        }
    printf("%d\n",count);
   }
    return 0;
}

*/
/*#include<stdio.h>
#include<cstring>
char s[28]={'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main()
{
    long long a[100];
    a[0]=1;a[1]=1;
    for(int i=2;i<100;i++)
        a[i]=a[i-1]+a[i-2];
    char c[100];
    gets(c);
    for(int i=0,x=0;i<strlen(c);)
      {
         for(int j=1;j<=26;j++)
         {
             if(c[i]==s[j])
             {
                 c[i]=s[(j-a[x]%26+26)%26];
                 i++;x++;
                 break; 
             }
             else if(c[i]==' '||c[i]==',')
             {
             	  i++;   
             }
         }
      }
    printf("%s",c);
    //puts(c);
}
*/
/*#include<stdio.h>
#define N 100001
typedef long long LL;
LL a[N];
int main()
{
    int n,i,j;
   while(scanf("%d",&n)!=EOF)
    {
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
       LL ret2=0;
    for(i=1;i<=n;i++) {
          for(j=i+1;j<=n;j++) {
             if(a[i]>a[j])
                {
                 if(a[i]%a[j]!=0) ret2++;
                }
           else if(a[j]>a[i])
                {
                 if(a[j]%a[i]!=0) ret2++;
                }

            }
        }
       printf("%I64d\n",ret2);
    }
       return 0;
}
*/
