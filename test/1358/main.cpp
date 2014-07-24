#include <cstdio>
#include <cstring>
int n;
int next[50];
char s[50];
void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<=n)
    {
        if(j==-1 || s[i]==s[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        j=next[j];
    }
}
int main()
{
    int t,j=1;
    while(scanf("%d",&n)&&n)
    {
       scanf("%s",s);
       get_next();
       printf("Test case #%d\n",j++);
       for(int i=2;i<=n;i++)
       {
           t=i-next[i]; //关键点在这里
           if(i%t==0&&i/t>1)
           {
               printf("%d %d\n",i,i/t);
           }
       }
       printf("\n");
    }
    return 0;
}
