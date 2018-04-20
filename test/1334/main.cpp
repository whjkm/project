#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char name[101][4];
    int n,i,q,p,left,right;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%s",name[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&p);
        left=right=p;
        if(name[p][0]!='?') printf("%s\n",name[p]);
        else
        {
            while(1)
            {
                if(left-1>0)
                    left=left-1;
                if(right+1<=n)
                    right=right+1;
                if(name[left][0]!='?' && name[right][0]!='?')
                {
                    printf("middle of %s and %s\n",name[left],name[right]);
                    break;
                }
                 if(name[left][0]=='?' && name[right][0]!='?')
                {
                     for(i=1;i<=right-p;i++)
                        printf("left of ");
                        printf("%s\n",name[right]);
                      break;
                }
                if(name[left][0]!='?' && name[right][0]=='?')
                {
                     for(i=1;i<=p-left;i++)
                        printf("right of ");
                        printf("%s\n",name[left]);
                      break;
                }
            }
        }
    }
    return 0;
}
