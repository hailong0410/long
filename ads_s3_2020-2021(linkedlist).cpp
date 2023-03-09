#include <bits/stdc++.h>

using namespace std;

const int modulo = 1e9 + 7;

typedef int typeData;

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

struct Node {
	typeData data;
	Node* next;
	Node* prev;

	Node() {}
	Node(int data):
		data(data) {}
	Node(int data, Node* next):
		data(data), next(next) {}
};

struct LinkedList {
	Node* head;
	int size = 0;

	void addFirst(typeData newData);
	void print();
};

void LinkedList::addFirst(typeData newData) {
	++ size;

	if (head == NULL) { // linked list is empty
		head = new Node(newData, NULL);
		return;
	}

	Node* newHead = new Node(newData, head);
	head = newHead;
}
void LinkedList::print() {
    for(Node* node1=head; node1!=NULL; node1=node1->next)
    {
        for(Node* node2=node1->next; node2!=NULL; node2=node2->next)
        {
            if(gcd(node1->data,node2->data)==1)
            {
                cout<< node1->data << " " << node2->data << " ";
				cout << '\n';
            }
        }
    }
}

void solution() {
	LinkedList* lst = new LinkedList();
	lst->addFirst(4);
	lst->addFirst(7);
	lst->addFirst(12);
	lst->addFirst(9);
	lst->addFirst(20);
	lst->print();
}

int main() {
	solution();
}