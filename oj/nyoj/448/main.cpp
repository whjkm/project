 /*#include<stdio.h>
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
*/

#include <cstdio>
#include <cstring>
int main()
{
    int t,m,len,max;
    char s[101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%d",s,&m);
        len=strlen(s);
        for(int i=0,j=0;m<len;m++)
        {
            max=0;
            while(j<=m)
            {
                if(s[j]>max)
                {
                    max=s[j];
                    i=j;
                }
                j++;
            }
            j=i+1;
            printf("%c",s[i]);
        }
        printf("\n"); 
    }
    return 0;
}
