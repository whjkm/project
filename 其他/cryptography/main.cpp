/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100]={1,0,1};
int main()
{
    for(int i=3;i<100;i++)
    {
        a[i]=(a[i-3]*a[i-2]+a[i-1])%2;
    }
    for(int i=0;i<100;i++)
        printf("%d",a[i]);
    return 0;
}
*/
#include <cstdio>
#include <cstring>
int main()
{
    int a[100];
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    for(int i=4;i<100;i++)
    {
        a[i]=(a[i-4]+a[i-3])%2;
    }
    for(int i=0;i<100;i++)
        printf("%d",a[i]);
    return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
int k, a[60]={0,0,1,0};
printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
for(k=4;k<60;++k){
a[k]=(a[k-3]+a[k-4])%2;
printf("%d",a[k]);
}
getchar();
}
*/

