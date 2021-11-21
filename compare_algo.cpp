#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;
float glb[3]; // global array
static int i = 0;
// Timer gives the time taken for each function to execute
class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::duration<float> duration;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;

public:
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    };
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = (end - start);
        i = i % 3;
        glb[i++] = duration.count(); // Takes note of the timing in a global array
    };
};
// Generates a Random array
void getRArr(int *arr, int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 1000;
    }
}
// Prints time in milliseconds from global array
template <class T>
void printArr(T *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] * 1000 << "  ";
    }
}
// For swaping  of variables
template <class T>
void swap(T *num1, T *num2)
{
    T temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int arr[], int len)
{
    Timer t;
    int check = 0; // to check if the array is already sorted or not
    for (int i = 1; i < len; i++)
    { // initalize i = 1 so that it won't go out of range in second loop
        for (int j = 0; j < len - i; j++)
        { // j<len-i to avoid comparing already sorted value and to prevent out of range
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                check = 1;
            }
        }
        if (check == 0)
            return; // check still 0 means everything sorted
        else
            check = 0;
    }
}
template <class T>
int partition(T *arr, int start, int len)
{
    int pivotIndex = len - 1;
    T pivot = arr[pivotIndex];
    int i = start;
    int j = pivotIndex;
    while (i < j)
    {
        if (arr[i] >= pivot && arr[j] < pivot)
        { // 4,8,6,6,9,23,12,11,7
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
int *mergeSort(int *arr, int len)
{
    if (len <= 1)
        return arr;
    int half = (len / 2); // half of array
    // declaring arrays
    int left[half];
    int right[len - half]; // len - half is the best way to get remaing half

    // filling values into both left and right arrays
    for (int i = 0; i < half; i++)
    {
        left[i] = arr[i];
    }
    for (int j = 0; j < (len - half); j++)
    {
        right[j] = arr[half + j];
    }

    int *leftSub = mergeSort(left, half);
    int *rightSub = mergeSort(right, len - half);

    int i = 0, j = 0, k = 0;
    while (i < half && j < (len - half))
    {
        if (leftSub[i] < rightSub[j])
        {
            arr[k] = leftSub[i];
            i++;
        }
        else
        {
            arr[k] = rightSub[j];
            j++;
        }
        k++;
    }
    while (i < half)
    {
        arr[k] = leftSub[i];
        k++;
        i++;
    }
    while (j < len - half)
    {
        arr[k] = rightSub[j];
        j++;
        k++;
    }

    return arr;
}
void quickSortI(int *arr, int len, int start = 0)
{
    Timer t;
    // cout<<"Starting Iterative Quicksort..."<<endl;
    if (len <= 1)
        return;
    int list[len]; // to store the start and end indexes
    int top = -1;
    list[++top] = start;
    list[++top] = len - 1;
    while (top > 0)
    {
        int high = list[top--];
        int low = list[top--];
        int i = partition(arr, low, high + 1); // using partition function
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

void quickSort(int *arr, int len)
{
    quickSortI(arr, len);
}
void mergeSrt(int *arr, int len)
{
    Timer t;
    mergeSort(arr, len);
}

// To take average of timings
void avg(float arr[], int len)
{
    float sum = 0;
    for (int j = 0; j < len; j++)
    {
        sum += arr[j];
    }
    printf("\nAverage is %.4f milliseconds", (sum / len) * 1000);
}

// Searching algorithms

void linearSearch(int *arr, int len, int value)
{
    Timer t;
    for (int j = 0; j < len; j++)
    {
        if (arr[j] == value)
        {
            cout << value << " found at index " << j << endl;
            return;
        }
    }
    cout << value << " not found\n";
}
void binarySearch(int *arr, int len, int value)
{
    Timer t;
    int start = 0, end = len - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (value == arr[mid])
        {
            cout << value << " found at index " << mid << endl;
            return;
        }
        else if (value > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << value << " is not found\n";
}
int main()
{
    int len = 1000;
    int arr[len];
    string sort[] = {"Merge Sort:", "Bubble Sort:", "Quick Sort:"};
    void (*sortfunPtr[])(int *arr, int len) = {mergeSrt, bubbleSort, quickSort};

    string search[] = {"Linear search:", "Binary Search:"};
    void (*searchfunPtr[])(int *arr, int len, int value) = {linearSearch, binarySearch};
    // Taking Time taken for each Sorting algorithms
    for (int j = 0; j < 3; j++)
    {
        cout << sort[j] << endl;
        for (int k = 0; k < 3; k++)
        {
            getRArr(arr, len);
            (*sortfunPtr[j])(arr, len);
        }
        cout << "Time taken for 3 arrays each: ";
        printArr(glb, 3);
        avg(glb, 3);
        cout << endl
             << endl;
    }
    // Taking time taken for each Searching algorithm
    getRArr(arr, len);

    for (int j = 0; j < 2; j++)
    {
        cout << search[j] << "\n";
        for (int k = 0; k < 3; k++)
        {
            int val = rand() % 1000;
            (*searchfunPtr[j])(arr, len, val);
        }
        cout << "Time taken for each: ";
        printArr(glb, 3);
        avg(glb, 3);
        mergeSort(arr, len);
        cout << "\n\n";
    }
    return 0;
}