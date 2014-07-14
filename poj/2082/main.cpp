#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
struct rectangle
{
    int h;
    int w;
}data;
int main()
{
    int n,ans,prior_h,total_w,area;
    while(scanf("%d",&n)&&n!=-1)
    {
        ans=0;
        stack<rectangle>s;
        prior_h=0;
        for(int i=0;i<n;i++)
           {
            scanf("%d%d",&data.w,&data.h);
        if(data.h>prior_h)
        {
            s.push(data);
        }
        else
        {
            total_w=0;
            area=0;
            while(!s.empty()&&s.top().h>data.h)
            {
                total_w+=s.top().w;
                area=total_w*s.top().h;
                if(area>ans)
                    ans=area;
                s.pop();
            }
            total_w+=data.w;
            data.w=total_w;
            s.push(data);
        }
       prior_h=data.h;
    }
    total_w=0;
    area=0;
    while(!s.empty())
    {
        total_w+=s.top().w;
        area=total_w*s.top().h;
        if(area>ans)
            ans=area;
        s.pop();
    }
    printf("%d\n",ans);
    }
    return 0;
}
