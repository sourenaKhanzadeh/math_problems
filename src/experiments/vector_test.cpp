#include "../generic_defs/vector.h"

int main(){
    Vector<int> v1;
    Vector<int> v2(10);
    Vector<int> v3(10, 5);
    Vector<int> v4(v3);
    Vector<int> v5;
    v5 = v4;
    Vector<int> v6;
    v6 += 5;
    Vector<int> v7;
    v7 = v6 - v5;
    Vector<int> v8;
    v8 = v6 * v5;
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;
    std::cout << v5 << std::endl;
    return 0;
}