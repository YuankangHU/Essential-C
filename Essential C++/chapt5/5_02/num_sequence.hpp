#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence(){};

    virtual int elem(int pos) const = 0; //完成动态编译，不改变成员数据，在子类中才有确切行为
    virtual const char * what_am_i() const = 0;
    virtual ostream& print( ostream &os = cout) const = 0;
    
    static int max_elems(){return _max_elems;}

protected:
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

    const static int _max_elems = 1024;
};

bool num_sequence::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > _max_elems)
    {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    if(pos > size)
        gen_elems(pos); //在调用时会选择派生类，使得此check此函数需要虚函数机制
    return true;
}

ostream &operator<<(ostream &os, const num_sequence &ns)
{
    return ns.print(os); //运算符重载，将os作为cout使用
}