#include <cstdio>
#include <cstring>
typedef struct
{
    int A;
    int B;
    int C;
} Resource;
const int m=5; //���̸���
Resource Available;//�����õ���Դ
Resource Max[m];//�������
Resource Allocation[m];//��ǰ�ѷ������Դ
Resource Need[m];//����Ҫ�ĸ�����Դ
int safeseq[m]; //��ȫ����

void init()//��ʼ��
{
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&Allocation[i].A,&Allocation[i].B,&Allocation[i].C);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&Max[i].A,&Max[i].B,&Max[i].C);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&Need[i].A,&Need[i].B,&Need[i].C);
    scanf("%d%d%d",&Available.A,&Available.B,&Available.C);
}
void Probealloc(int process,Resource *res)//��̽����
{
    Available.A-=res->A;
    Available.B-=res->B;
    Available.C-=res->C;

    Allocation[process].A+=res->A;
    Allocation[process].B+=res->B;
    Allocation[process].C+=res->C;

    Need[process].A-=res->A;
    Need[process].B-=res->B;
    Need[process].C-=res->C;
}
void rollbock(int process,Resource *res)//������ʧ�ܾͽ��лع�
{
    Available.A+=res->A;
    Available.B+=res->B;
    Available.C+=res->C;

    Allocation[process].A-=res->A;
    Allocation[process].B-=res->B;
    Allocation[process].C-=res->C;

    Need[process].A+=res->A;
    Need[process].B+=res->B;
    Need[process].C+=res->C;
}
bool security()//��ȫ���㷨
{
    Resource work=Available;
    bool finish[m]= {false,false,false,false,false};
    int i,j=0;
    for(i=0; i<m; i++)
    {
        if(finish[i]==false)
        {
            if(Need[i].A<=work.A&&Need[i].B<=work.B&&Need[i].C<=work.C)
            {
                work.A+=Allocation[i].A;
                work.B+=Allocation[i].B;
                work.C+=Allocation[i].C;
                finish[i]=true;
                safeseq[j++]=i;
                i=-1;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        if(finish[i]==false)
            return false;
    }
    return true;
}
bool banker(int process,Resource *res)
{
    if(res->A<=Need[process].A && res->B<=Need[process].B &&res->C<=Need[process].C)
    {
        if(res->A<=Available.A && res->B<=Available.B &&res->C<=Available.C)
        {
            Probealloc(process,res);
            if(security())
            {
                return true;
            }
            else
            {
                printf("����ʧ��,ԭ��ϵͳ�����벻��ȫ״̬���п�������������\n");
                rollbock(process,res);
            }
        }
        else
        {
            printf("��ȫ�Լ��ʧ�ܡ�ԭ�������������ڿ�������Դ������\n");
        }
    }
    else
    {
        printf("��ȫ�Լ��ʧ�ܡ�ԭ������������������������\n");
    }
    return false;
}
void PrintTable()
{
    printf("\t\t\t*********��Դ�����*********\n");
    printf("Process       Max          Allocation          Need          Available\n");
    printf("          A    B    C     A    B    C       A    B    C      A    B    C\n");
    printf("  P0      %d    %d    %d     %d    %d    %d       %d    %d    %d      %d    %d    %d\n",Max[0].A,Max[0].B,Max[0].C,Allocation[0].A,Allocation[0].B,Allocation[0].C,Need[0].A,Need[0].B,Need[0].C,Available.A,Available.B,Available.C);
    printf("  P1      %d    %d    %d     %d    %d    %d       %d    %d    %d\n",Max[1].A,Max[1].B,Max[1].C,Allocation[1].A,Allocation[1].B,Allocation[1].C,Need[1].A,Need[1].B,Need[1].C);
    printf("  P2      %d    %d    %d     %d    %d    %d       %d    %d    %d\n",Max[2].A,Max[2].B,Max[2].C,Allocation[2].A,Allocation[2].B,Allocation[2].C,Need[2].A,Need[2].B,Need[2].C);
    printf("  P3      %d    %d    %d     %d    %d    %d       %d    %d    %d\n",Max[3].A,Max[3].B,Max[3].C,Allocation[3].A,Allocation[3].B,Allocation[3].C,Need[3].A,Need[3].B,Need[3].C);
    printf("  P4      %d    %d    %d     %d    %d    %d       %d    %d    %d\n",Max[4].A,Max[4].B,Max[4].C,Allocation[4].A,Allocation[4].B,Allocation[4].C,Need[4].A,Need[4].B,Need[4].C);
    printf("\n");
}
int main()
{
    init();
    while(1)
    {
        char ch;
        printf("�ȼ���ʼ״̬�Ƿ�ȫ��\n");
        if(security())
        {
            printf("��ǰ���ڰ�ȫ״̬:\n");
            printf("��ȫ������{P%d,P%d,P%d,P%d,P%d}��\n",safeseq[0],safeseq[1],safeseq[2],safeseq[3],safeseq[4]);
        }
        else
        {
            printf("ϵͳ���ڲ���ȫ״̬�������˳�...\n");
            break;
        }
        do
        {
            int process;
            Resource res;
            PrintTable();
            printf("�����������������Ľ��̺Ͷ�������Դ������������");
            scanf("%d%d%d%d",&process,&res.A,&res.B,&res.C);
            if(banker(process,&res))
            {
                printf("����ɹ���\n");
                printf("��ȫ������{P%d,P%d,P%d,P%d,P%d}��\n",safeseq[0],safeseq[1],safeseq[2],safeseq[3],safeseq[4]);
            }
            else
            {
                printf("����ʧ�ܡ�\n");
            }
            printf("�Ƿ�������䣿(Y/N):");
            fflush(stdin);
            ch=getchar();
        }
        while(ch=='y' || ch=='Y');
    }
    return 0;
}





/*#include <string.h>
#include <stdio.h>
#include <iostream.h>
#define FALSE 0
#define TRUE 1
#define W 10
#define R 10
int M ; // �ܽ�����
int N ; // ��Դ����
int ALL_RESOURCE[W];// ������Դ����Ŀ�ܺ�
int MAX[W][R]; // M�����̶�N����Դ�����Դ������
int AVAILABLE[R]; // ϵͳ������Դ��
int ALLOCATION[W][R]; // M�������Ѿ��õ�N����Դ����Դ��
int NEED[W][R]; // M�����̻���ҪN����Դ����Դ��
int Request[R]; // ������Դ����
void output()
{
    int i,j;
    cout<<endl<<"������������������������������������"<<endl;
    cout<<"������Դ��������:"<<endl;
    for (j=0; j<N; j++)
        cout<<" ��Դ"<<j<<": "<<ALL_RESOURCE[j];
    cout<<endl;
    cout<<"������������������������������������"<<endl;
    cout<<"Ŀǰ������Դ�����õ�����Ϊ:"<<endl;
    for (j=0; j<N; j++)           cout<<" ��Դ"<<j<<": "<<AVAILABLE[j];
    cout<<endl;
    cout<<"������������������������������������"<<endl;
    cout<<"�����̻���Ҫ����Դ����:"<<endl<<endl;
    for(i=0; i<N; i++)       cout<<"        ��Դ"<<i;
    cout<<endl;
    for (i=0; i<M; i++)
    {
        cout<<"����"<<i<<":   ";
        for (j=0; j<N; j++)       cout<<NEED[i][j]<<"         ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"������������������������������������"<<endl;
    cout<<"�������Ѿ��õ�����Դ��: "<<endl<<endl;
    for(i=0; i<N; i++)       cout<<"        ��Դ"<<i;
    cout<<endl;
    for (i=0; i<M; i++)
    {
        cout<<"����"<<i<<":    ";
        for (j=0; j<N; j++)
            cout<<ALLOCATION[i][j]<<"         ";
        cout<<endl;
    }
    cout<<endl;
}
void distribute(int k)
{
    int j;
    for (j=0; j<N; j++)
    {
        AVAILABLE[j]=AVAILABLE[j]-Request[j];
        ALLOCATION[k][j]=ALLOCATION[k][j]+Request[j];
        NEED[k][j]=NEED[k][j]-Request[j];
    }
}
void restore(int k)
{
    int j;
    for (j=0; j<N; j++)
    {
        AVAILABLE[j]=AVAILABLE[j]+Request[j];
        ALLOCATION[k][j]=ALLOCATION[k][j]-Request[j];
        NEED[k][j]=NEED[k][j]+Request[j];
    }
}
int check()
{
    int WORK[R],FINISH[W];
    int i,j;
    for(j=0; j<N; j++) WORK[j]=AVAILABLE[j];
    for(i=0; i<M; i++) FINISH[i]=FALSE;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            if(FINISH[i]==FALSE&&NEED[i][j]<=WORK[j])
            {
                WORK[j]=WORK[i]+ALLOCATION[i][j];
            }
        }
        FINISH[i]=TRUE;
    }
    for(i=0; i<M; i++)
    {
        if(FINISH[i]==FALSE)
        {
            cout<<endl;
            cout<<" ϵͳ����ȫ!!! ������Դ���벻�ɹ�!!!"<<endl;
            cout<<endl;
            return 1;
        }
        else
        {
            cout<<endl;
            cout<<" ����ȫ�Լ�飬ϵͳ��ȫ�����η���ɹ���"<<endl;
            cout<<endl;
            return 0;
        }
    }
}
void bank()   // ���м��㷨
{
    int i=0,j=0;
    char flag='Y';
    while(flag=='Y'||flag=='y')
    {
        i=-1;
        while(i<0||i>=M)
        {
            cout<<"������������������������������������"<<endl;
            cout<<endl<<" ��������������Դ�Ľ��̺�:";
            cin>>i;
            if(i<0||i>=M)  cout<<" ����Ľ��̺Ų����ڣ���������!"<<endl;
        }
        cout<<" ���������"<<i<<"���������Դ������:"<<endl;
        for (j=0; j<N; j++)
        {
            cout<<" ��Դ"<<j<<": ";
            cin>>Request[j];
            if(Request[j]>NEED[i][j]) // ���������Դ�����ڽ��̻���Ҫi����Դ����Դ��j
            {
                cout<<endl<<" ����"<<i<<"�������Դ�����ڽ���"<<i<<"����Ҫ"<<j<<"����Դ������!";
                cout<<" ������ִ��ϵͳ�����ڲ���ȫ״̬!"<<endl;
                flag='N';
                break;
            }
            else
            {
                if(Request[j]>AVAILABLE[j]) // ���������Դ�����ڿ�����Դ��
                {
                    cout<<endl<<" ����"<<i<<"�������Դ������ϵͳ����"<<j<<"����Դ������!";
                    cout<<" ������ִ��ϵͳ�����ڲ���ȫ״̬!"<<endl;
                    flag='N';
                    break;
                }
            }
        }
        if(flag=='Y'||flag=='y')
        {
            distribute(i); // ����change(i)�������ı���Դ��
            if(check()) // ��ϵͳ��ȫ
            {
                restore(i); // ����restore(i)�������ָ���Դ��
                output();   // �����Դ�������          }
                else       // ��ϵͳ����ȫ
                    output(); // �����Դ�������      }
                else      // ��flag=N||flag=n
                    cout<<endl;
                cout<<" �Ƿ�������м��㷨��ʾ,��'Y'��'y'������,��'N'��'n'���˳���ʾ: ";
                cin>>flag;
            }
        }
        void version()
        {
            cout<<endl;
            cout<<"\t      ������������ ���� �� �� �� ���� ��������������"<<endl;
        }
        void main() // ������
        {
            int i=0,j=0,p;
            version();
            getchar();
            cout<<endl<<"�������ܽ�����:";
            cin>>M;
            cout<<endl<<"������������������������������������"<<endl;
            cout<<"����������Դ����:";
            cin>>N;
            cout<<endl<<"������������������������������������"<<endl;
            cout<<"�����������Դ����:(��Ҫ������Ϊ"<<N<<"��)";
            for(i=0; i<N; i++)
                cin>>ALL_RESOURCE[i];
            cout<<endl<<"������������������������������������"<<endl;
            cout<<"�������������Ҫ�ĸ�����Դ���������:(��Ҫ������Ϊ"<<M*N<<"��)";
            for (i=0; i<M; i++)
            {
                for (j=0; j<N; j++)
                {
                    do
                    {
                        cin>>MAX[i][j];
                        if (MAX[i][j]>ALL_RESOURCE[j])
                            cout<<endl<<"ռ����Դ�����������ĸ���Դ����,����������"<<endl;
                    }
                    while (MAX[i][j]>ALL_RESOURCE[j]);
                }
            }
            cout<<endl<<"������������������������������������"<<endl;
            cout<<"����������Ѿ�ռ�ݵĸ�����Դ������:(��Ҫ������Ϊ"<<M	  *N<<"��)";
            for (i=0; i<M; i++)
            {
                for (j=0; j<N; j++)
                {
                    do
                    {
                        cin>>ALLOCATION[i][j];
                        if (ALLOCATION[i][j]>MAX[i][j])
                            cout<<endl<<"ռ����Դ�����������������Դ,����������"<<endl;
                    }
                    while (ALLOCATION[i][j]>MAX[i][j]);
                }
            }
            for (j=0; j<N; j++) // ��ʼ����Դ����
            {
                p=ALL_RESOURCE[j];
                for (i=0; i<M; i++)
                {
                    p=p-ALLOCATION[i][j];// ��ȥ�Ѿ���ռ�ݵ���Դ
                    AVAILABLE[j]=p;
                    if(AVAILABLE[j]<0)      AVAILABLE[j]=0;
                }
            }
            for (i=0; i<M; i++)
                for(j=0; j<N; j++)
                    NEED[i][j]=MAX[i][j]-ALLOCATION[i][j];
            output();
            bank();
        }
*/
