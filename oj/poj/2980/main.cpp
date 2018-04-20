/*#include <cstdio>
#include <cstring>
char a[220],b[220];
int c[220],d[220];
int result[440];
int main()
{
    int i=0,j=0,lena,lenb,n;
    gets(a);
    gets(b);
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(result,0,sizeof(result));
    lena=strlen(a);
    lenb=strlen(b);
    n=lena>lenb?lena:lenb;
    for(j=0,i=lena-1;i>=0;i--)
        c[j++]=a[i]-'0';
    for(j=0,i=lenb-1;i>=0;i--)
        d[j++]=b[i]-'0';
    for(i=0;i<lena;i++)
        for(j=0;j<lenb;j++)
        result[i+j]+=c[i]*d[j];
    for(i=0;i<n*2;i++)
    {
        if(result[i]>=10)
        {
            result[i+1]+=result[i]/10;
            result[i]%=10;
        }
    }
    i=n*2-1;
    while(result[i]==0) i--;
    while(i>=0)
    {
         printf("%d",result[i]);
         i--;
    }
    return 0;
}
*/
/*#include <cstdio>
#include <cstring>
char a[250],b[250];
int c[250],d[250];
int result[1000];
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int i=0,j=0,lena,lenb,n,m;
    scanf("%d",&m);
    while(m--)
    {
    scanf("\n%s",a);
    getchar();
    scanf("%s",b);
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(result,0,sizeof(result));
    lena=strlen(a);
    lenb=strlen(b);
    n=lena>lenb?lena:lenb;
    for(j=0,i=lena-1;i>=0;i--)
        c[j++]=a[i]-'0';
    for(j=0,i=lenb-1;i>=0;i--)
        d[j++]=b[i]-'0';
    for(i=0;i<n;i++)
    {
     result[i]+=c[i]+d[i];
      if(result[i]>=10)
       {
           result[i+1]++;
           result[i]-=10;
       }
    }
    i=n;
    int flag=0;
    while(!result[i])
    {
        if(i==0)
        {
            flag=1;
            printf("0");
        }
        i--;
    }
    while(i>=0&&flag==0)
    {
        printf("%d",result[i]);
        i--;
    }
    printf("\n");
    }
    return 0;
}
*/
#include <cstdio>
#include <cstring>
char a[220],b[220];
int c[220],d[220];
int result[440];
int main()
{
    int i=0,j=0,lena,lenb,n;
    gets(a);//把数字用字符串保存输入
    gets(b);
    memset(c,0,sizeof(c));//对数组进行初始化
    memset(d,0,sizeof(d));
    memset(result,0,sizeof(result));
    lena=strlen(a);
    lenb=strlen(b);
    n=lena>lenb?lena:lenb;
    for(j=0,i=lena-1;i>=0;i--)//把字符数组倒序转换到数字数组中（满足我们的计算习惯）
        c[j++]=a[i]-'0';
    for(j=0,i=lenb-1;i>=0;i--)
        d[j++]=b[i]-'0';
    for(i=0;i<lena;i++)
        for(j=0;j<lenb;j++)
        result[i+j]+=c[i]*d[j];
    for(i=0;i<n*2;i++)
    {
        if(result[i]>=10)
        {
            result[i+1]+=result[i]/10;
            result[i]%=10;
        }
    }
    i=n*2-1;
    while(result[i]==0) i--;
    while(i>=0)
    {
         printf("%d",result[i]);
         i--;
    }
    return 0;
}

/*#include <cstdio>
#include <cstring>
void convision(char a[],int s[])
{
    int len,i,j;
    len=strlen(a);
    for(i=len-1,j=0;i>=0;i--)
        s[j++]=a[i]-'0';
}
int Substract(int *p,int *q,int len1,int len2,int *result)
{
    int i;
    if(len1<len2)
      return -1;
    bool flag=false;
    if(len1==len2)
    {
        for(i=len1-1;i>=0;i--)
        {
            if(p[i]>q[i])
                flag=true;
            else if(p[i]<q[i])
                  if(!flag)
                  return -1;
        }
    }
    for(i=0;i<len1;i++)
    {
        result[i]-=p[i]-q[i];
        if(result[i]<0)
        {
            result[i]+=10;
            result[i+1]--;
        }
    }
    return 0;
}
int main()
{
    char a[220],b[220];
    int c[220],d[220];
    int result[240];
    int n,lena,lenb;
    scanf("%d",&n);
    gets(a);
    gets(b);
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(result,0,sizeof(result));
    convision(a,c);
    convision(b,d);
    lena=strlen(a);
    lenb=strlen(b);


    return 0;
}
*/



/*#include <cstdio>
#include <cstring>
int main()
{
    //freopen("1.txt","r",stdin);
    char a[220],b[220];
    int c[220],d[220];
    int result[240];
    int n,i,j,lena,lenb;
    scanf("%d",&n);
    while(n--)
    {
        scanf("\n%s",a);
        getchar();
        scanf("%s",b);
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        memset(result,0,sizeof(result));
        lena=strlen(a);
        lenb=strlen(b);
        for(i=lena-1,j=0;i>=0;i--)
           c[j++]=a[i]-'0';
        for(i=lenb-1,j=0;i>=0;i--)
           d[j++]=b[i]-'0';
        for(i=0;i<lena;i++)
            result[i]=c[i]-d[i];
        for(i=0;i<lena;i++)
            if(result[i]<0)
            {
                result[i]+=10;
                result[i+1]--;
            }
      for(i=lena-1;!result[i]&&i>0;i--);
      for(j=i;j>=0;j--)
       printf("%d",result[j]);
      printf("\n");
    }
    return 0;
}
*/

/*#include <cstdio>
#include <cmath>
void factorial(int n)
{
int a[10000];
int i,j,c,m=0;
a[0]=1;
for(i=1;i<=n;i++)
{
    c=0;
    for(j=0;j<=m;j++)
    {
        a[j]=a[j]*i+c;
        c=a[j]/10000;
        a[j]=a[j]%10000;
    }
    if(c>0) {m++;a[m]=c;}
}
   printf("%d",a[m]);
   int w=m*4+log10(a[m])+1;
   for(i=m-1;i>=0;i--)
      printf("%0.4d",a[i]);
    printf("\n");
    printf("%d",w);
}
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        factorial(m);
    }
    return 0;
}
*/
