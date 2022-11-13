#include "../domains/linear_algebra/almat.h"

int main(){
    ALMat<float> m;
    ALMat<float> m2;
    
    m.zeros(3,3);
    
    m[0][0] = 3;
    m[0][1] = 1;
    m[0][2] = -1;

    m[1][0] = 2;
    m[1][1] = -2;
    m[1][2] = 1;

    m[2][0] = 1;
    m[2][1] = 1;
    m[2][2] = 1;

    ALVec<float> v;
    v.zeros(3);
    v[0] = 9;
    v[1] = -3;
    v[2] = 7;

    std::cout << m << std::endl;
    std::cout << v << std::endl;

    std::cout << m.solve(v) << std::endl;

    return 0;
}