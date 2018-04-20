/*#include <iostream>
#include <cstdio>
using namespace std;
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
				j--;
            if(i < j)
				s[i++] = s[j];

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
				i++;
            if(i < j)
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ����
        quick_sort(s, i + 1, r);
    }
}
int main()
{
    int a[10]={2,6,4,7,9,10,3,8,5,1};
    printf("����ǰ:\n");
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    quick_sort(a,0,9);
    printf("�����:\n");
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}
*/
#include <iostream>
#include <cstdio>
using namespace std;
int greedySelector(int s[],int f[],int b[])  //  �㷨
{
    b[0]=true;
    int j=0;
    int i=1;
    int count=0;
    for(i=1;i<=5;i++)
    {
        if(s[i]>f[j])
        {
            b[i]=true;
            j=i;
            count++;    //��¼�����
         }
        }
        else
            b[i]=false;  //������
    }
    printf("active number is %d\n",count);
    for(i=0;i<5;i++)
    {
        if(b[i]==1)
            printf("%d ",i+1);
    }
    return 0;
}
int main()
{
    int s[5]= {1,4,2,5,3};
    int f[5]= {2,5,3,6,4};
    int b[5];
    int sum;
    sum=greedySelector(s,f,b);
    return 0;
}
