#include <bits/stdc++.h>
using namespace std;

class products
{
    string name;
    int quantity;

};

class QNode
{
public:
    int data;
    QNode *next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    QNode *front, *rear;
    Queue() { front = rear = NULL; }

    void enQueue(int x)
    {
        QNode *temp = new QNode(x);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {
        if (front == NULL)
            return;
        QNode *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete (temp);
    }
};

int main()
{
    Queue q;
    int num_of_customers;
    cin >> num_of_customers;
    for(int i = 0; i < num_of_customers; i++)
    {
        int k;
        cin >> k;
        q.enQueue(k);
    }
    
}