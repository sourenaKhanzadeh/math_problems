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

    // Operator: +=
    // Adds the given matrix to this matrix.
    ALMat<T> operator+=(const ALMat<T>& m);

    // Operator: -=
    // Subtracts the given matrix from this matrix.
    ALMat<T> operator-=(const ALMat<T>& m);

    // Operator <<
    // Prints the matrix to the given output stream.
    friend std::ostream& operator<<(std::ostream& out, const ALMat<T>& m)
    {
        // print as an array of arrays
        out << "[";
        for (int i = 0; i < m.size(); i++)
        {
            out << "[";
            for (int j = 0; j < m[i].size(); j++)
            {
                out << m[i][j];
                if (j < m[i].size() - 1)
                    out << ", ";
            }
            out << "]";
        }
        out << "]";
        return out;
    }

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

    // Method: identity
    // creates an identity matrix of the given size
    void identity(int size);

    // Method: identity
    // creates an identity matrix of the given size
    void identity();

    // Method: transpose
    // returns the transpose of the matrix
    ALMat<T> transpose();

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

    // Method: getCols
    // returns the number of cols in the matrix
    int getCols();

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
    ALMat<T> result;
    result.zeros(this->getRows(), m.getCols());
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            T sum = 0;
            for (int k = 0; k < this->getCols(); k++)
            {
                sum += this->get(i).get(k) * m.get(k).get(j);
            }
            result.get(i).set(j, sum);
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

// Operator: +=
// Adds the given matrix to this matrix.
template <class T>
ALMat<T> ALMat<T>::operator+=(const ALMat<T>& m)
{
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            this->get(i).set(j, this->get(i).get(j) + m.get(i).get(j));
        }
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
        for (int j = 0; j < this->getCols(); j++)
        {
            this->get(i).set(j, this->get(i).get(j) - m.get(i).get(j));
        }
    }
    return *this;
}

template <class T>
void ALMat<T>::zeros(int rows, int cols)
{
    this->clear();
    for (int i = 0; i < rows; i++)
    {
        ALVec<T> v(cols);
        this->add(v);
    }
}

template <class T>
void ALMat<T>::ones(int rows, int cols)
{
    this->clear();
    for (int i = 0; i < rows; i++)
    {
        ALVec<T> v(cols);
        v.ones();
        this->add(v);
    }
}

template <class T>
void ALMat<T>::identity(int size)
{
    this->clear();
    for (int i = 0; i < size; i++)
    {
        ALVec<T> v(size);
        v.zeros();
        v.set(i, 1);
        this->add(v);
    }
}

template <class T>
void ALMat<T>::zeros()
{
    for (int i = 0; i < this->getRows(); i++)
    {
        this->get(i).zeros();
    }
}

template <class T>
void ALMat<T>::ones()
{
    for (int i = 0; i < this->getRows(); i++)
    {
        this->get(i).ones();
    }
}

template <class T>
void ALMat<T>::identity()
{
    for (int i = 0; i < this->getRows(); i++)
    {
        this->get(i).zeros();
        this->get(i).set(i, 1);
    }
}

template <class T>
ALMat<T> ALMat<T>::transpose()
{
    ALMat<T> result;
    result.zeros(this->getCols(), this->getRows());
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            result.get(j).set(i, this->get(i).get(j));
        }
    }
    *this = result;
}

template <class T>
T ALMat<T>::determinant()
{
    if (this->getRows() != this->getCols())
    {
        return 0;
    }
    if (this->getRows() == 1)
    {
        return this->get(0).get(0);
    }
    if (this->getRows() == 2)
    {
        return this->get(0).get(0) * this->get(1).get(1) - this->get(0).get(1) * this->get(1).get(0);
    }
    T result = 0;
    for (int i = 0; i < this->getCols(); i++)
    {
        ALMat<T> sub;
        sub.zeros(this->getRows() - 1, this->getCols() - 1);
        for (int j = 1; j < this->getRows(); j++)
        {
            for (int k = 0; k < this->getCols(); k++)
            {
                if (k < i)
                {
                    sub.get(j - 1).set(k, this->get(j).get(k));
                }
                else if (k > i)
                {
                    sub.get(j - 1).set(k - 1, this->get(j).get(k));
                }
            }
        }
        result += this->get(0).get(i) * sub.determinant() * (i % 2 == 0 ? 1 : -1);
    }
    return result;
}

template <class T>
ALMat<T> ALMat<T>::inverse()
{
    ALMat<T> result;
    result.zeros(this->getRows(), this->getCols());
    T det = this->determinant();
    if (det == 0)
    {
        return result;
    }
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getCols(); j++)
        {
            ALMat<T> sub;
            sub.zeros(this->getRows() - 1, this->getCols() - 1);
            for (int k = 0; k < this->getRows(); k++)
            {
                for (int l = 0; l < this->getCols(); l++)
                {
                    if (k < i && l < j)
                    {
                        sub.get(k).set(l, this->get(k).get(l));
                    }
                    else if (k < i && l > j)
                    {
                        sub.get(k).set(l - 1, this->get(k).get(l));
                    }
                    else if (k > i && l < j)
                    {
                        sub.get(k - 1).set(l, this->get(k).get(l));
                    }
                    else if (k > i && l > j)
                    {
                        sub.get(k - 1).set(l - 1, this->get(k).get(l));
                    }
                }
            }
            result.get(i).set(j, sub.determinant() * ((i + j) % 2 == 0 ? 1 : -1));
        }
    }
    result.transpose();
    result /= det;
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
int ALMat<T>::getCols()
{
    if (this->getRows() == 0)
    {
        return 0;
    }
    return this->get(0).size();
}

#endif