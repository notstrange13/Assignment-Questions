#include <iostream>
using namespace std;

int main()
{
    int n, i, pos;
    cout << "Enter the number of Elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter position: ";
    cin >> pos;
    for (i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Array after deletion: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}