#include <iostream>

using namespace std;

#define MAXSIZE 100

int q[MAXSIZE];
int front = -1;
int rear = -1;

bool isoverflow()
{
    return rear == MAXSIZE - 1;
}

bool isunderflow()
{
    return front == -1;
}

void enqueue(int x)
{
    if (isoverflow())
    {
        cout << "Queue is full";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        q[rear] = x;
    }
    else
    {
        rear = rear + 1;
        q[rear] = x;
    }
}

void dequeue()
{
    if (isunderflow())
    {
        cout << "Queue is empty";
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = front + 1;
    }
}

void peek()
{
    if (isunderflow())
    {
        cout << "Queue is empty";
        return;
    }
    cout << q[front];
}

void traverse()
{
    if (isunderflow())
    {
        cout << "Queue is empty";
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << q[i] << " ";
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    traverse();
    cout << endl;

    peek();
    cout << endl;

    dequeue();
    traverse();
    cout << endl;

    return 0;
}