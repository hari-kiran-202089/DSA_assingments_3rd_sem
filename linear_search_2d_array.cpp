#include <iostream>
using namespace std;

int main()
{
    int i, j, value, rows, columns, check = 0; // declaring variables

    //Take input from the user about shape of array
    cout << "Choose the shape of the 2D array..." << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    int arr[rows][columns];

    //Take values from user
    cout << "Enter the values..." << endl;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            cout << "element" << '(' << i << ',' << j << "): ";
            cin >> arr[i][j];
        }
    }

    cout << "Enter the number to search: ";
    cin >> value;

    // Search for value linearly in the 2d array
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (value == arr[i][j])
            {
                cout << value << " found at"
                     << " (" << i << ',' << j << ")" << endl;
                check = 1;
            }
        }
    }
    // check if value is in the array or not
    if (check == 0)
    {
        cout << value << " not found" << endl;
    }

    return 0;
}
