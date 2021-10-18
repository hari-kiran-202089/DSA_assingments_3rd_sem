#include <iostream>
using namespace std;
// Function to find the length of the string
int len(string str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
// Function to reverse a string
void reverse(string &str)
{
    int length = len(str);
    for (int i = 0; i < (length / 2); i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
// Function to copy second parameter into first parameter
void copyStr(string &strName, string str)
{
    string tempStr;
    for (int i = 0; str[i] != '\0'; i++)
    {
        tempStr += str[i];
    }
    strName = tempStr;
    cout << endl;
}
// Function to combine two strings
void concatenate(string &str1, string str2)
{
    int len1 = len(str1);
    int len2 = len(str2);
    string tempstr;
    copyStr(tempstr, str1);        // copy first string into temp varible
    for (int i = 0; i < len2; i++) // concatenating second string to temp varible
    {
        tempstr += str2[i];
    }
    str1 = tempstr; // assign tempstr to string 1
}

int main()
{
    string str1, str2;
    int choice;
    while (choice != 4)
    {
        cout << endl;
        cout << "String Operations:" << endl
             << "1.Find Length" << endl
             << "2.Concatenate" << endl
             << "3.Reverse" << endl
             << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(1, '\n'); // To ignore the "enter" key value that is stored in the input buffer
        switch (choice)
        {
        case 1:
            cout << "Enter a String: ";
            getline(cin, str1);
            cout << "Length of the string is " << len(str1) << endl;
            break;
        case 2:
            cout << "Enter first string: ";
            getline(cin, str1);
            cout << "Enter second string: ";
            getline(cin, str2);
            concatenate(str1, str2);
            cout << "Result: " << str1 << endl;
            break;
        case 3:
            cout << "Enter a string: ";
            getline(cin, str1);
            reverse(str1);
            cout << "Result: " << str1 << endl;
            break;
        case 4:
            break;
        default:
            cout << "Enter a valid choice..." << endl;
        }
    }

    return 0;
}
