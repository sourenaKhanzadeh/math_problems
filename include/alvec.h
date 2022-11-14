#ifndef ALVEC_H
#define ALVEC_H

#include "vector.h"


// Class: ALVec
// A class that represents a vector of objects of type T.
// and can do linear algebra operations on them
template <class T>
class ALVec : public Vector<T>
{
public:
    // Constructor: ALVec
    // Creates a new vector.
    ALVec();

    // Constructor: ALVec
    // Creates a new vector with the given initial capacity.
    ALVec(int initialCapacity);

    // Constructor: ALVec
    // Creates a new vector with the given initial capacity and
    // initial value.
    ALVec(int initialCapacity, const T& initialValue);

    // Constructor: ALVec
    // Creates a new vector that is a copy of the given vector.
    ALVec(const ALVec<T>& v);

    // Constructor: ALVec
    // Creates a new vector that is a copy of the given array
    // of the given size.
    ALVec(const T* array, int size);

    // Destructor: ~ALVec
    // Frees the memory associated with this vector.
    ~ALVec();

    // Operator: /=
    // Divides each element of this vector by the given value.
    ALVec<T>& operator/=(const T& value); 

    // Operator: *=
    // Multiplies each element of this vector by the given value.
    ALVec<T>& operator*=(const T& value);

    // Operator: +=
    // Adds the given vector to this vector.
    ALVec<T>& operator+=(const ALVec<T>& v);

    // Operator: -=
    // Subtracts the given vector from this vector.
    ALVec<T>& operator-=(const ALVec<T>& v);

    // Operator: +
    // Returns the sum of this vector and the given vector.
    ALVec<T> operator+(const ALVec<T>& v) const;

    // Operator: -
    // Returns the difference of this vector and the given vector.
    ALVec<T> operator-(const ALVec<T>& v) const;


    // Operator: /
    // Returns the element-wise division of this vector by the given vector.
    ALVec<T> operator/(const ALVec<T>& v) const;

    // Operator: *
    // Returns the element-wise multiplication of this vector by the given vector.
    ALVec<T> operator*(const ALVec<T>& v) const;

    // Operator: /
    // Returns the element-wise division of this vector by the given value.
    ALVec<T> operator/(const T& value) const;

    // Operator: *
    // Returns the element-wise multiplication of this vector by the given value.
    ALVec<T> operator*(const T& value) const;

    // Method: piecewiseMultiply
    // Multiplies each element of this vector by the corresponding
    // element of the given vector.
    void piecewiseMultiply(const ALVec<T>& v);

    // Method: zeros
    // creates a vector of zeros of the given size
    void zeros(int size);

    // Method: zeros
    // creates a vector of zeros of the given size
    void zeros();

    // Method: ones
    // creates a vector of ones of the given size
    void ones(int size);

    // Method: ones
    // creates a vector of ones of the given size
    void ones();

    // Method: random
    // creates a vector of random numbers of the given size
    void random(int size);

    // Method: distance
    // returns the distance between this vector and the given vector
    double distance(const ALVec<T>& v);

    // Method: unit vector
    // returns a unit vector in the direction of this vector
    ALVec<T> unitVector();

    // Method: magnitude
    // Returns the magnitude of this vector.
    T magnitude() const;


    // Method: normalize
    // Normalizes this vector.
    void normalize();

    // Method: angle
    // returns the angle between this vector and the given vector
    double angle(const ALVec<T>& v);


    // Method: dotproduct
    // Returns the dot product of this vector and the given vector.
    T dotproduct(const ALVec<T>& v) const;

    // Method: isOrthogonal
    // Returns true if this vector is orthogonal to the given vector.
    bool isOrthogonal(const ALVec<T>& v) const;

    // Method: isParallel
    // Returns true if this vector is parallel to the given vector.
    bool isParallel(const ALVec<T>& v) const;

    // Method: triangleInequality
    // Returns true if the triangle inequality holds for this vector
    // and the given vector.
    bool triangleInequality(const ALVec<T>& v) const;

};

template <class T>
ALVec<T>::ALVec() : Vector<T>()
{
}

template <class T>
ALVec<T>::ALVec(int initialCapacity) : Vector<T>(initialCapacity)
{
}

template <class T>
ALVec<T>::ALVec(int initialCapacity, const T& initialValue) : Vector<T>(initialCapacity, initialValue)
{
}

