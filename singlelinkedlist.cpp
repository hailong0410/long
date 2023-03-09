#include <bits/stdc++.h>

using namespace std;

const int modulo = 1e9 + 7;

typedef int typeData;

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
	void addLast(typeData newData);
	void addPosition(typeData key, typeData newData);
	void remove(typeData deleteData);
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

void LinkedList::addLast(typeData newData) {
	++ size;

	if (head == NULL) { // linked list is empty
		head = new Node(newData, NULL);
		return;
	}
	
	Node* node = head;
	for (; node->next != NULL; node = node->next) {}
	node->next = new Node(newData, NULL);
}

// key : preposition which newData is added
void LinkedList::addPosition(typeData key, typeData newData) {
	++ size;

	if (head == NULL) { // linked list is empty
		head = new Node(newData, NULL);
		return;
	}

	Node* node = head;
	for (; node->data != key; node = node->next) {}

	Node* newNode = new Node(newData, node->next); // connect  v -> d
	node->next = newNode; // connect u -> v

}

void LinkedList::remove(typeData deleteData) {
	if (head == NULL) { // linked list is empty
		return;
	}

	Node* node = head;
	for (; node->next->data != deleteData; node = node->next) {}

	Node* tmpNode = node->next; // fake father
	node->next = tmpNode->next; // connect son -> fake father -> grandfather
}

void LinkedList::print() {
	for (Node* node = head; node != NULL; node = node->next) {
		cout << node->data << ' ';
	}
	cout << '\n';
}

void solution() {
	LinkedList* lst = new LinkedList();
	lst->addFirst(3);
	lst->addFirst(5);
	lst->addFirst(4);
	lst->addLast(6);
	lst->addFirst(5);
	lst->addPosition(5, 7);

	lst->print();

	lst->remove(4);

	lst->print();
}

int main() {
	solution();
}