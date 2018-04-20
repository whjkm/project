#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define SIZE_INCRMENT 5
typedef struct
{
    int *base;                          //栈底
    int *top;                           //栈顶
    int stacksize;                      //栈大小
}Sqstack,*SQSTACK;
int stackinit(SQSTACK s)
{
    s->base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!(s->base))
        exit(0);
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
    return 1;
}
int PUSH(SQSTACK s,int e)
{
    if(s->base+s->stacksize==s->top)
    {
        s->base=(int*)realloc(s->base,(SIZE_INCRMENT+s->stacksize)*sizeof(int));
        s->top=s->base+s->stacksize;
        s->stacksize+=SIZE_INCRMENT;
    }
    *(s->top)=e;
    s->top+=1;
    return 1;
}
int POP(SQSTACK s,int *p)
{
    if(s->base==s->top)
        return 0;
        *p=*(s->top-1);
        s->top--;
        return 1;
}
int stacklength(SQSTACK s)
{
    return (s->top-s->base);
}
int stackfree(SQSTACK s)
{
    free(s->base);
    s->top=s->base=NULL;
    return 1;
}
int othertodec(int sys,char *in_str)
{
    int i,j,length,start=0;
    unsigned long sum=0,pow;
    int *in_bit;
    length=strlen(in_str);
    if(!(in_bit=(int *)malloc(sizeof(int)*length)))
    {
        printf("内存分配失败！\n");
        exit(0);
    }
    if(in_str[0]=='-')
        start++;
    j=0;
    for(i=length-1;i>=start;i--)
    {
        if(in_str[i]>='0'&&in_str[i]<='9')
            in_bit[j]=in_str[i]-'0';
        else if(in_str[i]>='A'&&in_str[i]<='F')
            in_bit[j]=in_str[i]-'A'+10;
        else if(in_str[i]>='a'&&in_str[i]<='f')
            in_bit[j]=in_str[i]-'a'+10;
        else
            exit(0);
        j++;
    }
    length-=start;
    for(i=0;i<length;i++)
    {
        if(in_bit[i]>=sys)
        {
            printf("输入的数据不符合%d进制数据的规则！",sys);
            exit(0);
        }
        for(j=1,pow=1;j<=i;j++)
            pow*=sys;
        sum+=in_bit[i]*pow;
    }
    return sum;
}
char *dectoother(unsigned long num,int sys)
{
    Sqstack s;
    int rem,i,length,num1,inc=1;
    char *out ,*p;
    if(!stackinit(&s))
        exit(0);
    do{
        if(num<sys)
        {
            rem=num;
            PUSH(&s,rem);
            break;
        }
        else
        {
            rem=num%sys;
            PUSH(&s,rem);
            num=num/sys;
        }
    }while(num);
    if(sys==16)
        inc++;
    length=stacklength(&s);
    if(!(out=(char *)malloc(sizeof(char)*(length+inc))))
    {
        printf("内存分配失败！\n");
        exit(0);
    }
    p=out;
    *p++='0';
    if(sys==16)
        *p++='x';
    for(i=1;i<=length;i++)
    {
        POP(&s,&num1);
        if(num1<10)
            *p++=num1+'0';
        else
            *p++=num1+'A'-10;
    }
    stackfree(&s);
    *p='\0';
    return (out);
}
int main()
{
   int old,new1;
   char select='N',*other,str[80];
   unsigned long num10;
   do
   {
       printf("\n原数据进制:");
       scanf("%d",&old);
       printf("输入%d进制数：",old);
       scanf("%s",str);
       num10=othertodec(old,str);
       printf("需要转换的进制:");
       scanf("%d",&new1);
       if(10==new1)
       {
           printf("\n将%d进制数%s\n转换为十进制数：%d\n",old,str,num10);
       }
       else
        {
            other=dectoother(num10,new1);
            printf("\n将%d进制数%s\n转换为%d进制数：%s\n",old,str,new1,other);
        }
        printf("\n继续（Y/N）?");
        select=getch();
   }while(select=='y'||select=='Y');
   getch();
    return 0;
}
