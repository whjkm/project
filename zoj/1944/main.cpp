#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node
{
    char value;
    node *lchild,*rchild;
};
node *newnode(char c)
{
    node *p;
    p=(node *)malloc(sizeof(node));
    p->value=c;
    p->lchild=p->rchild=NULL;
    return p;
}
node *rebulid(char *pre,char *in,int n)
{
    if(n==0) return NULL;
    int l_len,r_len,i;
    char s=pre[0];
    node *root=newnode(s);
    for(i=0;i<n&&in[i]!=s;i++);
    l_len=i;
    r_len=n-i-1;
    if(l_len>0) root->lchild=rebulid(pre+1,in,l_len);
    if(r_len>0) root->rchild=rebulid(pre+l_len+1,in+l_len+1,r_len);
    return root;
}
void postorder(node *p)
{
    if(p==NULL) return;
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%c",p->value);
}
int main()
{
    char preorder[30],inorder[30];
    while(scanf("%s%s",preorder,inorder)!=EOF)
    {
        node *root=rebulid(preorder,inorder,strlen(preorder));
        postorder(root);
        printf("\n");
    }
    return 0;
}
