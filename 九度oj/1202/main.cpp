#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int arr[102];
    while(cin>>n)
    {
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout<<"\n";
    }
    return 0;
}
