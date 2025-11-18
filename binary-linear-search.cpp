#include <iostream>
using namespace std;

// ---- Linear Search ----
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i; // return index
    }
    return -1; // not found
}

// ---- Binary Search (Array must be sorted) ----
int binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid; // found
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nEnter element to search: ";
    cin >> key;

    cout << "\nChoose Search Method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (Array must be sorted)\n";
    cout << "Enter choice: ";
    cin >> choice;

    int result;

    if (choice == 1)
    {
        result = linearSearch(arr, n, key);
    }
    else if (choice == 2)
    {
        result = binarySearch(arr, n, key);
    }
    else
    {
        cout << "Invalid choice!\n";
        return 0;
    }

    if (result != -1)
        cout << "\nElement found at index: " << result << endl;
    else
        cout << "\nElement not found.\n";

    return 0;
}
