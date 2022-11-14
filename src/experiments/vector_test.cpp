#include "../../include/almat.h"

int main(){
    ALMat<float> A(3, 3, 1.0);
    std::cout << A << std::endl;
    A.identity();
    

    std::cout << A << std::endl;
    

    return 0;
}