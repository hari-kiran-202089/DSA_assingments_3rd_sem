#include <iostream>
using namespace std;
// Takes matrix values from the user
int *readMat(int rows, int columns);

//class created for matrices
class Matrix
{
public:
    // constructor takes pointer to the matrix and its shape
    Matrix(int *mat, int row, int column)
    {
        rows = row;
        columns = column;
        matrix = mat;
    }

    // prints the matrix on to the terminal
    void printMatrix()
    {
        cout << "Matrix is: " << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "    ";
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i * columns + j] << " ";
            }
            cout << endl;
        }
    }
    //getRows,getColumns,getMatrix helps to access the rows,columns
    //and the pointer to the matrix values as they are private
    int getRows()
    {
        return rows;
    }
    int getColumns()
    {
        return columns;
    }
    int *getMatrix()
    {
        return matrix;
    }

    //Operator overloading for addition, this will return a pointer to the newly added matrix
    int *operator+(Matrix &mat1)
    {
        if (this->rows == mat1.getRows() && this->columns == mat1.getColumns())
        {
            int *sum = new int[rows * columns];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    sum[i * columns + j] = this->matrix[i * columns + j] + mat1.getMatrix()[i * columns + j];
                }
            }
            return sum;
        }
        else
        {
            // if shape of the two matrices doesn't match it will return pointer of first matrix
            cout << "Addition is not possible on matrices with different shapes." << endl;
            return this->matrix;
        }
    }
    //Operator overloading for subtraction, this will return a pointer to the newly subtracted matrix
    int *operator-(Matrix &mat1)
    {
        if (this->rows == mat1.getRows() && this->columns == mat1.getColumns())
        {
            int *sub = new int[rows * columns];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    sub[i * columns + j] = this->matrix[i * columns + j] - mat1.getMatrix()[i * columns + j];
                }
            }
            return sub;
        }
        else
        {
            cout << "Subtraction is not possible on matrices with different shapes." << endl;
            return this->matrix;
        }
    }
    //Operator overloading for multiplication, this will return a pointer to the newly multiplied matrix
    int *operator*(Matrix &mat1)
    {
        if (this->columns == mat1.getRows())
        {
            int *product = new int[this->rows * mat1.getColumns()];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < mat1.getColumns(); j++)
                {
                    product[i * mat1.getColumns() + j] = 0;
                    for (int k = 0; k < columns; k++)
                    {
                        product[i * mat1.getColumns() + j] += (this->matrix[i * columns + k] * mat1.getMatrix()[k * mat1.getColumns() + j]);
                    }
                }
            }
            return product;
        }
        else
        {
            cout << "Matrix multiplication is not possible for give matrices" << endl;
            return this->matrix;
        }
    }
    // it will transpose a matrix and return pointer to newly transposed matrix
    int *transpose()
    {
        int *trans = new int[rows * columns];
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                trans[i * rows + j] = matrix[j * columns + i];
            }
        }
        return trans;
    }
    // destructor will delete the matrix memory from the heap
    ~Matrix()
    {
        delete[] matrix;
    }

private:
    int rows, columns;
    int *matrix;
};

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
        Matrix mat1(readMat(r1, c1), r1, c1);
        mat1.printMatrix();
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
            Matrix mat2(readMat(r1, c1), r1, c1);
            mat2.printMatrix();
            cout << "Performing addition..." << endl;
            int *sum = mat1 + mat2;
            Matrix result(sum, r1, c1);
            result.printMatrix();
        }
        break;
        case 2:
        {
            cout << "Second Matrix shape is " << r1 << ',' << c1 << endl;
            Matrix mat2(readMat(r1, c1), r1, c1);
            mat2.printMatrix();
            cout << "Performing subtraction..." << endl;
            int *sub = mat1 - mat2;
            Matrix result(sub, r1, c1);
            result.printMatrix();
        }
        break;
        case 3:
        {
            cout << "Choose shape of second matrix..." << endl;
            cout << "Rows are " << c1 << endl;
            r2 = c1;
            cout << "Enter columns: ";
            cin >> c2;
            Matrix mat2(readMat(r2, c2), r2, c2);
            mat2.printMatrix();
            cout << "Performing multiplication..." << endl;
            int *product = mat1 * mat2;
            Matrix result(product, r1, c2);
            result.printMatrix();
        }
        break;
        case 4:
        {
            cout << "Performing transpose..." << endl;
            int *trans = mat1.transpose();
            Matrix result(trans, c1, r1);
            result.printMatrix();
        }
        break;
        default:
            break;
        }
    } while (op != 5);
    cout << "\nThank you & See you soon =)" << endl;
    return 0;
}

//Takes matrix values of given shape
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