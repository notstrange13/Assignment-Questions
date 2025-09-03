#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {1, 5, 6, 3, 58, 100};

    int size = sizeof(arr) / sizeof(arr[0]);
    int search;
    cin >> search;
    int index = linearSearch(arr, size, search);
    cout << index;

    return 0;
}