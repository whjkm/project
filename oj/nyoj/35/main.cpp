/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1001
char s[MAXN];
char op[MAXN];
char cmp(char s,char z)
{
    if(s=='+'||s=='-')
    {
        if(z=='*'||z=='/'||z=='(')
            return '<';
        else
            return '>';
    }
    if(s=='*'||s=='/')
    {
        if(z=='(')
            return '<';
        else
            return '>';
    }
    if(s==')')
        return '<';
    if(s=='('||s=='=')
    {
        if(s=='('&&z==')'||s=='='&&z=='=') return '=';
        else
            return '<';
    }
}
int main()
{
  int n,i,len;
  int top=-1;
  int op_top=-1;
  scanf("%d",&n);
  while(n--)
  {
      scanf("%s",s);
      len=strlen(s);
      for(i=0;i<len-1;i++)
      {
          if(s[i]>='0'&&s[i]<='9'||s[i]=='.')
          {
              printf("%c",s[i]);
              continue;
          }
         else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
          {
              op_top++;
              op[op_top]=s[i];
              if(op-top!=-1)
              {

              }
          }
        else if(s[i]=='(')
        {
            op_top++;
            op[op_top]=s[i];
        }
        else if(s[i]==')')
        {
            while(op[op_top]!='(')
            {
                printf("%c",op[op_top]);
                op_top--;
            }
            op_top--;
        }
      }
  }
    return 0;
}
*/
