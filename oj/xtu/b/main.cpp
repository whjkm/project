/*#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long LL;
#define lch rt<<1,l,m
#define rch rt<<1|1,m+1,r
const int N = (int)1e5+100;
LL tree[N<<2];
int idx[N<<2], cnt[N];
int n, top;
void push_up(int rt){
    int lc = rt<<1, rc = rt<<1|1;
    if( (tree[lc]>tree[rc]) || ((tree[lc]==tree[rc])&&(cnt[idx[lc]]>cnt[idx[rc]]) ) )
        tree[rt] = tree[lc], idx[rt] = idx[lc];
    else tree[rt] = tree[rc], idx[rt] = idx[rc];
}
void build(int rt,int l,int r){
    tree[rt] = -1; idx[rt] = l;
    if( l == r ){ return; }
    int m = (l+r)>>1;
    build( lch ), build( rch );
    push_up( rt );
}
void update(int rt,int l,int r,int a,LL b, bool flag){
    if( l == r ){
        if(flag) tree[rt] = b;
        else tree[rt] += b;
        return;
    }
    int m = (l+r)>>1;
    if(a <= m) update( lch, a, b,flag );
    else update( rch, a, b,flag );
    push_up(rt);
}
int main(){
    while( scanf("%d", &n) != EOF ){
        if( n == 0 ) break;
        char op[2];
        int x, y, k = 1;
        bool flag = true;
        top = 0;
        memset( cnt, 0, sizeof(cnt));
        build( 1, 1, n  );
        for(int i = 0; i < n; i++){
            scanf("%s", op);
            switch( op[0] ){
                case 'N':
                    scanf("%d",&x); cnt[k] = ++top;
                    update(1,1,n,k++,x,true);
                    break;
                case 'I':
                    scanf("%d%d",&x,&y);
                    if( cnt[x] == -1 ) continue;
                    update(1,1,n,x,y,false); break;
                case 'D':
                    scanf("%d%d",&x,&y);
                    if( cnt[x] == -1 ) continue;
                    update(1,1,n,x,-y,false); break;
                case 'E':
                    scanf("%d", &x); cnt[x] = -1;
                    update(1,1,n,x,-1,true); break;
                case 'S':
                    if( flag ) flag = false;
                    else printf(" ");
                    printf("%d", idx[1] );
            }
        }
        puts("");
    }
    return 0;
}
*/

#include <stdio.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d\n",a+b);
    }
    return 0;
}
