#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
typedef long long ll;
using namespace std;
int main()
{
    int n;
    ll heigh,ans;
    stack<ll>s;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        cin>>heigh;
        s.push(heigh);
        for(int i=1;i<n;i++)
        {
            cin>>heigh;
            while(!s.empty()&&s.top()<=heigh) //�Ƚ�ջ��Ԫ�غ��¼���Ԫ�صĹ�ϵ
            {
                s.pop();
            }
            ans+=s.size();
            s.push(heigh);
        }
        cout<<ans<<endl;
        while(!s.empty()) s.pop();//���ջ
    }
    return 0;
}
