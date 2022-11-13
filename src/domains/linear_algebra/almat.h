#ifndef ALMAT_H
#define ALMAT_H

#include "alvec.h"

// Class: ALMat
// A class that represents a matrix of objects of type T.
// and can do linear algebra operations on them
template <class T>
class ALMat : public ALVec<ALVec<T> >
{
public:
    // Constructor: ALMat
    // Creates a new matrix.
    ALMat();

    // Constructor: ALMat
    // Creates a new matrix with the given initial capacity.
    ALMat(int initialCapacity);

    // Constructor: ALMat
    // Creates a new matrix with the given initial capacity and
    // initial value.
    ALMat(int initialCapacity, const ALVec<T>& initialValue);

    // Constructor: ALMat
    // Creates a new matrix that is a copy of the given matrix.
    ALMat(const ALMat<T>& m);

    // Constructor: ALMat
    // Creates a new matrix that is a copy of the given array
    // of the given size.
    ALMat(const ALVec<T>* array, int size);

    // Destructor: ~ALMat
    // Frees the memory associated with this matrix.
    ~ALMat();

    // Operator: []
    // Returns the vector at the given index.
    ALVec<T>& operator[](int index);

    // Operator: []
    // Returns the vector at the given index.
    const ALVec<T>& operator[](int index) const;

    // Operator: +
    // Adds the given matrix to this matrix and returns the result.
    ALMat<T> operator+(const ALMat<T>& m);

    // Operator: -
    // Subtracts the given matrix from this matrix and returns the result.
    ALMat<T> operator-(const ALMat<T>& m);

    // Operator: *
    // Multiplies the given matrix by this matrix and returns the result.
    ALMat<T> operator*(const ALMat<T>& m);

    // Operator: *
    // Multiplies each element of this matrix by the given value.
    ALMat<T> operator*(const T& value);

    // Operator: /
    // Divides each element of this matrix by the given value.
    ALMat<T> operator/(const T& value);

    // Operator: /
    // Divides each element of this matrix by the given matrix.
    ALMat<T> operator/(const ALMat<T>& m);

    //Operator /=
    //Divides each element of this matrix by the given value.
    ALMat<T>& operator/=(const T& value);

    // Operator: +=
    // Adds the given matrix to this matrix.
    ALMat<T> operator+=(const ALMat<T>& m);

    // Operator: -=
    // Subtracts the given matrix from this matrix.
    ALMat<T> operator-=(const ALMat<T>& m);

    // Method: zeros
    // creates a matrix of zeros of the given size
    void zeros(int rows, int cols);

    // Method: zeros
    // creates a matrix of zeros of the given size
    void zeros();

    // Method: ones
    // creates a matrix of ones of the given size
    void ones(int rows, int cols);

    // Method: ones
    // creates a matrix of ones of the given size
    void ones();

    // Method: random
    // creates a matrix of random numbers of the given size
    void random(int rows, int cols);

    // Method: random
    // creates a matrix of random numbers of the given size
    void random();

    // Method: identity
    // creates an identity matrix of the given size
    void identity(int size);

    // Method: identity
    // creates an identity matrix of the given size
    void identity();

    // Method: transpose
    // returns the transpose of the matrix
    void transpose();

    // Method: determinant
    // returns the determinant of the matrix
    T determinant();

    // Method: inverse
    // returns the inverse of the matrix
    ALMat<T> inverse();

    // Method: row
    // returns the row of the matrix
    ALVec<T> row(int row);

    // Method: col
    // returns the col of the matrix
    ALVec<T> col(int col);

    // Method: setRow
    // sets the row of the matrix
    void setRow(int row, ALVec<T> v);

    // Method: setCol
    // sets the col of the matrix
    void setCol(int col, ALVec<T> v);

    // Method: getRows
    // returns the number of rows in the matrix
    int getRows();

    // Method: getRows
    // returns the number of rows in the matrix
    int getRows() const;

    // Method: getCols
    // returns the number of cols in the matrix
    int getCols();

    // Method: getCols
    // returns the number of cols in the matrix
    int getCols() const;

    // Method: strassen
    // returns the product of the matrix using the strassen algorithm
    ALMat<T> strassen(const ALMat<T>& m);
    
    // Method: get
    // returns the vector at the given index
    ALVec<T> get(int index);

    // Method: get
    // returns the vector at the given index
    ALVec<T> get(int index) const;

    // Method: isPowerOf2
    // returns true if the given number is a power of 2
    bool isPowerOf2(int n);
};


// Constructor: ALMat
// Creates a new matrix.
template <class T>
ALMat<T>::ALMat() : ALVec<ALVec<T> >()
{
}

// Constructor: ALMat
// Creates a new matrix with the given initial capacity.
template <class T>
ALMat<T>::ALMat(int initialCapacity) : ALVec<ALVec<T> >(initialCapacity)
{
}

