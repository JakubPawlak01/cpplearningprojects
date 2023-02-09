#include <iostream>
#include <memory>
#include <vector>
#include "head/matrix.hpp"

int main(){
    Matrix<int> m1{2,2};
    m1.matrix[0][0] = 3;
    m1.matrix[0][1] = 4;
    m1.matrix[1][0] = 5;
    m1.matrix[1][1] = 6;
    Matrix<int> m2{2,3};
    m2.matrix[0][0] = 1;
    m2.matrix[0][1] = 2;
    m2.matrix[0][2] = 10;
    m2.matrix[1][0] = 3;
    m2.matrix[1][1] = 4;
    m2.matrix[1][2] = 5;
    Matrix<int> m3;
    try{
    m3 = m1 + m2;
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << '\n';
    }
    std::cout <<m1<< std::endl;
    std::cout <<m2<< std::endl;
    std::cout <<m3<< std::endl;
    return 0;
}