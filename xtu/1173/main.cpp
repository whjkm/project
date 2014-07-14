#include <stdio.h>
#include <iostream>
using namespace std;
char Matrix[5][5];
using namespace std;
int big_tiger(char ch)
{
    if(Matrix[0][0]==ch && Matrix[0][4]==ch && Matrix[2][2]==ch && Matrix[4][0]==ch && Matrix[4][4]==ch)
        return 10;
    else
        return 0;
}
int small_tiger(char ch)
{
    int total = 0;
    int i=1,j=1;
    for(i=1; i<4; i++)
        for(j=1; j<4; j++)
        {
            if(Matrix[i][j]==ch && Matrix[i-1][j-1]==ch && Matrix[i+1][j+1]==ch && Matrix[i-1][j+1]==ch && Matrix[i+1][j-1]==ch)
               total += 5;
        }
    return total;
}
int sky(char ch)
{
    int total = 0;
    int i;
    for(i=0; i<5; i++)
    {
        if(Matrix[i][0]==ch && Matrix[i][1]==ch && Matrix[i][2]==ch && Matrix[i][3]==ch && Matrix[i][4]==ch)
            total += 5;
        if(Matrix[0][i]==ch && Matrix[1][i]==ch && Matrix[2][i]==ch && Matrix[3][i]==ch && Matrix[4][i]==ch)
           total += 5;
    }
    if(Matrix[0][0]==ch && Matrix[1][1]==ch && Matrix[2][2]==ch && Matrix[3][3]==ch && Matrix[4][4]==ch)
      total+=5;
    if(Matrix[0][4]==ch && Matrix[1][3]==ch && Matrix[2][2]==ch && Matrix[3][1]==ch && Matrix[4][0]==ch)
      total+=5;
    return total;
}
int four(char ch)
{
    int total=0;
    if(Matrix[0][3]==ch && Matrix[1][2]==ch && Matrix[2][1]==ch && Matrix[3][0]==ch)
        total += 4;
    if(Matrix[1][0]==ch && Matrix[2][1]==ch && Matrix[3][2]==ch && Matrix[4][3]==ch)
        total += 4;
    if(Matrix[1][4]==ch && Matrix[2][3]==ch && Matrix[3][2]==ch && Matrix[4][1]==ch)
        total += 4;
    if(Matrix[0][1]==ch && Matrix[1][2]==ch && Matrix[2][3]==ch && Matrix[3][4]==ch)
        total += 4;

        return total;
}
int three(char ch)
{
    int total=0;
    if(Matrix[0][2]==ch && Matrix[1][1]==ch && Matrix[2][0]==ch)
        total += 3;
    if(Matrix[2][0]==ch && Matrix[3][1]==ch && Matrix[4][2]==ch)
        total += 3;
    if(Matrix[2][4]==ch && Matrix[3][3]==ch && Matrix[4][2]==ch)
        total += 3;
    if(Matrix[0][2]==ch && Matrix[1][3]==ch && Matrix[2][4]==ch)
        total += 3;

    return total;
}
int small_dou(char ch)
{
    int total = 0;
    int i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(Matrix[i][j]==ch && Matrix[i+1][j]==ch && Matrix[i][j+1]==ch && Matrix[i+1][j+1]==ch)
            {
                total++;
            }

    return total;

}
int main()
{
    int t,frist,last ,i,j;
    scanf("%d",&t);
    getchar();
    //cin>>t;
    while(t--)
    {
        getchar();
        for(i=0;i<5;i++)
            {
               for(j=0;j<5;j++)
               scanf("%c",&Matrix[i][j]);
               getchar();
               //cin>>Matrix[i][j];
            }
         frist=last=0;
         frist=big_tiger('x')+small_tiger('x')+sky('x')+four('x')+three('x')+small_dou('x');
         last=big_tiger('o')+small_tiger('o')+sky('o')+four('o')+three('o')+small_dou('o');
         printf("%d %d\n",frist,last);
    }
    return 0;
}

/*int main()
{
    int i,j;
    int times;
    int total_first,total_last;
    cin >> times;
    getchar();
    while(times--)
    {
        getchar();
        for(i=0; i<5;i++)
        {
            for(j=0;j<5;j++)
              //cin>>Matrix[i][j];
               scanf("%c",&Matrix[i][j]);
               getchar();
        }
         total_first = total_last=0;
         total_first = big_tiger('x')+small_tiger('x')+sky('x')+four('x')+three('x')+small_dou('x');
         total_last = big_tiger('o')+small_tiger('o')+sky('o')+four('o')+three('o')+small_dou('o');
         printf("%d %d\n",total_first,total_last);
    }
    return 0;
}
*/
