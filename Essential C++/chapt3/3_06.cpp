#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string bad_words[] = { "cat", "apple", "banana", "dog"}; //set起到过滤的作用
    map<string, int> words;
    map<string, int>::iterator it;
    set<string> word_exclusion(bad_words, bad_words+4);
    set<string>::iterator it_set;
    ofstream out_file("data.txt");
    string tword;

    // 测试set集合
    for( it_set = word_exclusion.begin(); it_set != word_exclusion.end(); it_set++)
        cout << *it_set << endl;

    while (cin >> tword)
    {
        if(word_exclusion.count(tword))//count返回set内的元素个数，若存在，则为1，if为真
            continue;//跳出循环
        words[tword]++;//将tword放到map内，默认值为0，递增后为1，之后若出现，依次递增。
        cout <<words[tword];
    }
 
    if(!out_file)
        cerr << "Unable to use data.txt" << endl;
    else
    {
        for( it = words.begin(); it != words.end(); it++)
            out_file << it->first << "[" << it->second << "]" << endl;
    }
    return 0;
}