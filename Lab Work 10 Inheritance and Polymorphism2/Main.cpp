#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

void fillMatrix(MatrixBase &matrix)
{
    for (auto i = 0; i < matrix.size(); i++)
        for (auto j = 0; j < matrix.size(); j++)
            matrix.element(i, j) = i * matrix.size() + j + 1;
}

int main() 
{
    Matrix2D matrix2a, matrix2b;
    Matrix3D matrix3a, matrix3b;

    fillMatrix(matrix2a);
    fillMatrix(matrix2b);
    fillMatrix(matrix3a);
    fillMatrix(matrix3b);

    std::cout << "matrix2a \n\n"
              << matrix2a << std::endl;
    std::cout << "matrix2b \n\n"
              << matrix2b << std::endl;
    std::cout << "matrix3a \n\n"
              << matrix3a << std::endl;
    std::cout << "matrix3b \n\n"
              << matrix3b << std::endl;

    matrix3a += matrix3b;
    matrix2a *= 8;

    std::cout << "matrix3a + matrix3b \n\n"
              << matrix3a << std::endl;
    std::cout << "matrix2a * 8 \n\n"
              << matrix2a << std::endl;

    return 0;
}