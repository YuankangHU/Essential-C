#include "Matrix.hpp"

int main()
{
    Matrix mat1(8, 4); //mat的多种构造函数方式保证了mat的正常释放
    {
        Matrix mat2;
        mat2 = mat1; //欲保证正常释放，还需自定义运算符重载函数
    }

    cout << "Bye" << endl;
    return 0;
}