template <class T>
ALVec<T>::ALVec(const ALVec<T>& v) : Vector<T>(v)
{
}

template <class T>
ALVec<T>::~ALVec()
{
}

template <class T>
ALVec<T>::ALVec(const T* array, int size) : Vector<T>(array, size)
{
}

template <class T>
ALVec<T>& ALVec<T>::operator/=(const T& value)
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] /= value;
    }
    return *this;
}

template <class T>
ALVec<T>& ALVec<T>::operator*=(const T& value)
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] *= value;
    }
    return *this;
}

template <class T>
ALVec<T>& ALVec<T>::operator+=(const ALVec<T>& v)
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] += v[i];
    }
    return *this;
}

template <class T>
ALVec<T>& ALVec<T>::operator-=(const ALVec<T>& v)
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] -= v[i];
    }
    return *this;
}

template <class T>
ALVec<T> ALVec<T>::operator+(const ALVec<T>& v) const
{
    ALVec<T> result(*this);
    result += v;
    return result;
}

template <class T>
ALVec<T> ALVec<T>::operator-(const ALVec<T>& v) const
{
    ALVec<T> result(*this);
    result -= v;
    return result;
}

template <class T>
ALVec<T> ALVec<T>::operator/(const ALVec<T>& v) const
{
    ALVec<T> result(*this);
    for (int i = 0; i < this->size(); i++)
    {
        result[i] /= v[i];
    }
    return result;
}

template <class T>
ALVec<T> ALVec<T>::operator*(const ALVec<T>& v) const
{
    ALVec<T> result(*this);
    for (int i = 0; i < this->size(); i++)
    {
        result[i] *= v[i];
    }
    return result;
}

template <class T>
ALVec<T> ALVec<T>::operator/(const T& value) const
{
    ALVec<T> result(*this);
    result /= value;
    return result;
}

template <class T>
ALVec<T> ALVec<T>::operator*(const T& value) const
{
    ALVec<T> result(*this);
    result *= value;
    return result;
}



template <class T>
void ALVec<T>::piecewiseMultiply(const ALVec<T>& v)
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] *= v[i];
    }
}

template <class T>
void ALVec<T>::zeros(int size)
{
    this->resize(size);
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] = 0;
    }
}

template <class T>
void ALVec<T>::zeros()
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] = 0;
    }
}

template <class T>
void ALVec<T>::ones(int size)
{   
    this->resize(size);
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] = 1;
    }
}

template <class T>
void ALVec<T>::ones()
{
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] = 1;
    }
}

template <class T>
void ALVec<T>::random(int size)
{
    this->resize(size);
    for (int i = 0; i < this->size(); i++)
    {
        (*this)[i] = rand();
    }
}

template <class T>
double ALVec<T>::distance(const ALVec<T>& v)
{
    double sum = 0;
    for (int i = 0; i < this->size(); i++)
    {
        sum += pow((*this)[i] - v[i], 2);
    }
    return sqrt(sum);
}

template <class T>
ALVec<T> ALVec<T>::unitVector()
{
    ALVec<T> v(*this);
    v /= v.magnitude();
    return v;
}


template <class T>
double ALVec<T>::angle(const ALVec<T>& v)
{
    return acos(this->dotproduct(v) / (this->magnitude() * v.magnitude()));
}


template <class T>
T ALVec<T>::magnitude() const {
    return sqrt(dotproduct(*this));
}


template <class T>
void ALVec<T>::normalize(){
    *this /= magnitude();
}


template <class T>
T ALVec<T>::dotproduct(const ALVec<T>& v) const {
    // check if the type is numeric
    static_assert(std::is_arithmetic<T>::value, "T must be numeric");
    T sum = 0;
    for (int i = 0; i < this->size(); i++)
    {
        sum += (*this)[i] * v[i];
    }
    return sum;
}

template <class T>
bool ALVec<T>::isOrthogonal(const ALVec<T>& v) const {
    return dotproduct(v) == 0;
}

template <class T>
bool ALVec<T>::isParallel(const ALVec<T>& v) const {
    return dotproduct(v) == magnitude() * v.magnitude();
}

template <class T>
bool ALVec<T>::triangleInequality(const ALVec<T>& v) const {
    return distance(v) <= magnitude() + v.magnitude();
}

#endif