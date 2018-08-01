/****
转化为矩阵乘法，再用快速幂算法优化
****/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int m = 2;
const int mod = 7;
struct Matrix
{
    int x[m][m];
};

// 矩阵乘法
Matrix multiplication(Matrix a, Matrix b)
{
    Matrix temp;
    memset(temp.x, 0, sizeof(temp.x));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<m; k++)
            {
                temp.x[i][j] += a.x[i][k] * b.x[k][j];
                temp.x[i][j] %= mod;
            }
        }
    }
    return temp;
}

//矩阵的快速幂
Matrix powmatrix(Matrix matrix, int n)
{
    Matrix temp;
    memset(temp.x, 0, sizeof(temp.x));
    for(int i=0; i<m; i++)
        temp.x[i][i] = 1;     //初始化为单位阵
    while(n)
    {
        if(n%2 == 1)
        {
            temp = multiplication(temp, matrix);
        }
        matrix = multiplication(matrix, matrix);
        n = n/2;
    }
    return temp;
}

int main()
{
    int A, B;
    long long n;
    while((cin>>A>>B>>n) && A!=0 && B!=0 && n!=0)
    {
        Matrix mat;
        mat.x[0][0] = A;
        mat.x[0][1] = 1;
        mat.x[1][0] = B;
        mat.x[1][1] = 0;
        mat = powmatrix(mat, n-1);
        printf("%d\n",(mat.x[0][1] + mat.x[1][1])%mod);
    }
    return 0;
}





/****
找规律, 两个%7的数的组合最多只有7*7=49种，
49就为一个循环节，找出其中的周期。
****/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int A, B;
    long long n;
    int f[51];
    while((cin>> A >> B >> n) && A!=0 && B!=0 && n!=0)
    {
        f[1] = 1;
        f[2] = 1;
        int i;
        for(i=3; i<51; i++)
        {
            f[i] = A*f[i-1] + B*f[i-2];
            f[i] = f[i] % 7;
            if(f[i] == 1 && f[i-1] == 1)
            {
                break;
            }
        }
        n = n%(i-2);
        f[0] = f[i-2];
        cout << f[n] <<endl;
    }
    return 0;
}

