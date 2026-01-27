#include <iostream>
using namespace std;

// Drill 8: 2D Array Decay and int** vs Real 2D Arrays
void print_matrix_wrong(int **matrix, int rows, int cols)
{
    cout << "Wrong function (int**):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void print_matrix_correct(int matrix[][4], int rows)
{
    cout << "Correct function (fixed columns):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void demonstrate_decay()
{
    cout << "Drill 8: 2D Array Decay" << endl;

    int real_2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Real 2D array memory layout:" << endl;
    cout << "Type of real_2d: int[3][4]" << endl;
    cout << "When passed to function, decays to: int(*)[4]" << endl;

    // Correct usage
    print_matrix_correct(real_2d, 3);

    // Wrong usage - this is the classic bug!
    cout << "\nTrying wrong function (int**):" << endl;
    // print_matrix_wrong(real_2d, 3, 4);  // Type mismatch!

    cout << "The above line would cause a compilation error or undefined behavior!" << endl;
}

void demonstrate_int_star_star()
{
    cout << "\nDemonstrating int** (different from 2D array):" << endl;

    int rows = 3, cols = 4;
    int **ptr_array = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr_array[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            ptr_array[i][j] = (i + 1) * 10 + j;
        }
    }

    // This works with int**
    print_matrix_wrong(ptr_array, rows, cols);

    // Cleanup
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr_array[i];
    }
    delete[] ptr_array;
}

int main()
{
    demonstrate_decay();
    demonstrate_int_star_star();
    return 0;
}