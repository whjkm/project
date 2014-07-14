#include <stdio.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define MAXSIZE 10001
typedef int status;
typedef struct
{
    char data[MAXSIZE];
    int top;
}sqstack;
status push(sqstack *s,char e)
{
    if(s->top==MAXSIZE-1)
        return ERROR;
    s->top++;
    s->data[s->top]=e;
    return OK;
}
status pop(sqstack *s,char *e)
{
    if(s->top==-1)
        return ERROR;
    *e=s->data[s->top];
    s->top--;
    return OK;
}
int main()
{
   int n,i;
   sqstack *s;
   scanf("%d",&n);
   while(n--)
   {
      s->top=0;
      gets(s->data);
      for(i=0;s->data[i]!='\0';i++)
        {
             push(s,s->data[i]);
            if((s->data[i]=='['&&s->data[i+1]==']')||(s->data[i]=='('&&s->data[i+1]==')')
               pop(s,s->data[i-1]);
            else if()
        }
   }
    return 0;
}

/*#include "stdio.h"
int main()
{
    int i,k,T;
    char a[10000],b[10000];
    scanf("%d",&T);
    getchar();
    while(T--)
    {
           k=0;
           gets(a);
           for(i=0;a[i]!=0;i++)
           {
                  b[k++]=a[i];
                  if((b[k-2]=='('&&b[k-1]==')')||(b[k-2]=='['&&b[k-1]==']'))
                       k-=2;
           }
           if(k==0)
                  printf("Yes\n");
           else
                  printf("No\n");
    }
           return 0;
}
*/
