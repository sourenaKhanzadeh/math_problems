#include "../domains/linear_algebra/almat.h"

int main(){
    ALMat<float> m;
    ALMat<float> m2;
    
    m.ones(65, 65);
    m2.ones(65, 65);
    // m3.identity();
    // v.ones(4);

    // std::cout << m << std::endl;
    // std::cout << m2 << std::endl;
    // std::cout << m + m2 << std::endl;
    // std::cout << m - m2 << std::endl;
    std::cout << m * m2 << std::endl;
    // std::cout << m / m2 << std::endl;
    // std::cout << v[2] << std::endl;

    return 0;
}