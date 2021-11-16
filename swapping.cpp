#include <iostream>
using namespace std;

// Call by reference
void swap(int *num1, int *num2)
{
    cout << "Swaping using Call by reference Method..." << endl;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Call by Value
void swap(int num1, int num2)
{
    cout << "Swaping using Call by value method..." << endl;
    cout << "Before Swaping: " << endl;
    cout << "x is " << num1 << endl
         << "y is " << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "After Swaping: " << endl;
    cout << "x is " << num1 << endl
         << "y is " << num2 << endl;
}

int main()
{
    int x = 10, y = 20;
    cout << "Enter 'x' value: ";
    cin >> x;
    cout << "Enter 'y' value: ";
    cin >> y;
    swap(x, y);
    // swap(&x, &y);
    // cout << "After Swaping: " << endl
    //      << "x is " << x << endl
    //      << "y is " << y;

    return 0;
}