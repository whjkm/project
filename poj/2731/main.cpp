#include <stdio.h>
int main()
{
    int carry,n,j;
    int a[40001];
    int digit;
    int temp,i;
    while(scanf("%d",&n)!=EOF){
    a[0]=1;digit=1;
    for(i=2; i<=n; i++)
    {
        for(carry=0,j=1; j<=digit; ++j)
        {
            temp=a[j-1]*i+carry;
            a[j-1]=temp%10;
            carry=temp/10;
        }
        while(carry)
        {
            //digit++;
            a[++digit-1]=carry%10;
            carry/=10;
        }
    }

    for(int k=digit; k>=1; --k)
        printf("%d",a[k-1]);
    printf("\n");
 printf("length=%d\n",digit);
 }
    return 0;
}

/*#include<iostream>
#include <cstdio>
using namespace std;
int a[100000]={0};
int main()
{
 int n;
 //freopen("1.txt","w",stdout);
 int i,len=1,j,temp=0;
 cin>>n;
 a[0]=1;
 for(i=2;i<=n;i++)
 {
  for(j=0;j<len;j++)
  {
   a[j]=i*a[j]+temp;
   temp=a[j]/10;
   a[j]%=10;
  }
  while(temp!=0)
  {
   a[j++]=temp%10;
   temp/=10;
  }
  len=j;
 }
 len+=50-len%50;
 for(i=len-1;i>=0;i--)
 {
  if((i+1)%50==0&&i+1!=len)
  cout<<"\n";
  cout<<a[i];
 }
 cout<<"\n";
 return 0;
}
*/
