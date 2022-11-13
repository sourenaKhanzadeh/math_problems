#include "../domains/linear_algebra/almat.h"

int main(){
    ALMat<float> m;
    ALMat<float> m2;
    
    m.random(8, 8);
    m2.ones(8, 8);
    // m3.identity();
    // v.ones(4);

    std::cout << m << std::endl;
    m.transpose();

    std::cout << m << std::endl;

    std::cout << m.inverse() << std::endl;
    // std::cout << m2 << std::endl;
    // std::cout << m + m2 << std::endl;
    // std::cout << m - m2 << std::endl;
    std::cout << m.determinant() << std::endl;
    // std::cout << m / m2 << std::endl;
    // std::cout << v[2] << std::endl;

    return 0;
}