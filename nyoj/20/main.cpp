/*#include <stdlib.h>
#include <stdio.h>
int main()
{
   int t,n,s,a,b;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d",&n,&s);
       for(i=0;i<n;i++)
         scanf("%d%d",&a,&b);
   }
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100010
struct node{
    int num;
    struct node *next;
}set[N];
int parent[N];
void build(int a, int b){
	struct node *p=(struct node *)malloc(sizeof(struct node));
    p->num=b;
    p->next=set[a].next;//倒插法
    set[a].next=p;
}
void dfs(int s0,int s){
	struct node *p;
	parent[s]=s0;
    for(p=set[s].next; p!=NULL; p=p->next){
        if(parent[p->num]==0){//我哩个去，把条件写在了循环条件上面，调试了一个多小时。。。
            dfs(s,p->num);
        }
    }
}
int main(){
    int T,n,s,a,b,i;
    scanf("%d",&T);
    while(T--){
        memset(set,0,sizeof(set));
        memset(parent,0,sizeof(parent));
        scanf("%d %d",&n,&s);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&a,&b);
            build(a,b);
            build(b,a);
        }
        dfs(-1,s);
        for(i=1;i<n;i++){
            printf("%d ",parent[i]);
        }
		printf("%d\n",parent[i]);
    }
    return 0;
}

/*
1
10 1
1 9
1 8
8 10
10 3
8 6
1 2
10 4
9 5
3 7


-1 1 10 10 9 8 3 1 1 8


10 8
1 9
1 8
8 10
10 3
8 6
1 2
10 4
9 5
3 7

*/
