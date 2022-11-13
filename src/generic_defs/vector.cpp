
#include "vector.h"


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
    Vector<T> result = *this;
    for (int i = 0; i < v.count; i++) {
        result += v.elements[i];
    }
    return result;
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& v) {
    Vector<T> result = *this;
    for (int i = 0; i < v.count; i++) {
        for (int j = 0; j < result.count; j++) {
            if (result.elements[j] == v.elements[i]) {
                result.elements[j] = result.elements[result.count - 1];
                result.count--;
                break;
            }
        }
    }
    return result;
}

template <class T>
Vector<T> Vector<T>::operator*(const Vector<T>& v) {
    Vector<T> result;
    for (int i = 0; i < v.count; i++) {
        for (int j = 0; j < count; j++) {
            if (elements[j] == v.elements[i]) {
                result += elements[j];
                break;
            }
        }
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
T Vector<T>::dotproduct(const Vector<T>& v) const {
    // check if the type is numeric
    static_assert(std::is_arithmetic<T>::value, "Vector::dotproduct: type must be numeric");
    T result = 0;
    for (int i = 0; i < count; i++) {
        result += elements[i] * v.elements[i];
    }
    return result;
}

template <class T>
T Vector<T>::magnitude() const {
    return sqrt(dotproduct(*this));
}

template <class T>
void Vector<T>::normalize(){
    T mag = magnitude();
    for (int i = 0; i < count; i++) {
        elements[i] /= mag;
    }
}


//explicit instantiations   
template class Vector<int>;
template class Vector<double>;
template class Vector<float>;