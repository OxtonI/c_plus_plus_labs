#include <cassert>
#include <random>
#include <ctime>
#include "Matrix3x3.h"
#define MATRIX3X3_SIZE 3

Matrix3x3::Matrix3x3() 
{
    for (int i = 0; i < MATRIX3X3_SIZE; i++)
        for (int j = 0; j < MATRIX3X3_SIZE; j++)
            state[i][j] = 0;
}

int Matrix3x3::element(const int i, const int j) const 
{
    assert(i >= 0 && i < MATRIX3X3_SIZE && j >= 0 && j < MATRIX3X3_SIZE);
    return state[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value) 
{
    assert(i >= 0 && i < MATRIX3X3_SIZE && j >= 0 && j < MATRIX3X3_SIZE);
    state[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal) 
{
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for (int i = 0; i < MATRIX3X3_SIZE; i++)
        for (int j = 0; j < MATRIX3X3_SIZE; j++)
            state[i][j] = distribution(generator);
}

int Matrix3x3::sumPrincipalDiag() const 
{
    int sum = 0;
    for (int i = 0; i < MATRIX3X3_SIZE; i++)
        sum += state[i][i];
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const 
{
    int sum = 0;
    for (int i = 2; i >= 0; i--)
        sum += state[i][2 - i];
    return sum;
}

int Matrix3x3::productPrincipalDiag() const 
{
    int product = 1;
    for (int i = 0; i < MATRIX3X3_SIZE; i++)
        product *= state[i][i];
    return product;
}

int Matrix3x3::productSecondaryDiag() const 
{
    int product = 1;
    for (int i = 2; i >= 0; i--)
        product *= state[i][2 - i];
    return product;
}

int Matrix3x3::sumRow(const int iRow) const
{
    assert(iRow >= 0 && iRow < MATRIX3X3_SIZE);
    int sum = 0;
    for (int i = 0; i < MATRIX3X3_SIZE; i++)
        sum += state[iRow][i];
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const
{
    assert(iCol >= 0 && iCol < MATRIX3X3_SIZE);
    int min = state[0][iCol];
    for (int i = 1; i < MATRIX3X3_SIZE; i++)
        if (min > state[i][iCol])
            min = state[i][iCol];
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const 
{
    assert(iCol >= 0 && iCol < MATRIX3X3_SIZE);
    int max = state[0][iCol];
    for (int i = 1; i < MATRIX3X3_SIZE; i++)
        if (max < state[i][iCol])
            max = state[i][iCol];
    return max;
}
