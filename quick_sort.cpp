#include <iostream>
using namespace std;
void printArr(int arr[], int len);
void swap(int *num1, int *num2);
int partition(int *arr, int start, int len);

// Recursive Quick sort
void quickSortR(int *arr, int len, int start = 0)
{
    if (start > len - 1)
        return; //end condition
    int i = partition(arr, start, len);
    quickSortR(arr, i, start); // recursion of left sub array
    quickSortR(arr, len, ++i); // recursion of right sub array
}

//Iterative Quick sort
void quickSortI(int *arr, int len, int start = 0)
{
    cout << "Starting Iterative Quicksort..." << endl;
    if (len <= 1)
        return;
    int list[len]; //to store the start and end indexes
    int top = -1;
    list[++top] = start;
    list[++top] = len - 1;
    while (top > 0)
    {
        int high = list[top--];
        int low = list[top--];
        int i = partition(arr, low, high + 1);
        if (i - 1 > low)
        {
            list[++top] = low;
            list[++top] = i - 1;
        }
        if (i + 1 < high)
        {
            list[++top] = i + 1;
            list[++top] = high;
        }
    }
}
int main()
{
    int len;
    cout << "Enter length of the array: ";
    cin >> len;
    int arr[len];
    cout << "Enter values... " << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "Element(" << i + 1 << "): ";
        cin >> arr[i];
    }
    cout << "Before Sorting: " << endl;
    printArr(arr, len);
    cout << "Starting recursive quicksort..." << endl;
    quickSortR(arr, len);
    // quickSortI(arr, len);
    cout << "After Sorting: " << endl;
    printArr(arr, len);

    return 0;
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int *arr, int start, int len)
{
    int pivotIndex = len - 1;
    int pivot = arr[pivotIndex];
    int i = start;
    int j = pivotIndex;
    while (i < j)
    {
        if (arr[i] >= pivot && arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
        }
        else if (arr[i] < pivot)
            i++;
        else
            j--;
    }

    swap(&arr[i], &arr[pivotIndex]);
    return i;
}