#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void display(vector<int> *vec, ostream & os=cout);
void swap( int *val1, int *val2);
void bubble_sort(vector<int> *vec, ofstream * ofil = 0);

int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);
    cout << "vector before sort: ";
    display(&vec); //命令行显示排序前数列
    
    ofstream ofil("data.txt"); //创建文件
    bubble_sort(&vec, &ofil);
    cout << "vector after sort: ";
    display(&vec); //命令行显示排序后数列
    // display(&vec, ofil); 
    // 将数列输出到文件中
    return 0;
}

void display(vector<int> *vec, ostream & os )
{
    for (int ix = 0; ix < vec->size(); ix++)
        os << (*vec)[ix] << ' ';
    os << endl;
}

void swap( int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void bubble_sort(vector<int> *vec, ofstream * ofil )
{
    for (int ix = 0; ix < vec->size()-1; ix++)
    {
        for(int jx = ix+1; jx < vec->size(); jx++)
            if( (*vec)[ix] > (*vec)[jx] )
            {
                swap( (*vec)[ix], (*vec)[jx]);
            }
        if(ofil != 0)
            display(vec, *ofil); //此处vec传的是地址，ofil传的是ostream具体对象     
    }
    
}