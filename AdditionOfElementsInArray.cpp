// WAP to insert an element in an array

#include <iostream>
using namespace std;

void insertAtBeginning(int arr[], int *n, int element)
{
    for (int i = *n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    (*n)++;
}

void insertAtMiddle(int arr[], int *n, int element)
{
    int pos = *n / 2;
    for (int i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*n)++;
}

void insertAtEnd(int arr[], int *n, int element)
{
    arr[*n] = element;
    (*n)++;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100], n, element;
    cout << "Enter the number of elements = ";
    cin >> n;

    cout << "Enter " << n << " elements = \n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    printArray(arr, n);

    cin >> element;

    insertAtBeginning(arr, &n, element);
    printArray(arr, n);

    cin >> element;

    insertAtMiddle(arr, &n, element);
    printArray(arr, n);

    cin >> element;

    insertAtEnd(arr, &n, element);
    printArray(arr, n);

    return 0;
}