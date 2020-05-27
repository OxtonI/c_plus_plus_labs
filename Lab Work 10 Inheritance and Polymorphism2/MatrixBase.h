#ifndef ABSTRACT_MATRIX_MATRIXBASE_H
#define ABSTRACT_MATRIX_MATRIXBASE_H
#include <iostream>
#include <stdexcept>

class MatrixBase
{
    public:
    unsigned int size() const { return m_size; }
    virtual int element(unsigned int i, unsigned int j) const;
    virtual int &element(unsigned int i, unsigned int j);
    void operator*=(int iMult);
    void operator+=(const MatrixBase &iAdd);
    friend std::ostream &operator<<(std::ostream &out, const MatrixBase &iMatrix);

    protected:
    MatrixBase(unsigned int iSize);
    ~MatrixBase() { delete[] m_array; }

    private:
    int *m_array;
    const unsigned int m_size = 0;
    constexpr int index(unsigned int i, unsigned int j) const { return i * m_size + j; }
};

#endif