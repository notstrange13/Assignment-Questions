#include <iostream>
using namespace std;

int main()
{
    int n, i, j, temp;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < n - i - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    cout << "Sorted Array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}