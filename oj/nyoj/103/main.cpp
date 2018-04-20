#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,a[1001],b[1001],c[1001],lenth1,lenth2,n,m=1;
    char s1[1001],s2[1001];
    scanf("%d",&t);
    while(t--)
    {
        n=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%s%s",s1,s2);
        lenth1=strlen(s1);
        lenth2=strlen(s2);
        n=(lenth1>lenth2)?lenth1:lenth2;
        for(j=0,i=lenth1-1;i>=0;i--)
            a[j++]=s1[i]-'0';
        for(j=0,i=lenth2-1;i>=0;i--)
            b[j++]=s2[i]-'0';
        for(i=0;i<n;i++)
        {
            c[i]+=a[i]+b[i];
            if(c[i]>=10)
            {
                c[i+1]=c[i]/10;
                c[i]%=10;
            }
        }
        printf("Case %d:\n",m++);
     printf("%s + %s = ",s1,s2);
    while(n>=0 && !c[n]) n--;		//去前导零
	while(n>=0) printf("%d", c[n--]);	//输出
	printf("\n");
 }
 return 0;
}
       /*for(j=n;c[j]==0;j--);//从高位把c中是零的给排除
          if(j<0)
          printf("0");
          else
         for(;j>=0;j--)
         {
         printf("%d",c[j]);
         }
          printf("\n");
         }
    return 0;
}
*/
/*#include<stdio.h>
 #include<string.h>
 #define LEN 1000
 int main()
 {
 int count,a[LEN+10],b[LEN+10],len_stra,len_strb,i,j,c[LEN+10],n=0;
 char stra[LEN+10],strb[LEN+10];
 scanf("%d",&count);
 while(n++<count)
 {
 memset(a,0,sizeof(a));//对数组初始化；
memset(b,0,sizeof(b));
 memset(c,0,sizeof(c));
 scanf("%s",stra);
 scanf("%s",strb);
 len_stra=strlen(stra);
 len_strb=strlen(strb);
 for(i=len_stra-1,j=0;i>=0;i--)//把stra中的字符转化成int型倒着保存到a中；
a[j++]=stra[i]-'0';
 for(i=len_strb-1,j=0;i>=0;i--)
b[j++]=strb[i]-'0';
 for(i=0;i<LEN+10;i++)//a和b对应位相加保存到c中
{
c[i]+=a[i]+b[i];
 if(c[i]>=10)//进位
{
c[i]%=10;
 c[i+1]++;
 }
 }
 printf("Case %d:\n",n);//输出结果
printf("%s + %s = ",stra,strb);
 for(j=LEN+10-1;c[j]==0;j--);//从高位把c中是零的给排除
if(j<0)
 printf("0");
 else
 for(;j>=0;j--)
 {
printf("%d",c[j]);
 }
 }
 printf("\n");
 return 0;
 }
*/

