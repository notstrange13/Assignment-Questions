#include <iostream>
using namespace std;

int main()
{
    int stack[100], top = -1, choice, val, i;
    do
    {
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value to push: ";
            cin >> val;
            top++;
            stack[top] = val;
        }
        else if (choice == 2)
        {
            if (top == -1)
            {
                cout << "Stack Underflow";
            }
            else
            {
                cout << "Popped Value: " << stack[top];
                top--;
            }
        }
        else if (choice == 3)
        {
            if (top == -1)
            {
                cout << "Stack is empty";
            }
            else
            {
                cout << "Stack Elements: ";
                for (i = top; i >= 0; i--)
                {
                    cout << stack[i] << " ";
                }
            }
        }
    } while (choice != 4);
    return 0;
}