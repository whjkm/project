#include <cstdio>
#include <cstring>
/*int calculation(int a,int b,int c)
{
    int ans=1;
    int m=a%c;
    while(b>0)
    {
        if(b%2==1)
            ans=(m*ans)%c;
        b=b/2;
        m=(m*m)%c;
    }
    ans=ans%c;
    return ans;
}*/
int calculation(int a,int b,int c)//�ֱ�Ϊ������ָ����ȡ����
{
    int ans=1;//����
    while(b>0)
    {
        if(b%2==1) //���������
            ans=(a*ans)%c;
        b=b/2;
        a=(a*a)%c;
    }
    return ans;
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",calculation(a,b,c));
    return 0;
}
