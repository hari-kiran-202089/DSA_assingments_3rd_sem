#include <iostream>
using namespace std;

class Binary_search
{
public:
    //Constructor function to intialize size and copy the array
    Binary_search(int array[], int len)
    {
        size = len;
        arr = copy_arr(array, len);
    }
    // Destructor function used to delete the copied array from heap
    ~Binary_search()
    {
        delete[] arr;
    }
    // Interative Binary search function
    int findI(int value)
    {
        cout << "Starting Interative Binary Search..." << endl;
        int start = 0, end = size - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (value == arr[mid])
            {
                return mid;
            }
            else if (value < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    // Recursive Binary search function
    int findR(int value, int start, int end)
    {
        int mid = (start + end) / 2;
        if (start > end)
        {
            return -1;
        }
        else if (value == arr[mid])
        {
            return mid;
        }
        else if (value < arr[mid])
        {
            return findR(value, start, mid - 1);
        }
        else
        {
            return findR(value, mid + 1, end);
        }
    }
    // function overloading for single parameter
    int findR(int value)
    {
        cout << "Starting Recursive Binary search..." << endl;
        return findR(value, 0, size);
    }

private:
    int *arr = NULL;
    int size; // length of the array

    // function that takes an array and return a pointer to newly copied array
    int *copy_arr(int arr[], int len)
    {
        int *ptr = NULL;
        ptr = new int[len];
        for (int i = 0; i < len; i++)
        {
            ptr[i] = arr[i];
        }
        return ptr;
    }
};

int main()
{
    int len, i, value;
    cout << "Enter Length of the array: ";
    cin >> len;
    int arr[len];
    cout << "Enter the sorted values..." << endl;
    for (i = 0; i < len; i++)
    {
        cout << "Value" << '[' << i << "] :";
        cin >> arr[i];
    }

    cout << "Enter a value to search: ";
    cin >> value;
    Binary_search list1(arr, len);
    // int index = list1.findI(value);
    int index = list1.findR(value);
    if (index == -1)
    {
        cout << value << " not found" << endl;
    }
    else
    {
        cout << value << " found at index " << index << endl;
    }

    return 0;
}