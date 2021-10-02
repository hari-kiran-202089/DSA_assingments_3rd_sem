#include <iostream>
using namespace std;
void printMat(int *mat, int rows, int columns);
int *readMat(int rows, int columns);
void addMat(int *mat1, int *mat2, int rows, int columns);
void subMat(int *mat1, int *mat2, int rows, int columns);
void mulMat(int *mat1, int r1, int c1, int *mat2, int r2, int c2);
void transMat(int *mat, int rows, int columns);
int main()
{
    int r1, c1, r2, c2, op;
    do
    {
        cout << endl
             << "-------------------------------------------------------------" << endl;
        cout << "Choose shape of first matrix..." << endl;
        cout << "Enter rows: ";
        cin >> r1;
        cout << "Enter columns: ";
        cin >> c1;
        int *mat1 = readMat(r1, c1);
        printMat(mat1, r1, c1);
        cout << "Choose one of the following operations: " << endl;
        cout << "1.Addition" << endl
             << "2.Subtraction" << endl
             << "3.Multiplication" << endl
             << "4.Transpose" << endl
             << "5.Exit" << endl;
        cout << "Enter the operation: ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout << "Second Matrix shape is " << r1 << ',' << c1 << endl;
            int *mat2 = readMat(r1, c1);
            printMat(mat2, r1, c1);
            cout << "Performing addition..." << endl;
            addMat(mat1, mat2, r1, c1);
            delete[] mat2;
        }
        break;
        case 2:
        {
            cout << "Second Matrix shape is " << r1 << ',' << c1 << endl;
            int *mat2 = readMat(r1, c1);
            printMat(mat2, r1, c1);
            cout << "Performing subtraction..." << endl;
            subMat(mat1, mat2, r1, c1);
            delete[] mat2;
        }
        break;
        case 3:
        {
            cout << "Choose shape of second matrix..." << endl;
            cout << "Rows are " << c1 << endl;
            r2 = c1;
            cout << "Enter columns: ";
            cin >> c2;
            int *mat2 = readMat(r2, c2);
            printMat(mat2, r2, c2);
            cout << "Performing multiplication..." << endl;
            mulMat(mat1, r1, c1, mat2, r2, c2);
            delete[] mat2;
        }
        break;
        case 4:
        {
            cout << "Performing transpose..." << endl;
            transMat(mat1, r1, c1);
        }
        break;
        case 5:
            cout << "Terminating the program..." << endl;
            break;
        default:
            break;
        }
        delete[] mat1;
    } while (op >= 1 && op <= 4);
    cout << "\nThank you & See you soon =)" << endl;
    return 0;
}
void transMat(int *mat, int rows, int columns)
{
    int *transpose = new int[rows * columns];
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            transpose[i * rows + j] = mat[j * columns + i];
        }
    }
    printMat(transpose, columns, rows);
    delete[] transpose;
}
void mulMat(int *mat1, int r1, int c1, int *mat2, int r2, int c2)
{
    int newR = r1, newC = c2;
    int *result = new int[newR * newC];
    if (c1 != r2)
    {
        return;
    }
    for (int i = 0; i < newR; i++)
    {
        for (int j = 0; j < newC; j++)
        {
            result[i * newC + j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i * newC + j] += (mat1[i * c1 + k] * mat2[k * c2 + j]);
            }
        }
    }
    printMat(result, newR, newC);
    delete[] result;
    return;
}

void addMat(int *mat1, int *mat2, int rows, int columns)
{
    int *sum = new int[rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum[i * columns + j] = mat1[i * columns + j] + mat2[i * columns + j];
        }
    }
    printMat(sum, rows, columns);
    delete[] sum;
}
void subMat(int *mat1, int *mat2, int rows, int columns)
{
    int *sum = new int[rows * columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum[i * columns + j] = mat1[i * columns + j] - mat2[i * columns + j];
        }
    }
    cout << "Subtracting second matrix from first matrix: " << endl;
    printMat(sum, rows, columns);
    delete[] sum;
}

void printMat(int *mat, int rows, int columns)
{
    cout << "Matrix is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "  ";
        for (int j = 0; j < columns; j++)
        {
            cout << mat[i * columns + j] << "  ";
        }
        cout << endl;
    }
}
int *readMat(int rows, int columns)
{
    cout << "Enter values: " << endl;
    int *mat = new int[rows * columns];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Value[" << i << "," << j << "]: ";
            cin >> mat[i * columns + j];
        }
    }
    return mat;
}