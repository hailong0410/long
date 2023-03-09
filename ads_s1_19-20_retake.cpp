#include<bits/stdc++.h>
using namespace std;
bool checksnt(int n)
{
    if(n<2)
    {
        return false;
    }
    if (n % 2 == 0)  
		{
			return false;
		}
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int primeFactors(int n)
{
while (n % 2 == 0)
{
cout << 2 << " ";
n = n/2;
}
for (int i = 3; i <= sqrt(n); i = i + 2)
{
while (n % i == 0)
{
cout << i << " ";
n = n/i;
}
}
if (n > 2)
cout << n << " ";
return 0;
}
struct Node
{
    int data;
    Node *next;
    Node() {}
	Node(int data):
		data(data) {}
	Node(int data, Node* next):
		data(data), next(next) {}
};
struct LinkedList {
	Node* head;
    Node* tail;
	int size = 0;

	void push(int newData);
	void pop(int newData);
	void print();
};
void LinkedList::push( int newData)
{
	struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    cout<<"ENter data:";
    cin>>newNode->data;
    newNode->next=head;
    if(head==NULL)
    {
      head=tail=newNode;
    }
    else
    {
    newNode->next=head;
    head=newNode;
    }
}
void LinkedList::pop(int newData)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    cin>>newNode->data;
    newNode->next=head;
  
    if(head==NULL)
    {
      head=tail=newNode;
    }
    else
    {
    newNode->next=head;
    head=newNode;
    }
}
void LinkedList::print()
{
    int a=1;
    Node* node = head;
    for (Node* node = head; node != NULL; node = node->next)
    {
        if(checksnt(primeFactors(node->data))==true)
        {
            push(node->data);
            a=a*node->data;
             pop(node->data);
        }
    }
     for (Node* node = head; node != NULL; node = node->next)
     {
        cout<< node->data;
     }
}
void solution()
{
    LinkedList* lst = new LinkedList();
    lst->print();
}
int main()
{   
    solution();
}