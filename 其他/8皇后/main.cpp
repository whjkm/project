/*#include <cstdio>
#include <cmath>
#include <cstdlib>
const int maxn=8;
int queen[maxn],sum=0;
void print()
{
    printf("(");
    for(int i=0;i<maxn;i++)
    {
        printf(" %d",queen[i]);
    }
    printf(")\n");
    sum++;
}
int place(int n)
{
    for(int i=0;i<n;i++)
    {
        if(queen[i]==queen[n] || abs(queen[i]-queen[n])==(n-i))
            return 1;
    }
    return 0;
}
void nqueen(int n)
{
    for(int i=0;i<maxn;i++)
    {
        queen[n]=i;
            if(!place(n))
            {
                if(n==maxn-1)
                {
                    print();
                }
            else
            {
                nqueen(n+1);
            }
            }
    }
}
int main()
{
    nqueen(0);
    printf("%d\n",sum);
    return 0;
}
*/



/*#include <stdio.h>
#include <stdlib.h>
#define N 8
int column[N+1]; // ͬ���Ƿ��лʺ�1��ʾ��
int rup[2*N+1]; // �����������Ƿ��лʺ�
int lup[2*N+1]; // �����������Ƿ��лʺ�
int queen[N+1] = {0};
int num; // �����
void backtrack(int); // �ݻ����
int main(void)
{
    int i;
    num = 0;
    for(i = 1; i <= N; i++)
        column[i] = 1;
    for(i = 1; i <= 2*N; i++)
        rup[i] = lup[i] = 1;
    backtrack(1);
    return 0;
}
void showAnswer()
{
    int x, y;
    printf("\n��� %d\n", ++num);
    for(y = 1; y <= N; y++)
    {
        for(x = 1; x <= N; x++)
        {
            if(queen[y] == x)
            {
                printf(" Q");
            }
            else
            {
                printf(" .");
            }
        }
        printf("\n");
    }
}
void backtrack(int i)
{
    int j;
    if(i > N)
    {
        showAnswer();
    }
    else
    {
        for(j = 1; j <= N; j++)
        {
            if(column[j] == 1 && rup[i+j] == 1 && lup[i-j+N] == 1)
            {
                queen[i] = j;   // �趨Ϊռ��
                column[j] = rup[i+j] = lup[i-j+N] = 0;
                backtrack(i+1);
                column[j] = rup[i+j] = lup[i-j+N] = 1;
            }
        }
    }
}
*/

/*#include<iostream>
using namespace std;
#define N 8
//N����ʺ���
void queen()
{
    int Count=0;         //�����ܹ��Ľ������
    int column[N+1];     //column[m]=n��ʾ��m�У���n�з����˻ʺ�,�����±���0��ʼ
    int row[N+1];        //row[m]=1��ʾ��m��û�лʺ�=0��ʾ�лʺ�
    int b[2*N+1];        //b[m]=1��ʾ��m�����Խ���û�лʺ�
    int c[2*N+1];        //c[m]=1��ʾ��m���ζԽ���û�лʺ�=0��ʾ�лʺ�
    int numQueen=1;      //�����Ѿ����õĻʺ���Ŀ����numQueen=Nʱ�����ʾ�Ѿ����̽��
    int good=1;          //good=1��ʾû�з�����ͻ,good=0��ʾ������ͻ

    //��ʼ����Щ���
    for(int j=0;j<N+1;++j)
    {
        row[j]=1;
    }
    for(int j=0;j<2*N+1;++j)
    {
        b[j]=c[j]=1;
    }
    column[1]=1;
    column[0]=0;          //��ʼ����һ�е�һ�У��ڶ��еڶ��з��ûʺ�
    do
    {
        //û�з�����ͻ�����������̽�⣬���ӻʺ�����жϵ�ǰ�Ƿ��ǽ�
        if(good)
        {
            //��ǰ�ʺ����ǽ⣬��ӡ����������̽��
            if(numQueen==N)
            {
                Count++;
                cout<<"�ҵ���"<<endl;
                for(int j=1;j<N+1;++j)
                {
                    cout<<j<<"��"<<column[j]<<"��"<<endl;
                }
                //���һ�����������ƶ�,�ƶ����������һ��
                while(column[numQueen]==N)
                {
                    numQueen--;         //�ʺ�����1����������1������
                    //���ݺ󽫸����Լ��������һ��״̬λ�޸�
                    //��numQueen��column[numQueen]�д�״̬λ���޸�
                    row[column[numQueen]]=1;
                    b[numQueen+column[numQueen]]=1;
                    c[N+numQueen-column[numQueen]]=1;
                }
                column[numQueen]++;     //��������һ�У�����һ�е���һ�м���̽��
            }
            //��ǰ���ǽ⣬��ô��������̽��
            else
            {
                //�ı��λ�ö�Ӧ��־
                row[column[numQueen]]=0;
                b[numQueen+column[numQueen]]=0;
                c[N+numQueen-column[numQueen]]=0;
                //����λ��û�з�����ͻ��Ҳ������ȷ�⣬��ô��Ӧ������̽����һ�еĵ�һ��
                column[++numQueen]=1;
            }
        }
        //�����ǰ�����˳�ͻ�����ڱ��м������£�������˱������һ�У�����ݵ���һ��
        else
        {
            while(column[numQueen]==N) //���˱������һ�У����ǳ�ͻ����ô���ݵ���һ��
            {
                numQueen--;
                row[column[numQueen]]=1;
                b[numQueen+column[numQueen]]=1;
                c[N+numQueen-column[numQueen]]=1;
            }
            column[numQueen]++; //������ͻ�ˣ���û�е����е����һ�У���ô�ڱ��м�������һ��̽��
        }
        //�����������λ�ú��Ƿ��ͻ
        good=row[column[numQueen]]&b[numQueen+column[numQueen]]&c[N+numQueen-column[numQueen]];
    }while(numQueen);
    cout<<N<<"�ʺ��ܹ��ҵ��⣺"<<Count<<"��"<<endl;
}
int main()
{
    queen();
   // system("pause");
   return 0;
}
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
const int maxn=8;
int queen[maxn],sum=0;//����ÿһ�лʺ��λ��
void print()
{
    int i;
    printf("(");
    for(i = 0; i < maxn; i++)
    {
         printf(" %d", queen[i]);
    }
    printf(")\n");
    sum++;//��¼�ⷨ������
}
bool check(int n)//�жϵ�ǰ���Ƿ��ܷ��ûʺ�
{
     for(int i=0;i<n;i++)
     {
         if(queen[i]==queen[n] || abs(queen[n]-queen[i])==abs(n-i))//�ж��У��Խ���
            return false;
     }
     return true;
}
void nqueen(int n)//���ݵݹ�
{
    for(int i=0;i<maxn;i++)
    {
        queen[n]=i;//�ѻʺ�ڵ���ǰ��λ��
        if(check(n))
        {
            if(n==maxn-1)//˵���ڷųɹ�
            {
                print();
            }
            else
                nqueen(n+1);
        }
    }
}
int main()
{
    nqueen(0);
    printf("%d\n",sum);
}
