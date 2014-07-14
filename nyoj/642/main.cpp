#include <algorithm>
#include <stdio.h>
using namespace std;
struct milk
{
    char name[20];
    int money;
    int v;
};
/*bool cmp(milk x,milk y)
{
    int m,n;
    n=x.v/x.money;
    m=y.v/y.money;
    if(x.v>1000)
        n=1000/x.money;
    else if(y.v>1000)
        m=1000/y.money;
    if(n>m)
        return true;
    else if(n==m&&x.v>y.v)
        return true;
    return false;
}*/
/*int cmp(milk x,milk y)
{   int day1,day2;
	double price2,price1;
	day1=(x.v/200)>5?5:(x.v/200);
	day2=(y.v/200)>5?5:(y.v/200);
	price1=x.money*1.0/day1;
	price2=y.money*1.0/day2;
	if(price1==price2)
	return x.v>y.v;
	else
	return price1<price2;
}*/
bool cmp(milk x,milk y)
{
    int day1,day2;
    double price1,price2;
    day1=(x.v/200)>5?5:(x.v/200);
    day2=(y.v/200)>5?5:(y.v/200);
    price1=x.money*1.0/day1;
    price2=y.money*1.0/day2;
    if(price1==price2&&x.v>y.v)
        return true;
    else if(price1<price2)
        return true;
    return false;
}

int main()
{
   int t,i;
   struct milk s[102];
   while(scanf("%d",&t)!=EOF)
   {
       for(i=0;i<t;i++)
        scanf("%s%d%d",s[i].name,&s[i].money,&s[i].v);
       sort(s,s+t,cmp);
       for(i=0;i<t;i++)
           if(s[i].v>=200)
           {
               printf("%s\n",s[i].name);
                break;
           }
   }
    return 0;
}
