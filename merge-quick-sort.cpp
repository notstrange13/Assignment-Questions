#include <iostream>
using namespace std;

// ---------------- Merge Sort ----------------
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------------- Quick Sort ----------------
int partitionIndex(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionIndex(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// ---------------- Print Function ----------------
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------------- Main Program ----------------
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose Sorting Technique:\n";
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        mergeSort(arr, 0, n - 1);
        cout << "\nArray after Merge Sort:\n";
        break;

    case 2:
        quickSort(arr, 0, n - 1);
        cout << "\nArray after Quick Sort:\n";
        break;

    default:
        cout << "Invalid choice!\n";
        return 0;
    }

    printArray(arr, n);
    return 0;
}
