#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int N = 500005;
const double PI = acos(-1.0);

// 构造复数结构体
struct complex
{
    double r,i;
    complex(double _r = 0.0, double _i = 0.0)
    {
        r = _r;
        i = _i;
    }

    //复数三种运算的定义
    complex operator +(const complex &b)
    {
        return complex(r + b.r, i + b.i);
    }
    complex operator -(const complex &b)
    {
        return complex(r - b.r, i - b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r - i*b.i, r*b.i + i*b.r);
    }
};

// 雷德算法 -- 倒位序
void Rader(complex F[], int len)
{
    int j = len >> 1;        // j = len/2
    for(int i=1; i<len-1; i++)
    {
        if(i < j)                     // i<j保证只交换一次
            swap(F[i], F[j]);         // 交换下标互为反转的元素
        int k = len >> 1;
        while(j >= k)        // 由最高位检索,遇1变0,遇0变1
        {
            j -= k;
            k >>= 1;
        }
        if(j < k)
            j += k;
    }
}

// on=1时为DFT,on=-1时为IDFT
void FFT(complex F[], int len, int on)
{
    Rader(F, len);
    for(int h=2; h<=len; h<<=1)    //计算长度为h的DFT
    {
        complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));   //单位复根e^(2*PI/m),用欧拉公式展开
        for(int j=0; j<len; j+=h)
        {
            complex w(1,0);       //旋转因子
            for(int k=j; k<j+h/2; k++)
            {
                complex u = F[k];
                complex t = w * F[k + h/2];
                F[k] = u + t;        //蝴蝶合并操作
                F[k + h/2] = u - t;
                w = w * wn;          //更新旋转因子
            }
        }
    }
    if(on == -1)
    {
        for(int i=0; i<len; i++)
        {
            F[i].r /= len;
        }
    }
}

//求卷积
void Conv(complex a[], complex b[], int len)
{
    FFT(a, len, 1);
    FFT(b, len, 1);
    for(int i=0; i<len; i++)
    {
        a[i] = a[i] * b[i];         //卷积定理
    }
    FFT(a, len, -1);
}


char str1[N], str2[N];
complex a[N], b[N];
int result[N];
int len;

void Init(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    len = 1;
    while(len < 2*len1 || len < 2*len2) len <<= 1;     //将次数界变成2^n

    int i;
    for(i=0; i<len1; i++)   // 倒置存入
    {
        a[i].r = str1[len1-i-1] - '0';
        a[i].i = 0.0;
    }
    while(i < len)
    {
        a[i].r = a[i].i = 0.0;      //多余的初始化为0
        i++;
    }
    for(i=0; i<len2; i++)
    {
        b[i].r = str2[len2-i-1] - '0';
        b[i].i = 0.0;
    }
    while(i < len)
    {
        b[i].r = b[i].i = 0.0;
        i++;
    }
}

void Work()
{
    Conv(a, b, len);
    for(int i=0; i<len; i++)
    {
        result[i] = a[i].r + 0.5;    // 四舍五入
    }
}

void Export()
{
    for(int i=0; i<len; i++)    // 进位
    {
        result[i+1] += result[i]/10;
        result[i] %= 10;
    }
    int high = 0;
    for(int i=len-1; i>=0; i--)
    {
        if(result[i])    //检索最高位
        {
            high = i;
            break;
        }
    }
    for(int i = high; i>=0; i--)
    {
        printf("%d", result[i]);   //倒序输出
    }
    puts("");
}


int main()
{
    while(~scanf("%s%s", str1,str2))
    {
        Init(str1, str2);
        Work();
        Export();
    }
    return 0;
}
