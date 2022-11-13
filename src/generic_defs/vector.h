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

    // Operator: +=
    // Adds the given vector to the end of this vector.
    Vector<T>& operator+=(const Vector<T>& v);

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
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v){
        os << v.toString();
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

    // Method: pop
    // Removes the last element from this vector.
    void pop();

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

    // Method: resize
    // Resizes the vector to the given size.
    void resize(int size);

    // Method: getCapacity
    // Returns the capacity of this vector.
    int getCapacity() const;

    // Method: swap
    // Swaps the elements at the given indices.
    void swap(int i, int j);

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

// Implementation section

template <typename T>
Vector<T>::Vector() {
    count = 0;
    capacity = INITIAL_CAPACITY;
    elements = new T[capacity];
}

template <typename T>
Vector<T>::Vector(int initialCapacity) {
    count = 0;
    capacity = initialCapacity;
    elements = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) {
    deepCopy(v);
}

template <typename T>
Vector<T>::~Vector() {
    delete[] elements;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (this != &v) {
        delete[] elements;
        deepCopy(v);
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const T& element) {
    add(element);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        add(v[i]);
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= count) {
        error("Index out of range");
    }
    return elements[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= count) {
        error("Index out of range");
    }
    return elements[index];
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& v) const {
    if (count != v.count) {
        return false;
    }
    for (int i = 0; i < count; i++) {
        if (elements[i] != v.elements[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& v) const {
    return !(*this == v);
}

template <typename T>
int Vector<T>::size() const {
    return count;
}

template <typename T>
bool Vector<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
void Vector<T>::clear() {
    count = 0;
}

template <typename T>
T Vector<T>::get(int index) const {
    return (*this)[index];
}

template <typename T>
void Vector<T>::pop() {
    if (count == 0) {
        error("pop: vector is empty");
    }
    count--;
}

template <typename T>
void Vector<T>::set(int index, const T& value) {
    // set specified element to given value
    elements[index] = value;
}

template <typename T>
void Vector<T>::insert(int index, const T& element) {
    if (index < 0 || index > count) {
        error("Index out of range");
    }
    if (count == capacity) {
        expandCapacity(count + 1);
    }

    for (int i = count; i > index; i--) {
        std::cout << elements[i] << ", " << elements[i-1] << std::endl;
        elements[i] = elements[i - 1];
    }
    elements[index] = element;
    count++;
}

template <typename T>
void Vector<T>::add(const T& element) {
    insert(count, element);
}

template <typename T>
void Vector<T>::remove(int index) {
    if (index < 0 || index >= count) {
        error("Index out of range");
    }
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    count--;
}

template <typename T>
int Vector<T>::indexOf(const T& value) const {
    for (int i = 0; i < count; i++) {
        if (elements[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int Vector<T>::lastIndexOf(const T& value) const {
    for (int i = count - 1; i >= 0; i--) {
        if (elements[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool Vector<T>::contains(const T& value) const {
    return indexOf(value) != -1;
}

template <typename T>
void Vector<T>::mapAll(void (*fn)(T)) const{
    for (int i = 0; i < count; i++) {
        fn(elements[i]);
    }
}

template <typename T>
Vector<T> Vector<T>::filter(bool (*fn)(T)) const {
    Vector<T> result;
    for (int i = 0; i < count; i++) {
        if (fn(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}

template <typename T>
void Vector<T>::expandCapacity(int minCapacity) {
    if (capacity < minCapacity) {
        capacity = std::max(minCapacity, capacity * GROWTH_FACTOR);
        T* oldElements = elements;
        elements = new T[capacity];
        for (int i = 0; i < count; i++) {
            elements[i] = oldElements[i];
        }
        delete[] oldElements;
    }
}

template <typename T>
void Vector<T>::deepCopy(const Vector<T>& v) {
    count = v.count;
    capacity = v.capacity;
    elements = new T[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = v.elements[i];
    }
}


template <typename T>
void Vector<T>::error(std::string msg) const {
    throw std::out_of_range(msg);
}

template <typename T>
void Vector<T>::resize(int newCapacity) {
    if (newCapacity < 0) {
        error("Illegal capacity");
    }
    count = newCapacity;
    capacity = newCapacity;
    T* oldElements = elements;
    elements = new T[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = oldElements[i];
    }
    delete[] oldElements;

}

template <typename T>
int Vector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
std::string Vector<T>::toString() const {
    // make a string representation of the vector
    std::ostringstream os;
    os << "[";
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << elements[i];
    }
    os << "]";
    return os.str();
}


template <typename T>
void Vector<T>::swap(int i, int j) {
    T temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;

}


#endif