// WAP to implement an output restricted deque using array representation

#include <iostream>
using namespace std;

struct OutputRestrictedDeque
{
    int data[5], front = -1, rear = -1, size = 5;

    bool full()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }
    bool empty()
    {
        return front == -1;
    }

    void insertFront(int val)
    {
        if (full())
            return;
        if (front == -1)
            front = rear = 0;
        else
            front = (front - 1 + size) % size;
        data[front] = val;
    }

    void insertRear(int val)
    {
        if (full())
            return;
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % size;
        data[rear] = val;
    }

    void deleteFront()
    {
        if (empty())
            return;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }

    void show()
    {
        if (empty())
        {
            cout << "Empty\n";
            return;
        }
        for (int i = front;; i = (i + 1) % size)
        {
            cout << data[i] << " ";
            if (i == rear)
                break;
        }
        cout << "\n";
    }
};

int main()
{
    OutputRestrictedDeque dq;
    dq.insertRear(10);
    dq.insertFront(5);
    dq.insertRear(20);
    dq.show();
    dq.deleteFront();
    dq.show();
    return 0;
}