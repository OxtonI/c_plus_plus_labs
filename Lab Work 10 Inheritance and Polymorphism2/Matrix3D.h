#ifndef ABSTRACT_MATRIX_MATRIX3D_H
#define ABSTRACT_MATRIX_MATRIX3D_H
#include "MatrixBase.h"

struct Matrix3D : public MatrixBase
{
    Matrix3D() : MatrixBase(3) {}
};

#endif