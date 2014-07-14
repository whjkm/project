/*#include <stdio.h>
#include <string.h>
int main()
{
    int k1,k2,k3,i,d1,d2,d3,l,j;
    char s[80],a1[80],a2[80],a3[80],change[80],x1[80],x2[80],x3[80];
    while(scanf("%d%d%d",&k1,&k2,&k3)&&k1!=0&&k2!=0&&k3!=0)
    {
        getchar();
        gets(s);
        d1=d2=d3=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]>='a'&&s[i]<='i')
                {
                    a1[d1]=s[i];
                    d1++;
                }
            else if(s[i]>='j'&&s[i]<='r')
               {
                   a2[d2]=s[i];
                   d2++;
               }
            else if((s[i]>='s'&&s[i]<='z')||s[i]=='_')
                {
                    a3[i]=s[i];
                    d3++;
                }
        }
            for(i=0;i<d1;i++)
               x1[i]=a1[(i+k1)%d1];
            for(i=0;i<d2;i++)
                x2[i]=a2[(i+k2)%d2];
            for(i=0;i<d3;i++)
                x3[i]=a3[(i+k3)%d3];
           for(j=0,d1=d2=d3=0;j<l;i++)
           {
                if(s[j]>='a'&&s[j]<='i')
                {
                   change[j]=x1[d1++];
                }
            else if(s[j]>='j'&&s[j]<='r')
               {
                  change[j]=x2[d2++];
               }
            else if((s[j]>='s'&&s[i]<='z')||s[j]=='_')
                {
                change[j]=x3[d3++];
                }
           }
        printf("%s\n",change);
    }
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
struct cgroup
{
    char c;//(mei  ge  zi  fu)
    int p;//zi fu  wei   zhi
};cgroup group1[82],group2[82],group3[82];
int main()
{
    int i,j;
    int k1,k2,k3;
    char me[128];
    while(scanf("%d%d%d\n",&k1,&k2,&k3)&&k1&&k2&&k3)
    {
        int p1,p2,p3;
        p1=p2=p3=0;
        gets(me);
        int n=strlen(me);
        for(i=0;i<n;i++)
            if(me[i]>='a'&&me[i]<='i')
            group1[p1].c=me[i],group1[p1++].p=i;
            else if(me[i]>='j'&&me[i]<='r')
            group2[p2].c=me[i],group2[p2++].p=i;
            else
            group3[p3].c=me[i],group3[p3++].p=i;
            for(i=0;i<p1;i++)
            {
                j=i+k1;
                if(j>=p1)
                    j%=p1;
                me[group1[j].p]=group1[i].c;}
            for(i=0;i<p2;i++)
            {
                j=i+k2;
                if(j>=p2)
                    j%=p2;
                me[group2[j].p]=group2[i].c;
            }
            for(i=0;i<p3;i++)
            {
                j=i+k3;
                if(j>=p3)
                    j%=p3;
                me[group3[j].p]=group3[i].c;
            }
            printf("%s\n",me);
    }
}
