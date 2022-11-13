#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>



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
    Vector<T> operator*(const T v);
    T operator*(const Vector<T>& v);

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

    // Method: crossproduct
    // Returns the cross product of this vector and the given vector.
    Vector<T> crossproduct(const Vector<T>& v) const;

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
    
    // Method: shape
    // Returns a printable representation of this vector.
    std::string shape() const;

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

    // Method: error
    // Throws an error with the given message.
    void error(std::string msg) const;

};


template <class T>
Vector<T>::Vector() {
    capacity = 10;
    count = 0;
    elements = new T[capacity];
}

template <class T>
Vector<T>::Vector(int initialCapacity) {
    capacity = initialCapacity;
    count = 0;
    elements = new T[capacity];
}

template <class T>
Vector<T>::Vector(int initialCapacity, const T& initialValue) {
    capacity = initialCapacity;
    count = capacity;
    elements = new T[capacity];
    for (int i = 0; i < capacity; i++) {
        elements[i] = initialValue;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T>& v) {
    capacity = v.capacity;
    count = v.count;
    elements = new T[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = v.elements[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    delete[] elements;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (this != &v) {
        delete[] elements;
        capacity = v.capacity;
        count = v.count;
        elements = new T[capacity];
        for (int i = 0; i < count; i++) {
            elements[i] = v.elements[i];
        }
    }
    return *this;
}

template <class T>
T& Vector<T>::operator[](int index) {
    return elements[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const {
    return elements[index];
}

template <class T>
Vector<T>& Vector<T>::operator+=(const T& element) {
    if (count == capacity) {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < count; i++) {
            newArray[i] = elements[i];
        }
        delete[] elements;
        elements = newArray;
    }
    elements[count] = element;
    count++;
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& v) const {
    assert(count == v.count);
    Vector<T> result = *this;
    for (int i = 0; i < v.count; i++) {
        result[i] += v.elements[i];
    }
    return result;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& v) {
    assert(count == v.count);
    Vector<T> result = *this;
    for (int i = 0; i < v.count; i++) {
        result[i] -= v.elements[i];
    }
    return result;
}

template <class T>
T Vector<T>::operator*(const Vector<T>& v) {
    assert(count == v.count);
    return dotproduct(v);
}

template <class T>
Vector<T> Vector<T>::operator*(const T v) {
    Vector<T> result = *this;
    for (int i = 0; i < count; i++) {
        result[i] *= v;
    }
    return result;
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& v) const {
    if (count != v.count) return false;
    for (int i = 0; i < count; i++) {
        if (elements[i] != v.elements[i]) return false;
    }
    return true;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& v) const {
    return !(*this == v);
}

template <class T>
int Vector<T>::size() const {
    return count;
}

template <class T>
bool Vector<T>::isEmpty() const {
    return count == 0;
}

template <class T>
void Vector<T>::add(const T& element) {
    *this += element;
}

template <class T>
void Vector<T>::insert(int index, const T& element) {
    if (count == capacity) {
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i = 0; i < count; i++) {
            newArray[i] = elements[i];
        }
        delete[] elements;
        elements = newArray;
    }
    for (int i = count; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = element;
    count++;
}

template <class T>
void Vector<T>::remove(int index) {
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    count--;
}

template <class T>
void Vector<T>::clear() {
    count = 0;
}

template <class T>
bool Vector<T>::contains(const T& element) const {
    for (int i = 0; i < count; i++) {
        if (elements[i] == element) return true;
    }
    return false;
}

template <class T>
int Vector<T>::indexOf(const T& element) const {
    for (int i = 0; i < count; i++) {
        if (elements[i] == element) return i;
    }
    return -1;
}

template <class T>
int Vector<T>::lastIndexOf(const T& element) const {
    for (int i = count - 1; i >= 0; i--) {
        if (elements[i] == element) return i;
    }
    return -1;
}

template <class T>
T Vector<T>::get(int index) const {
    return elements[index];
}

template <class T>
void Vector<T>::set(int index, const T& element) {
    elements[index] = element;
}

template <class T>
void Vector<T>::mapAll(void (*fn)(T)) const{
    for (int i = 0; i < count; i++) {
        fn(elements[i]);
    }
}

template <class T>
T Vector<T>::reduce(T (*fn)(T, T)) const {
    T result = elements[0];
    for (int i = 1; i < count; i++) {
        result = fn(result, elements[i]);
    }
    return result;
}

template <class T>
Vector<T> Vector<T>::filter(bool (*fn)(T)) const {
    Vector<T> result;
    for (int i = 0; i < count; i++) {
        if (fn(elements[i])) {
            result += elements[i];
        }
    }
    return result;
}


template <class T>
std::string Vector<T>::toString() const {
    std::ostringstream os;
    os << "[";
    for (int i = 0; i < count; i++) {
        os << elements[i];
        if (i < count - 1) os << ", ";
    }
    os << "]";
    return os.str();
}

template <class T>
std::vector<T> Vector<T>::toStlVector() const {
    std::vector<T> result;
    for (int i = 0; i < count; i++) {
        result.push_back(elements[i]);
    }
    return result;
}

template <class T>
void Vector<T>::sort() {
    sort([](T a, T b) { return a < b; });
}

template <class T>
void Vector<T>::sort(bool (*fn)(T, T)) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (fn(elements[j], elements[i])) {
                T temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }
}

template <class T>
std::string Vector<T>::shape() const {
    std::ostringstream os;
    os << "(1, " << count << ")";
    return os.str();
}

template <class T>
void Vector<T>::expandCapacity(int newCapacity) {
    if (newCapacity < count) {
        error("Vector::expandCapacity: newCapacity must be >= count");
    }
    T* newArray = new T[newCapacity];
    for (int i = 0; i < count; i++) {
        newArray[i] = elements[i];
    }
    delete[] elements;
    elements = newArray;
    capacity = newCapacity;
}

template <class T>
void Vector<T>::deepCopy(const Vector<T>& v) {
    count = v.count;
    capacity = v.capacity;
    elements = new T[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = v.elements[i];
    }
}

template <class T>
void Vector<T>::error(std::string msg) const {
    throw std::runtime_error(msg);
}


#endif