#include<iostream>
#include<eigen3/Eigen/Dense>

using std::cout;
using std::endl;

int main(int argc, char ** argv) {

    Eigen::MatrixXi matrix_a(5, 5); // dinamic ize
    matrix_a << 1, 1, 1, 1, 1,
                2, 2, 2, 2, 2,
                3, 3, 3, 3, 3,
                4, 4, 4, 4, 4,
                5, 5, 5, 5, 5;

    std::cout << matrix_a(1) << std::endl; // 2
    matrix_a.transposeInPlace();
    std::cout << matrix_a(1 ) << std::endl; // 1

    Eigen::Matrix<float, 4, 4> A;
    A << 0, 2, 0, 0,
        1, 23, 0 ,0,
        7, 0, 0, 0,
        0, 0, 0, 0;

    std::cout << A(1, 0) << std::endl; // 0

    Eigen::Matrix<float, 2, 2> B, C; 
    B << 
        1, 2, 
        3, 4;
    C << 
        1, 2,
        3, 4;

    std::cout << B * C << std::endl; 
    /* 
    7 10
    15 22 
    */

    std::cout << B.array() * C.array() << std::endl;
    /*
    1  4
    9 16
    */

    Eigen::Array<float, 2, 2> array_A, array_B;
    array_A << 1, 2, 3, 4;
    array_B << 1, 2, 3, 4;

    std::cout << array_A * array_B << std::endl << std::endl;
    /*
    1  4
    9 16
    */

   // special matrices and arrays initialization
   Eigen::Matrix<float, 3, 3> A_z = Eigen::Matrix<float, 3, 3>::Zero(3, 3);
   Eigen::Matrix3f B_z = Eigen::Matrix3f::Zero(3, 3); // same
   std::cout << "A and B for zeros: " << std::endl << "A: " << A_z << std::endl << "B: " << B_z << std::endl;

   Eigen::Matrix3f C_ones = Eigen::Matrix3f::Ones(3, 3);
   cout << "Ones: " << endl <<C_ones << endl;

    int x = 10, y = 10;
   Eigen::MatrixXf w0 = Eigen::MatrixXf::Random(x, y)*2;
   cout << "random:" << endl << w0 << endl;
}