// Constructor: ALMat
// Creates a new matrix with the given initial capacity and
// initial value.
template <class T>
ALMat<T>::ALMat(int initialCapacity, const ALVec<T>& initialValue) : ALVec<ALVec<T> >(initialCapacity, initialValue)
{
}

// Constructor: ALMat
// Creates a new matrix that is a copy of the given matrix.
template <class T>
ALMat<T>::ALMat(const ALMat<T>& m) : ALVec<ALVec<T> >(m)
{
}

// Constructor: ALMat
// Creates a new matrix that is a copy of the given array
// of the given size.
template <class T>
ALMat<T>::ALMat(const ALVec<T>* array, int size) : ALVec<ALVec<T> >(array, size)
{
}

// Destructor: ~ALMat
// Frees the memory associated with this matrix.
template <class T>
ALMat<T>::~ALMat()
{
}

// Operator: []
// Returns the vector at the given index.
template <class T>
ALVec<T>& ALMat<T>::operator[](int index)
{
    return ALVec<ALVec<T> >::operator[](index);
}

// Operator: []
// Returns the vector at the given index.
template <class T>
const ALVec<T>& ALMat<T>::operator[](int index) const
{
    return ALVec<ALVec<T> >::operator[](index);
}


// Operator: +
// Adds the given matrix to this matrix and returns the result.
template <class T>
ALMat<T> ALMat<T>::operator+(const ALMat<T>& m)
{
    ALMat<T> result(*this);
    result += m;
    return result;
}

// Operator: -
// Subtracts the given matrix from this matrix and returns the result.
template <class T>
ALMat<T> ALMat<T>::operator-(const ALMat<T>& m)
{
    ALMat<T> result(*this);
    result -= m;
    return result;
}

// Operator: *
// Multiplies the given matrix by this matrix and returns the result.
template <class T>
ALMat<T> ALMat<T>::operator*(const ALMat<T>& m)
{
    // if its power of 2 use strassen
    if (isPowerOf2(getRows()) && isPowerOf2(getCols()) && isPowerOf2(m.getRows()) && isPowerOf2(m.getCols()))
    {
        return strassen(m);
    }
    
    ALMat<T> result;
    result.zeros(getRows(), m.getCols());
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            T sum = 0;
            for (int k = 0; k < getCols(); k++)
            {
                sum += (*this)[i][k] * m[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

// Operator: *
// Multiplies each element of this matrix by the given value.
template <class T>
ALMat<T> ALMat<T>::operator*(const T& value)
{
    ALMat<T> result(*this);
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            result.get(i).set(j, result.get(i).get(j) * value);
        }
    }
    return result;
}

// Operator: /
// Divides each element of this matrix by the given value.
template <class T>
ALMat<T> ALMat<T>::operator/(const T& value)
{
    ALMat<T> result(*this);
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            result.get(i).set(j, result.get(i).get(j) / value);
        }
    }
    return result;
}

// Operator: /
// Divides each element of this matrix by the given value.
template <class T>
ALMat<T> ALMat<T>::operator/(const ALMat<T>& m)
{
    ALMat<T> result(*this);
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            result.get(i).set(j, result.get(i).get(j) / m.get(i).get(j));
        }
    }
    return result;
}

// Operator: /=
// Divides each element of this matrix by the given value.
template <class T>
ALMat<T>& ALMat<T>::operator/=(const T& value)
{
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            (*this)[i][j] /= value;
        }
    }
    return *this;
}

// Operator: +=
// Adds the given matrix to this matrix.
template <class T>
ALMat<T> ALMat<T>::operator+=(const ALMat<T>& m)
{
    for (int i = 0; i < this->getRows(); i++)
    {
        (*this)[i] += m.get(i);
    }
    return *this;
}

// Operator: -=
// Subtracts the given matrix from this matrix.
template <class T>
ALMat<T> ALMat<T>::operator-=(const ALMat<T>& m)
{
    for (int i = 0; i < this->getRows(); i++)
    {
        (*this)[i] -= m.get(i);
    }
    return *this;
}

template <class T>
void ALMat<T>::zeros(int rows, int cols)
{
    this->clear();
    for (int i = 0; i < rows; i++)
    {
        ALVec<T> v;
        v.zeros(cols);
        this->add(v);
    }
}

template <class T>
void ALMat<T>::ones(int rows, int cols)
{
    this->clear();
    for (int i = 0; i < rows; i++)
    {
        ALVec<T> v;
        v.ones(cols);
        this->add(v);
    }
}

template <class T>
void ALMat<T>::identity(int size)
{
    this->clear();
    for (int i = 0; i < size; i++)
    {
        ALVec<T> v;
        v.zeros(size);
        v.set(i, 1);
        this->add(v);
    }
}

