#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node *head = nullptr;

// Create / Insert at End
void insertEnd(int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at Beginning
void insertBegin(int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert at Position (1-based index)
void insertAtPos(int value, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1)
    {
        insertBegin(value);
        return;
    }

    Node *newNode = new Node(value);
    Node *temp = head;

    for (int i = 1; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Position out of range!\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a Node by Value
void deleteValue(int value)
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Value not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Delete by Position
void deletePos(int pos)
{
    if (!head || pos <= 0)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (!temp || !temp->next)
    {
        cout << "Position out of range!\n";
        return;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// Search an Element
void search(int value)
{
    Node *temp = head;
    int pos = 1;

    while (temp)
    {
        if (temp->data == value)
        {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value not found!\n";
}

// Traverse List
void traverse()
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    cout << "Linked List: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, value, pos;

    while (true)
    {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Delete by Position\n";
        cout << "6. Search\n";
        cout << "7. Traverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertEnd(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertBegin(value);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            insertAtPos(value, pos);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteValue(value);
            break;

        case 5:
            cout << "Enter position to delete: ";
            cin >> pos;
            deletePos(pos);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;

        case 7:
            traverse();
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
