#include "Stack.hpp"

bool Stack::pop(string &elem)
{
    if(empty())
        return false;
    elem = _stack.back(); //取出最后一个元素赋值给elem
    _stack.pop_back(); // 将最后一个元素删除
    return true;
}

bool Stack::peek(string &elem) //同pop，但不删除容器内最后的元素
{
    if(empty())
        return false;
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem)
{
    if(full())
        return false;
    _stack.push_back(elem);
    return true;
}
