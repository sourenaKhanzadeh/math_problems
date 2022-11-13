#include "../domains/linear_algebra/alvec.h"

int main(){
    ALVec<float> v1;
    ALVec<float> v2;
    v1.ones(3);
    v2 += 10;
    v2 += 3;
    v2 += 5;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v1.magnitude() << std::endl;
    std::cout << v2.unitVector() << std::endl;
    std::cout << v1.distance(v2) << std::endl;
    std::cout << v1.dotproduct(v2) << std::endl;
    std::cout << v1.angle(v2) << std::endl;

    assert(v1.size() == 3);
    assert(v2.size() == 3);
    assert(v1[0] == 1);
    assert(v1[1] == 1);
    assert(v1[2] == 1);
    assert(v2[0] == 10);
    assert(v2[1] == 3);
    assert(v2[2] == 5);
    return 0;
}