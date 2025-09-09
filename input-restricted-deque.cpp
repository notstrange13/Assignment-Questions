// WAP to implement an input restricted deque using array representation

#include <iostream>
using namespace std;

struct InputRestrictedDeque
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

    void insertRear(int val)
    {
        if (full())
            return;
        if (front == -1)
            front = 0;
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

    void deleteRear()
    {
        if (empty())
            return;
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear + 1) % size;
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
    InputRestrictedDeque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.show();
    dq.deleteFront();
    dq.deleteRear();
    dq.show();
    return 0;
}

/*
Output
10  20  30

20


*/