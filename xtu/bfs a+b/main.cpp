#include <iostream>
using namespace std;
int queue[100000],front,rear;
int BFS(int a,int b)
{
    int result;
    front=0;
    rear=2;
    queue[0]=a;
    queue[1]=b;
    while(front<rear)
    {
        int x=queue[front++];
        if(x==1)
        {
            result++;
            continue;
        }
        queue[rear++]=1;
        queue[rear++]=--x;
    }
    return result;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<BFS(a,b)<<endl;
    return 0;
}
