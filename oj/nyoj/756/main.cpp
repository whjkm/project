#include <cstdio>
#include <cstring>
#include <cstdlib>
struct node
{
    char value;
    node *lchild,*rchild;
};
node *newnode(char c)
{
  node *p=(node *)malloc(sizeof(node));
  p->value=c;
  p->lchild=p->rchild=NULL;
  return p;
}
node *rebulid(char *post,char *in,int n)
{
    if(n==0) return NULL;
    char ch=post[n-1];
    node *p=newnode(ch);
    int i;
    for(i=0;i<n&&in[i]!=ch;i++);
    int l_len=i;
    int r_len=n-i-1;
    if(l_len>0) p->lchild=rebulid(post,in,l_len);
    if(r_len>0) p->rchild=rebulid(post + l_len, in+l_len+1, r_len);
    return p;
}
void preorder(node *p)
{
    if(p==NULL) return;
    printf("%c",p->value);
    preorder(p->lchild);
    preorder(p->rchild);
}
int main()
{
    char postorder[30],inorder[30];
    while(scanf("%s%s",postorder,inorder)!=EOF)
    {
        node *root=rebulid(postorder,inorder,strlen(postorder));
        preorder(root);
        printf("\n");
    }
    return 0;
}
