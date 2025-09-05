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
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Asending order: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nDescending order: ";
    for (i = n-1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}