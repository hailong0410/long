//stack implementation using linked list
#include<iostream>
#include<malloc.h>
using namespace std;
struct Node{
  int data;
  struct Node *next;
  
};

struct Node *head=NULL,*tail=NULL;

void push()
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

void pop()
{
  struct Node *temp;
  if(head==NULL)
  {
    head=tail=NULL;
  }
  else
  {
    temp=head;
    head=head->next;
    free(temp);
  }
}

void display()
{
  for (Node* node = head; node != NULL; node = node->next) {
		cout << node->data << ' ';
	}
	cout << '\n';
}
int main()
{ 
  
  push();
  push();
  push();
  push();
  push();
  display();
return 0;
}
