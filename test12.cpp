#include <bits/stdc++.h>

using namespace std;

#define null NULL // more easy to use 

class Node {

    int data;
    Node* next;

public:

    Node() {}
    Node(int data):
        data(data), next(null) {}
    Node(int data, Node* next):
        data(data), next(next) {}  

    int getData() { return (*this).data; }
    Node* getNext() { return (*this).next; }
};

class Stack {

    Node* topStack;
    int stackSize = 0;

    int rebuildMultiply = 1;

public:

    static const int limitSize = 3;
 
    void push(int data);
    void pop();
    int multiply();
    void print();
    bool checkso(int n);
};

vector<int> primeFactorization(int n);
bool checkuoc(int n)
{
    int a=0;
    for(int i=1;i<=n;i++)
    {
        if((n%i)==0)
        {
            a+=1;
        }
    }
    if(a==2)
    {
        return true;
    }
    else
        return false;
    }

bool checkso(int n)
{
    // a la dem so uoc
    //b la dem so nguyen to
    int a=0;
    int b=0;
    for(int i=1;i<=n;i++)
    {
        if((n%i)==0)
        {
            a+=1;
        if (checkuoc(i)==true)
        {
            b+=1;
        }
    }
    }
    if (a==8 && b==3)
    {
        return true;
    }
    else {return false;}
    
}
// main function
int main() {
    Stack* st = new Stack();

    int n ;
    cin>>n;
    for(int i=1;i<=n;i++)
    {  
        if(checkso(i)==true)
        st->push(i);
    }
    st->print();
}

void Stack::push(int data) {
    if (stackSize == limitSize) {
        return;
    }
    
    ++stackSize;

    if (topStack == null) {
        topStack = new Node(data);
    } else {
        Node* node = new Node(data, topStack);
        topStack = node;
    }
}

void Stack::pop() {
    if (topStack == null) {
        return;
    }

    rebuildMultiply *= topStack->getData();

    Node* node = topStack->getNext();
    delete topStack;
    topStack = node;
}

int Stack::multiply() {
    while (stackSize--) {
        pop();
    }
    return rebuildMultiply;
}

void Stack::print() {
    for(Node* node = topStack; node != null; node = node->getNext()) {
        cout << node->getData() << ' ';
    }
    cout << '\n';
}
