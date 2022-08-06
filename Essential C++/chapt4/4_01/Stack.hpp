#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Stack
{
public:
    bool push(const string &elem);
    bool pop(string &elem);
    bool peek(string &elem);
    bool empty() {return _stack.empty();} //定义classe主体内，提高效率，被称为inline函数
    bool full() {return _stack.max_size() == _stack.size();}
    int size(){return _stack.size();}

private:
    vector<string> _stack; //定义一个私有的容器
};