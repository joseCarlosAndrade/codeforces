
#include<iostream>
#include<vector>

#include"../include/Matrices.hpp"

int main() {
    // float a[2] = {1, 2};
    // float b[3] = { 5, 5, 5};
    // GenMatrix4x4f mat(4, 4);
    // GenMatrix4x4f mat_b(4, 4);
    // mat(0, 3) = 1;
    // // std::cout << mat. << std::endl;
    // mat.setMatrix(a, 2);
    // mat_b.setMatrix(b, 3);
    // mat.printM();
    // mat_b.printM();

    // GenMatrix4x4f mat_sum = mat + mat_b;
    // mat_sum.printM();
    // GenMatrix4x4f point(4, 1);
    // point(0, 0) = 1;
    // point(1, 0) = 3;
    // point(2, 0) = 2;
    // point.print();
    // GenMatrix4x4f mat_mult = mat*mat;
    // // std::cout << "mat mult r c: " << mat_mult.getRows() << " " << mat_mult.getColumns() << std::endl;
    // // mat_mult = mat_mult*point;
    // mat.print();
    // mat_mult.print();

    // MatrixIdentity identity(3);
    // MatrixRotationX rotation((2*3.1415), 4);

    // identity.print();

    // std::cout << "rotation: " << std::endl;
    // rotation.print();


    MatrixTranslation translation(4, 2, -1, -4); // size , x, y, z
    MatrixRotationX rotation(5);
    // GenMatrix4x4f point(4, 1);
    // float a[16] = {4, 1,0,1};

    // point.setMatrixCols(a, 4);
    GenMatrix4x4f point(4, 1, 0);
    // F4Point point(a);

    std::cout << "Original point: " << std::endl;
    point.print();

     point = rotation * point;

    std::cout << "Translation matrix: " << std::endl;
    translation.print();

    // GenMatrix4x4f identity(true);
    // rotation = identity * rotation;

    std::cout << "Transformed point: " << std::endl;
    point.print();

}