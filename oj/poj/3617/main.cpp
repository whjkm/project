#include <stdio.h>
#include <string.h>
char s[2002];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
       for(int i=0;i<n;i++)
          scanf("\n%c",&s[i]);
       int a=0,b=n-1;
       int ans=0;
       while(a<=b)
       {
           bool left=false;
           for(int i=0;a+i<=b;i++)
           {
               if(s[a+i]<s[b-i])
               {
                   left=true;
                   break;
               }
               else if(s[a+i]>s[b-i])
               {
                   left=false;
                   break;
               }
           }
               if(left) printf("%c",s[a++]);
               else printf("%c",s[b--]);
                ans++;
               if(ans==80){
                printf("\n");
                ans=0;
               }
           }
       printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
char s[2002];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
       for(int i=0;i<n;i++)
          scanf("\n%c",&s[i]);//����ط��ο��˱��˵ģ��о�������ģ�ѧϰ�ˣ������������ʱ��ѻس���������������ʼ��������ط�һֱ                               // wa,����һ�����룬����Ҫ�������⡣
       int a=0,b=n-1;
       int ans=0; //��ǰûע�⣬�������䶨�嵽�����whileѭ�������ˣ�����һֱpe����
       while(a<=b)  //��λ�ַ����бȽ�
       {
           bool left=false;
           for(int i=0;a+i<=b;i++)
           {
               if(s[a+i]<s[b-i])
               {
                   left=true;
                   break;
               }
               else if(s[a+i]>s[b-i])
               {
                   left=false;
                   break;
               }
           }
               if(left) printf("%c",s[a++]);
               else printf("%c",s[b--]);
                ans++;
               if(ans==80){  //����ط��Ҳ�����һ��  ���д����������ӵĻ���ʱ�����16ms
                printf("\n");
                ans=0;
               }
               /*if(ans==80)
               {
                printf("\n");
                ans=0;
               }*/
           }
       printf("\n");
    }
    return 0;
}





/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

char s[4000];
int N;

int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
        {
            scanf("\n%c",&s[i]);
        }
       int start=0,end=N-1;
       int count=0;
        while(start<=end)
        {
            bool left = false;
            for(int i = 0; start + i<=end;i++)
            {
                if(s[start+i]<s[end-i])
                {
                    left=true;
                    break;
                }
                else if(s[start+i]>s[end-i])
                {
                    left=false;
                    break;
                }
            }
            if(!left)
            {
                printf("%c",s[end]);
                end--;
            }
            else
            {
                printf("%c",s[start]);
                start++;
            }
            count++;
            if(count==80){
                putchar('\n');
                count=0;
            }
        }
        putchar('\n');
    }
	return 0;
}
*/
