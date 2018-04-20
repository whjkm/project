#include <cstdio>
#include <cstring>
typedef struct
{
    int A;
    int B;
    int C;
} Resource;
const int m=5; //进程个数
Resource Available;//可利用的资源
Resource Max[m];//最大需求
Resource Allocation[m];//当前已分配的资源
Resource Need[m];//还需要的各种资源
int safeseq[m]; //安全序列

void init()//初始化
{
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&Allocation[i].A,&Allocation[i].B,&Allocation[i].C);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&Max[i].A,&Max[i].B,&Max[i].C);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&Need[i].A,&Need[i].B,&Need[i].C);
    scanf("%d%d%d",&Available.A,&Available.B,&Available.C);
}
void Probealloc(int process,Resource *res)//试探分配
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
void rollbock(int process,Resource *res)//若分配失败就进行回滚
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
bool security()//安全性算法
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
                printf("分配失败,原因：系统将进入不安全状态，有可能引起死锁。\n");
                rollbock(process,res);
            }
        }
        else
        {
            printf("安全性检查失败。原因：请求向量大于可利用资源向量。\n");
        }
    }
    else
    {
        printf("安全性检查失败。原因：请求向量大于需求向量。\n");
    }
    return false;
}
void PrintTable()
{
    printf("\t\t\t*********资源分配表*********\n");
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
        printf("先检查初始状态是否安全：\n");
        if(security())
        {
            printf("当前处于安全状态:\n");
            printf("安全序列是{P%d,P%d,P%d,P%d,P%d}。\n",safeseq[0],safeseq[1],safeseq[2],safeseq[3],safeseq[4]);
        }
        else
        {
            printf("系统处于不安全状态。程序将退出...\n");
            break;
        }
        do
        {
            int process;
            Resource res;
            PrintTable();
            printf("请依次输入请求分配的进程和对三类资源的请求数量：");
            scanf("%d%d%d%d",&process,&res.A,&res.B,&res.C);
            if(banker(process,&res))
            {
                printf("分配成功。\n");
                printf("安全序列是{P%d,P%d,P%d,P%d,P%d}。\n",safeseq[0],safeseq[1],safeseq[2],safeseq[3],safeseq[4]);
            }
            else
            {
                printf("分配失败。\n");
            }
            printf("是否继续分配？(Y/N):");
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
int M ; // 总进程数
int N ; // 资源种类
int ALL_RESOURCE[W];// 各种资源的数目总和
int MAX[W][R]; // M个进程对N类资源最大资源需求量
int AVAILABLE[R]; // 系统可用资源数
int ALLOCATION[W][R]; // M个进程已经得到N类资源的资源量
int NEED[W][R]; // M个进程还需要N类资源的资源量
int Request[R]; // 请求资源个数
void output()
{
    int i,j;
    cout<<endl<<"━━━━━━━━━━━━━━━━━━"<<endl;
    cout<<"各种资源的总数量:"<<endl;
    for (j=0; j<N; j++)
        cout<<" 资源"<<j<<": "<<ALL_RESOURCE[j];
    cout<<endl;
    cout<<"━━━━━━━━━━━━━━━━━━"<<endl;
    cout<<"目前各种资源可利用的数量为:"<<endl;
    for (j=0; j<N; j++)           cout<<" 资源"<<j<<": "<<AVAILABLE[j];
    cout<<endl;
    cout<<"━━━━━━━━━━━━━━━━━━"<<endl;
    cout<<"各进程还需要的资源数量:"<<endl<<endl;
    for(i=0; i<N; i++)       cout<<"        资源"<<i;
    cout<<endl;
    for (i=0; i<M; i++)
    {
        cout<<"进程"<<i<<":   ";
        for (j=0; j<N; j++)       cout<<NEED[i][j]<<"         ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"━━━━━━━━━━━━━━━━━━"<<endl;
    cout<<"各进程已经得到的资源量: "<<endl<<endl;
    for(i=0; i<N; i++)       cout<<"        资源"<<i;
    cout<<endl;
    for (i=0; i<M; i++)
    {
        cout<<"进程"<<i<<":    ";
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
            cout<<" 系统不安全!!! 本次资源申请不成功!!!"<<endl;
            cout<<endl;
            return 1;
        }
        else
        {
            cout<<endl;
            cout<<" 经安全性检查，系统安全，本次分配成功。"<<endl;
            cout<<endl;
            return 0;
        }
    }
}
void bank()   // 银行家算法
{
    int i=0,j=0;
    char flag='Y';
    while(flag=='Y'||flag=='y')
    {
        i=-1;
        while(i<0||i>=M)
        {
            cout<<"━━━━━━━━━━━━━━━━━━"<<endl;
            cout<<endl<<" 请输入需申请资源的进程号:";
            cin>>i;
            if(i<0||i>=M)  cout<<" 输入的进程号不存在，重新输入!"<<endl;
        }
        cout<<" 请输入进程"<<i<<"申请各类资源的数量:"<<endl;
        for (j=0; j<N; j++)
        {
            cout<<" 资源"<<j<<": ";
            cin>>Request[j];
            if(Request[j]>NEED[i][j]) // 若请求的资源数大于进程还需要i类资源的资源量j
            {
                cout<<endl<<" 进程"<<i<<"申请的资源数大于进程"<<i<<"还需要"<<j<<"类资源的数量!";
                cout<<" 若继续执行系统将处于不安全状态!"<<endl;
                flag='N';
                break;
            }
            else
            {
                if(Request[j]>AVAILABLE[j]) // 若请求的资源数大于可用资源数
                {
                    cout<<endl<<" 进程"<<i<<"申请的资源数大于系统可用"<<j<<"类资源的数量!";
                    cout<<" 若继续执行系统将处于不安全状态!"<<endl;
                    flag='N';
                    break;
                }
            }
        }
        if(flag=='Y'||flag=='y')
        {
            distribute(i); // 调用change(i)函数，改变资源数
            if(check()) // 若系统安全
            {
                restore(i); // 调用restore(i)函数，恢复资源数
                output();   // 输出资源分配情况          }
                else       // 若系统不安全
                    output(); // 输出资源分配情况      }
                else      // 若flag=N||flag=n
                    cout<<endl;
                cout<<" 是否继续银行家算法演示,按'Y'或'y'键继续,按'N'或'n'键退出演示: ";
                cin>>flag;
            }
        }
        void version()
        {
            cout<<endl;
            cout<<"\t      　　　　　　 　银 行 家 算 法　 　　　　　　　"<<endl;
        }
        void main() // 主函数
        {
            int i=0,j=0,p;
            version();
            getchar();
            cout<<endl<<"请输入总进程数:";
            cin>>M;
            cout<<endl<<"━━━━━━━━━━━━━━━━━━"<<endl;
            cout<<"请输入总资源种类:";
            cin>>N;
            cout<<endl<<"━━━━━━━━━━━━━━━━━━"<<endl;
            cout<<"请输入各类资源总数:(需要输入数为"<<N<<"个)";
            for(i=0; i<N; i++)
                cin>>ALL_RESOURCE[i];
            cout<<endl<<"━━━━━━━━━━━━━━━━━━"<<endl;
            cout<<"输入各进程所需要的各类资源的最大数量:(需要输入数为"<<M*N<<"个)";
            for (i=0; i<M; i++)
            {
                for (j=0; j<N; j++)
                {
                    do
                    {
                        cin>>MAX[i][j];
                        if (MAX[i][j]>ALL_RESOURCE[j])
                            cout<<endl<<"占有资源超过了声明的该资源总数,请重新输入"<<endl;
                    }
                    while (MAX[i][j]>ALL_RESOURCE[j]);
                }
            }
            cout<<endl<<"━━━━━━━━━━━━━━━━━━"<<endl;
            cout<<"输入各进程已经占据的各类资源的数量:(需要输入数为"<<M	  *N<<"个)";
            for (i=0; i<M; i++)
            {
                for (j=0; j<N; j++)
                {
                    do
                    {
                        cin>>ALLOCATION[i][j];
                        if (ALLOCATION[i][j]>MAX[i][j])
                            cout<<endl<<"占有资源超过了声明的最大资源,请重新输入"<<endl;
                    }
                    while (ALLOCATION[i][j]>MAX[i][j]);
                }
            }
            for (j=0; j<N; j++) // 初始化资源数量
            {
                p=ALL_RESOURCE[j];
                for (i=0; i<M; i++)
                {
                    p=p-ALLOCATION[i][j];// 减去已经被占据的资源
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
