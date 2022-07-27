#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;


int main()
{
    ifstream in_file("input.txt");
    ofstream out_file("output.txt");
    istream_iterator<string> is(in_file); //将is绑定到标准输出，此时is为first
    istream_iterator<string> eof;
    ostream_iterator<string> os(out_file, "\n"); //第二个参数定义输出的格式
    
    vector<string> text; //定义的容器用来储存copy的值
    
    if(!in_file || !out_file)
    {
        cerr << "Unable to use files" << endl;
        return -1;
    }
    copy(is, eof, back_inserter(text));
    sort(text.begin(), text.end()); //利用算法排序

    copy(text.begin(), text.end(), os); //将值输入到文件中
    return 0;

}