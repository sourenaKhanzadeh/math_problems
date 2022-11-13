#include "../domains/linear_algebra/alvec.h"
#include "../domains/linear_algebra/almat.h"

int main(){
    ALMat<float> m;

    m.zeros(3,3);

    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;
    m[2][0] = 7;
    m[2][1] = 8;
    m[2][2] = 9;


    std::cout << m << std::endl;

    return 0;
}