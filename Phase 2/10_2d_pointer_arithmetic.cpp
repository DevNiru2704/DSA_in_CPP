#include <iostream>
using namespace std;

// Drill 10: Pointer Arithmetic on 2D Arrays
void demonstrate_2d_pointer_arithmetic()
{
    cout << "Drill 10: Pointer Arithmetic on 2D Arrays" << endl;

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPointer arithmetic breakdown:" << endl;

    // matrix is of type int(*)[4] - pointer to array of 4 ints
    cout << "matrix = " << matrix << " (pointer to first row)" << endl;
    cout << "matrix + 1 = " << (matrix + 1) << " (pointer to second row)" << endl;
    cout << "matrix + 2 = " << (matrix + 2) << " (pointer to third row)" << endl;

    // Dereferencing
    cout << "\nDereferencing:" << endl;
    cout << "*matrix = " << *matrix << " (first row as int*)" << endl;
    cout << "*(matrix + 1) = " << *(matrix + 1) << " (second row as int*)" << endl;

    // Accessing elements
    cout << "\nAccessing elements:" << endl;
    cout << "matrix[1][2] = " << matrix[1][2] << endl;
    cout << "*(*(matrix + 1) + 2) = " << *(*(matrix + 1) + 2) << endl;

    // Manual conversion from a[i][j] to pointer arithmetic
    cout << "\nManual conversion a[i][j] -> *(*(a + i) + j):" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "*(*(matrix + " << i << ") + " << j << ") = "
                 << *(*(matrix + i) + j) << endl;
        }
    }
}

void practice_conversion()
{
    cout << "\nPractice: Convert these expressions:" << endl;
    cout << "matrix[0][0] -> *(*(matrix + 0) + 0)" << endl;
    cout << "matrix[2][3] -> *(*(matrix + 2) + 3)" << endl;
    cout << "matrix[i][j] -> *(*(matrix + i) + j)" << endl;
}

int main()
{
    demonstrate_2d_pointer_arithmetic();
    practice_conversion();
    return 0;
}