template <class T>
void ALMat<T>::zeros()
{
    // turn all elements to 0
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            (*this)[i].set(j, 0);
        }
    }
}

template <class T>
void ALMat<T>::ones()
{
    // turn all elements to 1
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            (*this)[i].set(j ,1);
        }
    }
}

template <class T>
void ALMat<T>::random()
{
    // turn all elements to random values 0 to 1
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            (*this)[i].set(j, (T)rand() / (T)RAND_MAX);
        }
    }
}

template <class T>
void ALMat<T>::random(int rows, int cols)
{
    this->zeros(rows, cols);
    this->random();
}

template <class T>
void ALMat<T>::identity()
{
    // return error if not square matrix
    if (this->getRows() != this->getCols())
    {
        return;
    }
    // turn all elements to 0
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            (*this)[i].set(j, 0);
        }
    }
    // turn diagonal elements to 1
    for (int i = 0; i < this->getRows(); i++)
    {
        (*this)[i].set(i, 1);
    }
}

template <class T>
void ALMat<T>::transpose()
{
    ALMat<T> result;
    result.zeros(this->getCols(), this->getRows());
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            result[j][i] = (*this)[i][j];
        }
    }
    *this = result;
}

template <class T>
T ALMat<T>::determinant()
{
    // return error if not square matrix
    if (this->getRows() != this->getCols())
    {
        return 0;
    }
    // return 1 if 1x1 matrix
    if (this->getRows() == 1)
    {
        return (*this)[0][0];
    }
    // return 0 if 2x2 matrix
    if (this->getRows() == 2)
    {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }
    // return determinant of 3x3 matrix
    if (this->getRows() == 3)
    {
        return (*this)[0][0] * ((*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1]) -
               (*this)[0][1] * ((*this)[1][0] * (*this)[2][2] - (*this)[1][2] * (*this)[2][0]) +
               (*this)[0][2] * ((*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0]);
    }
    // return determinant of nxn matrix
    T result = 0;
    for (int i = 0; i < this->getRows(); i++)
    {
        ALMat<T> submatrix;
        submatrix.zeros(this->getRows() - 1, this->getCols() - 1);
        for (int j = 1; j < this->getRows(); j++)
        {
            for (int k = 0; k < this->getCols(); k++)
            {
                if (k < i)
                {
                    submatrix[j-1][k] = (*this)[j][k];
                }
                else if (k > i)
                {
                    submatrix[j-1][k-1] = (*this)[j][k];
                }
            }
        }
        result += pow(-1, i) * (*this)[0][i] * submatrix.determinant();
    }
    return result;

}

template <class T>
ALMat<T> ALMat<T>::inverse()
{
    // return error if not square matrix
    if (this->getRows() != this->getCols())
    {
        return *this;
    }
    // return inverse of 1x1 matrix
    if (this->getRows() == 1)
    {
        ALMat<T> result;
        result.zeros(1, 1);
        result[0][0] = 1 / (*this)[0][0];
        return result;
    }
    // return inverse of 2x2 matrix
    if (this->getRows() == 2)
    {
        ALMat<T> result;
        result.zeros(2, 2);
        result[0][0] = (*this)[1][1];
        result[0][1] = -(*this)[0][1];
        result[1][0] = -(*this)[1][0];
        result[1][1] = (*this)[0][0];
        result /= this->determinant();
        return result;
    }
    // return inverse of 3x3 matrix
    if (this->getRows() == 3)
    {
        ALMat<T> result;
        result.zeros(3, 3);
        result[0][0] = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
        result[0][1] = -((*this)[1][0] * (*this)[2][2] - (*this)[1][2] * (*this)[2][0]);
        result[0][2] = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
        result[1][0] = -((*this)[0][1] * (*this)[2][2] - (*this)[0][2] * (*this)[2][1]);
        result[1][1] = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
        result[1][2] = -((*this)[0][0] * (*this)[2][1] - (*this)[0][1] * (*this)[2][0]);
        result[2][0 ] = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
        result[2][1] = -((*this)[0][0] * (*this)[1][2] - (*this)[0][2] * (*this)[1][0]);
        result[2][2] = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
        result /= this->determinant();
        return result;
    }
    // return inverse of nxn matrix
    ALMat<T> result;
    result.zeros(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            ALMat<T> submatrix;
            submatrix.zeros(this->getRows() - 1, this->getCols() - 1);
            for (int k = 0; k < this->getRows(); k++)
            {
                for (int l = 0; l < this->getCols(); l++)
                {
                    if (k < i && l < j)
                    {
                        submatrix[k][l] = (*this)[k][l];
                    }
                    else if (k < i && l > j)
                    {
                        submatrix[k][l-1] = (*this)[k][l];
                    }
                    else if (k > i && l < j)
                    {
                        submatrix[k-1][l] = (*this)[k][l];
                    }
                    else if (k > i && l > j)
                    {
                        submatrix[k-1][l-1] = (*this)[k][l];
                    }
                }
            }
            result[j][i] = pow(-1, i + j) * submatrix.determinant();
        }
    }
    result /= this->determinant();
    return result;

}

