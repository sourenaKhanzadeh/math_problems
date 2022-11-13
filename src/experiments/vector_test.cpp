#include "../generic_defs/vector.h"

int main(){
    Vector<int> v1;

    v1 += 1;
    v1 += 2;
    v1 += 3;

    Vector<int> v2 = v1;
    Vector<int> v3 = v1 + v2;
    int dot = v3 * v1;
    Vector<int> v4 = v3 * 2;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v4 << std::endl;
    std::cout << dot << std::endl;
    std::cout << v4.shape() << std::endl; 
    return 0;
}