#include <string.h>
#include <stdio.h>
int main()
{
   int t,l,i;
   char s[102];
   int a[6];
   scanf("%d",&t);
   while(t--)
   {
   	   memset(a,0,sizeof(a));
   	   memset(s,0,sizeof(s));
       scanf("%s",s);
       l=strlen(s);
       for(i=l-1;i>=0;i--)
           a[i%6]+=s[i];  //���ַ����۵� �����
       for(i=0;i<6;i++)
       {
          a[i]=a[i]/100+(a[i]/10-a[i]/100*10)+a[i]%10;// �����ֽ�����λ
          do{
           a[i]=a[i]/10+a[i]%10;}
           while(a[i]>=10);
       }
        for(i=0;i<6;i++)
        printf("%d",a[i]);
        printf("\n");
   }
    return 0;
}
