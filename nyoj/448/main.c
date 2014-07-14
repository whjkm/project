/*#include <stdio.h>
#define N 100
int main()
{
    int t,m,l;
    char a[N];
    while(t--)
    {
        scanf("%s%d",a,&m);
        l=strlen(a);

    }
    return 0;
}
*/
#include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 int cmp(const void *a,const void *b)
 {
 return *(char *)b-*(char *)a;
 }
 int main()
 {
 char str[110],s;
 int test,m,t,k,a;
 scanf("%d",&test);
 while(test--)
 {
 scanf("%s%d",str,&m);
 t=strlen(str);
 for(a=k=0;m<t; m++)
 {
 s='0'-1;
 while(k<=m)
 {
 if(str[k]>s) {s=str[k],a=k;}
 k++;
 }
 k=a+1;
 //printf("%d %d %d\n",m,k,i);
 printf("%c",str[a]);
 }
 printf("\n");
 }
 return 0;
 }
