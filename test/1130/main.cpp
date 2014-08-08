/*#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
const int N = 100000;
int key[N], lefts[N], rights[N], size[N];
int u;//根结点
int node;
inline void Left_Rotate(int &x)
{
    int k = rights[x];
    rights[x] = lefts[k];
    lefts[k] = x;
    size[k] = size[x];
    size[x] = size[lefts[x]] + size[rights[x]] + 1;
    x = k;
}
inline void Right_Rotate(int &y)
{
    int k = lefts[y];
    lefts[y] = rights[k];
    rights[k] = y;
    size[k] = size[y];
    size[y] = size[lefts[y]] + size[rights[y]] + 1;
    y = k;
}
void Maintain(int &u, bool flag)//维护
{
    if(flag == false)
    {
        if(size[lefts[lefts[u]]] > size[rights[u]])
            Right_Rotate(u);
        else
        {
            if(size[rights[lefts[u]]] > size[rights[u]])
            {
                Left_Rotate(lefts[u]);
                Right_Rotate(u);
            }
            else return;
        }
    }
    else
    {
        if(size[rights[rights[u]]] > size[lefts[u]])
            Left_Rotate(u);
        else
        {
            if(size[lefts[rights[u]]] > size[lefts[u]])
            {
                Right_Rotate(rights[u]);
                Left_Rotate(u);
            }
            else return;
        }
    }
    Maintain(lefts[u], false);
    Maintain(rights[u], true);
    Maintain(u, true);
    Maintain(u, false);
}
void Insert(int &u, int v)//插入结点
{
    if(u == 0)
    {
        key[u = ++node] = v;
        size[u] = 1;
    }
    else
    {
        size[u]++;
        if(v < key[u])
            Insert(lefts[u], v);
        else
            Insert(rights[u], v);
        Maintain(u, v >= key[u]);
    }
}

int Delete(int &u, int v)//删除结点
{
    size[u]--;
    if( (v == key[u]) || (v < key[u] && lefts[u] == 0) || (v > key[u] && rights[u] == 0) )
    {
        int r = key[u];
        if(lefts[u] == 0 || rights[u] == 0)
            u = lefts[u] + rights[u];
        else
            key[u] = Delete(lefts[u], key[u] + 1);
        return r;
    }
    else
    {
        if(v < key[u])
            return Delete(lefts[u], v);
        else
            return Delete(rights[u], v);
    }
}
int Search(int x, int k)//查询
{
    if(x == 0 || k == key[x])
        return x;
    if(k < key[x])
        return Search(lefts[x], k);
    else
        return Search(rights[x], k);
}

int Select(int u, int k)//返回树在第k位置上的结点值
{
    int r = size[lefts[u]] + 1;
    if(k == r)
        return key[u];
    else if(k < r)
        return Select(lefts[u], k);
    else
        return Select(rights[u], k - r);
}
int Successor(int u, int k)//查询结点k的后继
{
    if(u == 0)
        return k;
    if(key[u] <= k)
        return Successor(rights[u], k);
    else
    {
        int r = Successor(lefts[u], k);
        if(r == k)
            return key[u];
        else
            return r;
    }
}
int Predecessor(int u, int k)//查询结点k的前驱
{
    if(u == 0)
        return k;
    if(key[u] >= k)
        return Predecessor(lefts[u], k);
    else
    {
        int r = Predecessor(rights[u], k);
        if(r == k)
            return key[u];
        else
            return r;
    }
}
int Rank(int u, int k)//排名(rank),也叫秩,求整棵树中从大到小排序的第k位元素;
{
    if(u==0)
        return 1;
    if(key[u] >= k)
        return Rank(lefts[u], k);
    else
        return size[lefts[u]] + Rank(rights[u], k) + 1;
}
int main()
{
    int n,k,m;
    char s[5];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='I')
            {
                scanf("%d",&m);
                Insert(u,m);
            }
            else
            {
                printf("%d\n",Rank(u,k));
            }
        }
    }
    return 0;
}
*/
/*#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n,k,m;
    char s[5];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='I')
            {
                scanf("%d",&m);
                if(q.size()<k)
                    q.push(m);
                else if(m>q.top())
                {
                    q.pop();
                    q.push(m);
                }
            }
            else
            {
                printf("%d\n",q.top());
            }
        }
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
int heap[1000010],size;
void down(int r)
{
   while(r<size)
   {
       int son=r*2;
       if(son+1<=size)
        son=heap[son]>heap[son+1]?son+1:son;
       if(son<=size && heap[r]>heap[son])  swap(heap[r],heap[son]);
       else return;
       r=son;
   }
}
void up(int r)
{
    while(r!=1)
    {
        if(heap[r]<heap[r/2]) swap(heap[r],heap[r/2]);
        else break;
        r>>=1;
    }
}
void heap_push(int k)
{
    heap[++size]=k;
    up(size);
}
void heap_pop()
{
    heap[1]=heap[size--];
    down(1);
}
int main()
{
    int n,k,m;
    char s[5];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        size=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='I')
            {
                scanf("%d",&m);
                heap_push(m);
                if(size>k) heap_pop();
            }
            else
            {
                printf("%d\n",heap[1]);
            }
        }
    }
    return 0;
}
