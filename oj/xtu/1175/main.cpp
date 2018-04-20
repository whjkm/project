#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#define E 1e-10
using namespace std;
double x1,y11,x2,y22,vp,vt;
double call(double x)
{
    return sqrt((x1-x)*(x1-x)+y11*y11)/vp+sqrt((x2-x)*(x2-x)+y22*y22)/vt;
}
double fun()
{
    double low,high,mid,mmid;
    if(x1>x2) swap(x1,x2);
     low=x1,high=x2;
     while(low+E<high)
     {
         double v1,v2;
         mid=(low+high)/2;
         mmid=(mid+high)/2;
         v1=call(mid);
         v2=call(mmid);
         if(v1<=v2)
         {
             high=mmid;
         }
         else low=mid;
     }
     return call(low);
}
int main()
{
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        //cin >> x1 >> y11 >> x2 >> y22 >> vp >> vt;
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y11,&x2,&y22,&vp,&vt);
        double p_time,t_time;
        p_time=sqrt((x2-x1)*(x2-x1)+(y22-y11)*(y22-y11))/vp;
        t_time=fun();
        printf("%.2lf\n",p_time<t_time?p_time:t_time);
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
    int times;
    int x1,y1,x2,y2,vp,vt;
    double min,person_time,taxi_time;
    //cin >> times;
    scanf("%d",&times);
    while(times--)
    {
        //cin >> x1 >> y1 >> x2 >> y2 >> vp >> vt;
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&vp,&vt);
        x1*=10,x2*=10,y2*=10,y1*=10,vp*=10,vt*=10;
        person_time = (double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))/vp;
        min = 1000;
        if(x2>=x1)
            for(int i=x1; i<=x2; i++)
            {
                taxi_time = sqrt((i-x1)*(i-x1)+y1*y1)/vp+sqrt((x2-i)*(x2-i)+y2*y2)/vt;
                if(taxi_time<min)
                    min = taxi_time;
            }
        else
            for(int i=x2; i<=x1; i++)
            {
                taxi_time = sqrt((i-x2)*(i-x2)+y2*y2)/vt+sqrt((x1-i)*(x1-i)+y1*y1)/vp;
                if(taxi_time<min)
                    min = taxi_time;
            }
        printf("%.2f\n",person_time<min?person_time:min);
    }
    return 0;
}


