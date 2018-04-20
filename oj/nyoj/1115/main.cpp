//±©Á¦·¨
/*#include <cstdio>
#include <cstring>
int main()
{
    int n,count;
    char a[200],b[1200];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        count=0;
        int i=0,j=0,len;
        scanf("%s\n%s",a,b);
        len=strlen(b);
        while(i<=len)
        {
        	if(a[j]=='\0')
            {
                count++;
                i=i-j+1;
                j=0;
            }
            else if(a[j]==b[i])
            {
                i++;
                j++;
            }
            else
            {
                i=i-j+1;
                j=0;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
*/
#include<cstdio>
#include<cstring>
int nextval[200];
void get_next(char a[])
{
    int len;
    int i=0,j=-1;
    nextval[0]=-1;
    len=strlen(a);
    while(i<=len)
    {
        if(j==-1 || a[i]==a[j])
        {
            ++i;
            ++j;
            if(a[i]==a[j])
            nextval[i] = nextval[j];
            else
            nextval[i] = j;
        }
        else
            j=nextval[j];
    }
}
int kmp(char a[],char b[])
{
    int i=0,j=0,count=0;
    int lena,lenb;
    lena=strlen(a);
    lenb=strlen(b);
    get_next(a);
    while(i<=lenb)
    {
         if(j==-1 || a[j]==b[i])
        {
            ++i;
            ++j;
        }
        else
            j=nextval[j];
        if(j>=lena)
        {
            count++;
            j=nextval[j];
        }
    }
    return count;
}
int main()
{
    int n;
    char a[20],b[1200];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s\n%s",a,b);
        printf("%d\n",kmp(a,b));
    }
    return 0;
}
