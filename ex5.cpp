#include<bits/stdc++.h>
using namespace std;
struct _node
{
    char data;
    struct _node * next;
};
typedef struct _node  Node;
struct _stack
{
    int size;
    Node *ptop;

};
typedef struct _stack Stack;
void init(Stack *redostack, Stack *undostack)
{
    redostack->ptop->data=-1;
    undostack->ptop->data=-1;
};
int isEmpty(Stack *st)
{
    return st->ptop->data<0;
}
int push(char newdata, Stack *st)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        return 0;
    }
    p->data=newdata;
    p->next=st->ptop->next;
    st->ptop=p;
    st->size++;
    return 1;
}
int pop(Stack *st)
{
    Node *p;
    if(isEmpty(st))
    {
        return 0;
    }
    p=st->ptop;
    st->ptop=st->ptop->next;
    st->size--;
    free(p);
    return 1;
}
void display(Stack *st)
{
    Node *cur;
    cur= st->ptop;
    while(cur != NULL)
    {
        cout << st->ptop;
    }
}
int main()
{

}