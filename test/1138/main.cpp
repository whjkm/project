#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n,i,j;
    string str1,str2;
    while(cin>>n>>str1>>str2)
    {
        stack<int>s;
        vector<string>v;
        for(i=0,j=0;i<n&&j<n;i++)
        {
            s.push(str1[i]);
            v.push_back("in");
            while(s.top()==str2[j])
            {
                if(!s.empty())
                {
                    s.pop();
                    v.push_back("out");
                }
                j++;
                if(s.empty()) break;
            }
        }
        if(j==n)
        {
            printf("Yes.\n");
            for(i=0; i< v.size();i++)
             cout<< v[i] <<endl;
             printf("FINISH\n");
        }
        else
             printf("No.\nFINISH\n");
    }
    return 0;
}
