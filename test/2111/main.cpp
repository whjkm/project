#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
    int t,m,len,flag,i,j;
    char n[2000],min,temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        len=strlen(n);
        min=n[0];
        if(m==1)
        {
            for(int i=0; i<len; i++)
            {
                if(n[i]!='0' && n[i]<min)
                {
                    min=n[i];
                    flag=i;
                }
            }
            if(n[0]!='0' && n[0]>min)//是要与最小值所在的位置的值进行交换
            {
                /*temp=n[flag];
                n[flag]=n[0];
                n[0]=temp;*/
                swap(n[0],n[flag]);
                m--;
            }
        }
            for(i=1;i<len&&m!=0;i++)
            {
                min=n[i];
                for(j=len-1;j>i&&m!=0;j--)
                {
                    if(n[j]<min)
                    {
                        min=n[j];
                        flag=j;
                    }
                }
                if(n[j]>min)
                {
                    swap(n[j],n[flag]);
                    m--;
                }
            }
        if(m==0)
            cout << n <<endl;
    }
    return 0;
}
