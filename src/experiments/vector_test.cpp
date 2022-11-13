#include "../domains/linear_algebra/almat.h"

int main(){
    ALMat<float> m;
    ALMat<float> m2;
    ALMat<float> m3;
    
    m.zeros(3,3);
    m2.ones(3,3);
    m3.identity(3);
    m3.identity(5);
    m3.ones();
    m3.zeros();
    // m3.identity();
    // v.ones(4);

    std::cout << m << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m3 << std::endl;
    // std::cout << v[2] << std::endl;

    return 0;
}