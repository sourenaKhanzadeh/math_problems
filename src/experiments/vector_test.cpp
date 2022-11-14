#include "../domains/linear_algebra/almat.h"

int main(){
    ALMat<float> A;
    A.zeros(3,3);
    
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;
    

    std::cout << A << std::endl;
    

    return 0;
}