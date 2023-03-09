    #include <bits/stdc++.h>

using namespace std;

class products
{
public:
    int id;
    string name;
    int quantity;
    products(string name, int quantity)
    {
        this->name = name;
        this->quantity = quantity;
    }
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

    bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }

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

void purchase_item(products *item, int buy_quantity)
{
    if (item->quantity < buy_quantity && item->quantity > 0)
    {
        cout << "Sorry, we don't have enough " << item->name << "to purchase";
        cout << endl;
        return;
    }
    if (item->quantity == 0)
    {
        cout << "Out of stock, please come back later";
        cout << endl;
        return;
    }
    cout << "Item " << item->name << " purchased successfully" << endl;
    item->quantity = item->quantity - buy_quantity;
}

int main()
{  
    Queue q;
    products item1("ballpoint pen", 5);
    products item2("eraser", 10);
    products item3("ruler", 19);

    int num_of_customers;
    cout << "Number of customer: ";
    cin >> num_of_customers;
    cout << "Enter number of products customer can buy: " << endl;

    for (int i = 0; i < num_of_customers; i++)
    {
        int k;
        cout << "Customer " << i + 1 << ", you can buy : ";
        cin >> k;
        q.enQueue(k);
        int item_num;
        cout << "How much items do  you want to buy :";
        cin >> item_num;
        cout << "Products id you want to purchase and number of items you want to buy(id number):\n";
        int id[3] = {0, 0, 0};
        int num[3] = {0, 0, 0};
        for (int i = 0; i < item_num; i++)
            cin >> id[i] >> num[i];
        for (int i = 0; i < item_num; i++)
        {
            if (id[i] == 1)
                purchase_item(&item1, num[i]);
            if (id[i] == 2)
                purchase_item(&item2, num[i]);
            if (id[i] == 3)
                purchase_item(&item3, num[i]);
        }
    }
    return 0;
}