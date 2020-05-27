#include "MatrixBase.h"
#include <string>
#include <cassert>

MatrixBase::MatrixBase(unsigned int iSize) : m_size(iSize), m_array(new int[iSize * iSize])
{
    for (int i = 0; i < m_size * m_size; i++)
        m_array[i] = 0;
}

int MatrixBase::element(unsigned int i, unsigned int j) const
{
    assert(i < m_size && j < m_size);
    return m_array[index(i, j)];
}

int &MatrixBase::element(unsigned int i, unsigned int j)
{
    assert(i < m_size && j < m_size);
    return m_array[index(i, j)];
}

void MatrixBase::operator*=(int iMult)
{
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            element(i, j) *= iMult;
        }
    }
}

void MatrixBase::operator+=(const MatrixBase &iAdd)
{
    assert(iAdd.size() == m_size);
    for (int i = 0; i < iAdd.m_size; ++i)
    {
        for (int j = 0; j < iAdd.m_size; ++j)
        {
            element(i, j) += iAdd.element(i, j);
        }
    }
}

std::ostream &operator<<(std::ostream &out, const MatrixBase &iMatrix)
{
    for (int i = 0; i < iMatrix.size(); i++)
    {
        for (int j = 0; j < iMatrix.size(); j++)
            out << iMatrix.element(i, j) << ' ';
        out << "\n";
    }
    return out;
}