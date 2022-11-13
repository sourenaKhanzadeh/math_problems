#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>



// Class: Vector
// A class that represents a vector of objects of type T.
template <class T>
class Vector
{
public:
    // Constructor: Vector
    // Creates a new vector.
    Vector();

    // Constructor: Vector
    // Creates a new vector with the given initial capacity.
    Vector(int initialCapacity);

    // Constructor: Vector
    // Creates a new vector with the given initial capacity and
    // initial value.
    Vector(int initialCapacity, const T& initialValue);

    // Constructor: Vector
    // Creates a new vector that is a copy of the given vector.
    Vector(const Vector<T>& v);

    // Destructor: ~Vector
    // Frees the memory associated with this vector.
    ~Vector();

    // Operator: =
    // Sets this vector to be a copy of the given vector.
    Vector<T>& operator=(const Vector<T>& v);

    // Operator: []
    // Returns the element at the given index in this vector.
    T& operator[](int index);

    // Operator: []
    // Returns the element at the given index in this vector.
    const T& operator[](int index) const;

    // Operator: +=
    // Adds the given element to the end of this vector.
    Vector<T>& operator+=(const T& element);

    //Operator: -
    //Returns a new vector that is the difference of the two vectors
    Vector<T> operator-(const Vector<T>& v);

    // Operator: *
    // Returns a new vector that is the product of the two vectors
    Vector<T> operator*(const Vector<T>& v);

    // Operator: +
    // Returns a new vector that is the concatenation of this vector
    // and the given vector.
    Vector<T> operator+(const Vector<T>& v) const;

    // Operator: ==
    // Returns whether this vector is equal to the given vector.
    bool operator==(const Vector<T>& v) const;

    // Operator: !=
    // Returns whether this vector is not equal to the given vector.
    bool operator!=(const Vector<T>& v) const;

    // Operator: <<
    // Prints the given vector to the given output stream.
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
    {
        os << "[";
        for (int i = 0; i < v.count; i++) {
            if (i > 0) os << ", ";
            os << v.elements[i];
        }
        os << "]";
        return os;
    }

    

    // Method: size
    // Returns the number of elements in this vector.
    int size() const;

    // Method: isEmpty
    // Returns whether this vector contains no elements.
    bool isEmpty() const;

    // Method: clear
    // Removes all elements from this vector.
    void clear();

    // Method: get
    // Returns the element at the given index in this vector.
    T get(int index) const;

    // Method: set
    // Sets the element at the given index in this vector to the
    // given value.
    void set(int index, const T& value);

    // Method: insert
    // Inserts the given element into this vector at the given index.
    void insert(int index,const T& element);

    // Method: add
    // Adds the given element to the end of this vector.
    void add(const T& element);

    // Method: remove
    // Removes the element at the given index from this vector.
    void remove(int index);

    // Method: indexOf
    // Returns the index of the first occurrence of the given value
    // in this vector, or -1 if the value is not found.
    int indexOf(const T& value) const;

    // Method: contains
    // Returns whether the given value is contained in this vector.
    bool contains(const T& value) const;

    // Method: toString
    // Returns a printable representation of this vector.
    std::string toString() const;

    // Method: toStlVector
    // Returns an STL vector that is a copy of this vector.
    std::vector<T> toStlVector() const;

    // Method: sort
    // Sorts the elements of this vector.
    void sort();

    // Method: sort
    // Sorts the elements of this vector using the given comparison
    // function.
    void sort(bool (*cmpfn)(T, T));

    // Method: dotproduct
    // Returns the dot product of this vector and the given vector.
    T dotproduct(const Vector<T>& v) const;

    // Method: crossproduct
    // Returns the cross product of this vector and the given vector.
    Vector<T> crossproduct(const Vector<T>& v) const;

    // Method: magnitude
    // Returns the magnitude of this vector.
    T magnitude() const;

    // Method: normalize
    // Normalizes this vector.
    void normalize();

    // Method: lastindexof
    // Returns the index of the last occurrence of the given value
    // in this vector, or -1 if the value is not found.
    int lastIndexOf(const T& value) const;

    // Method: mapAll
    // Calls the given function on each element of this vector.
    void mapAll(void (*fn)(T)) const;

    // Method: reduce
    // Calls the given function on each element of this vector,
    // passing the result of the previous call as the first argument
    // to the next call.
    T reduce(T (*fn)(T, T)) const;

    // Method: filter
    // Returns a new vector containing only those elements of this
    // vector for which the given predicate function returns true.
    Vector<T> filter(bool (*fn)(T)) const;
    

private:
    // The number of elements in this vector.
    int count;

    // The capacity of this vector.
    int capacity;

    // The elements of this vector.
    T* elements;

    // The initial capacity of this vector.
    static const int INITIAL_CAPACITY = 10;

    // The growth factor of this vector.
    static const int GROWTH_FACTOR = 2;

    // Method: expandCapacity
    // Expands the capacity of this vector to be at least the given
    // value.
    void expandCapacity(int minCapacity);

    // Method: deepCopy
    // Copies the given vector into this vector.
    void deepCopy(const Vector<T>& v);
};


#endif