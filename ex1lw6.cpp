#include<bits/stdc++.h>
using namespace std;

int a[100];
struct _queue
{
  int data[40];
  int front, back;
};
void init(_queue *q)
{
  q->front=0;
  q->back=0;
}
struct Treenode
{
  int val;
  Treenode *parent;
  Treenode *tleft;
  Treenode *tright;
}*root;
typedef struct Treenode *Tree;
Treenode *newNode(int data)
{
  Treenode *Tnode=new Treenode;
  Tnode->tleft=NULL;
  Tnode->tright=NULL;
  Tnode->val=data;
  return Tnode;
}

void NLR( Treenode *root)
{
  if (root->tleft != NULL)
    NLR(root->tleft);
  cout<< root->val<< " ";
  if (root ->tright != NULL)
    NLR(root->tright);
}

void createTree(Treenode *root, int l, int r)
{
  if (l > r)
    return;
  if (l == r)
  {
    root->val = a[l];
    return;
  }
  int mid = (l+r)/2;
  Treenode *x = newNode(123456);
  Treenode *y = newNode(123456);
  x->parent = root;
  y->parent = root;
  root->tleft = x;
  root->tright = y;
  createTree(x,l,mid);
  createTree(y,mid+1,r);
  root->val = min(x->val, y->val);
}

bool Search(int x, Treenode *root)
{
  if (x == root->val)
  {
    NLR(root);
    return true;
  }
  bool xx = false;
  if (root->tleft != NULL && root->tleft->val <= x)
    xx = Search(x,root->tleft);
  bool yy = false;
  if (root->tright != NULL && root->tright->val <= x)
    yy = Search(x,root->tright);
  if (xx || yy)
    return true;
  return false;
}

int insert(Tree &tree,int x)
{
  if(tree!=NULL)
  {
    if(x=tree->val)
      return 0;
    else
    {
      if(x<tree->val)

      {
        insert(tree->tleft,x);
      }
      else
      {
        insert(tree->tright,x);
      }
    }
  }
  else
  {
    tree= new Treenode;
    tree->val=x;
    tree->tleft=tree->tright=NULL;
  }
  return 1;
}
int delnode(Tree &tree, int x )
{
  if(tree= NULL) return 0;
  else if(tree->val>x) return delnode(tree->tleft,x);
  else if(tree->val<x) return delnode(tree->tright,x);
  else
  {
    Tree P=tree;
    if(tree->tleft==NULL) tree=tree->tright;
    else if(tree->tright==NULL) tree=tree->tleft;
    else
    {
      Tree S=tree, Q=S->tleft;
      while(Q->tright!=NULL)
      {
        S=Q;
        Q=Q->tright;
      }
      P->val=Q->val;
      S->tright=Q->tleft;
      delete Q;
    }
  }
  return 1;
}

int main()
{
  Treenode *root = newNode(123456);
  int n ;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  createTree(root,1,n);
  //int k;
  //cin>>k;
  bool found = Search(40,root);
  if (!found)
    cout << -1 <<" \n";

  NLR(root);
}