template <class T>
ALVec<T> ALMat<T>::row(int index)
{
    return this->get(index);
}

template <class T>
ALVec<T> ALMat<T>::col(int index)
{
    ALVec<T> result(this->getRows());
    for (int i = 0; i < this->getRows(); i++)
    {
        result.set(i, this->get(i).get(index));
    }
    return result;
}

template <class T>
void ALMat<T>::setRow(int index, ALVec<T> row)
{
    this->get(index) = row;
}

template <class T>
void ALMat<T>::setCol(int index, ALVec<T> col)
{
    for (int i = 0; i < this->getRows(); i++)
    {
        this->get(i).set(index, col.get(i));
    }
}

template <class T>
int ALMat<T>::getRows()
{
    return this->size();
}

template <class T>
int ALMat<T>::getRows() const
{
    return this->size();
}

template <class T>
int ALMat<T>::getCols()
{
    if (this->getRows() == 0)
    {
        return 0;
    }
    return this->get(0).size();
}

template <class T>
int ALMat<T>::getCols() const
{
    if (this->getRows() == 0)
    {
        return 0;
    }
    return this->get(0).size();
}

template <class T>
ALMat<T> ALMat<T>::strassen(const ALMat<T>& other)
{
    ALMat<T> result;
    result.zeros(this->getRows(), other.getCols());
    if (this->getRows() == 1 && other.getCols() == 1)
    {
        result[0][0] = this->get(0).get(0) * other.get(0).get(0);
        return result;
    }
    
    ALMat<T> a11, a12, a21, a22, b11, b12, b21, b22;
    a11.zeros(this->getRows() / 2, this->getCols() / 2);
    a12.zeros(this->getRows() / 2, this->getCols() / 2);
    a21.zeros(this->getRows() / 2, this->getCols() / 2);
    a22.zeros(this->getRows() / 2, this->getCols() / 2);
    b11.zeros(other.getRows() / 2, other.getCols() / 2);
    b12.zeros(other.getRows() / 2, other.getCols() / 2);
    b21.zeros(other.getRows() / 2, other.getCols() / 2);
    b22.zeros(other.getRows() / 2, other.getCols() / 2);
    for (int i = 0; i < this->getRows() / 2; i++)
    {
        for (int j = 0; j < this->getCols() / 2; j++)
        {
            a11[i][j] = this->get(i).get(j);
            a12[i][j] = this->get(i).get(j + this->getCols() / 2);
            a21[i][j] = this->get(i + this->getRows() / 2).get(j);
            a22[i][j] = this->get(i + this->getRows() / 2).get(j + this->getCols() / 2);

            b11[i][j] = other.get(i).get(j);
            b12[i][j] = other.get(i).get(j + other.getCols() / 2);
            b21[i][j] = other.get(i + other.getRows() / 2).get(j);
            b22[i][j] = other.get(i + other.getRows() / 2).get(j + other.getCols() / 2);
        }
    }

    ALMat<T> p1, p2, p3, p4, p5, p6, p7;

    p1 = (a11 + a22).strassen(b11 + b22);

    p2 = (a21 + a22).strassen(b11);

    p3 = a11.strassen(b12 - b22);

    p4 = a22.strassen(b21 - b11);

    p5 = (a11 + a12).strassen(b22);

    p6 = (a21 - a11).strassen(b11 + b12);

    p7 = (a12 - a22).strassen(b21 + b22);

    ALMat<T> c11, c12, c21, c22;

    c11 = p1 + p4 - p5 + p7;

    c12 = p3 + p5;

    c21 = p2 + p4;

    c22 = p1 - p2 + p3 + p6;

    for (int i = 0; i < this->getRows() / 2; i++)

    {

        for (int j = 0; j < this->getCols() / 2; j++)

        {
            
            result[i][j] = c11[i][j];
            result[i][j + this->getCols() / 2] = c12[i][j];
            result[i + this->getRows() / 2][j] = c21[i][j];
            result[i + this->getRows() / 2][j + this->getCols() / 2] = c22[i][j];
        }

    }

    return result;

}

template <class T>
ALVec<T> ALMat<T>::get(int index)
{
    return (*this)[index];
}

template <class T>
ALVec<T> ALMat<T>::get(int index) const
{
    return (*this)[index];
}

template <class T>
bool ALMat<T>::isPowerOf2(int n)
{
    return (n & (n - 1)) == 0;
}

#endif