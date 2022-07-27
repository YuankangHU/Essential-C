#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int arr[4] = {1, 3, 5, 7};
    vector<string> svec;
    const vector <int> ivec(arr, arr+4);
    svec.push_back("hykkk");
    svec.push_back("zby");
    svec.push_back("love");

    vector<string>::iterator it_first = svec.begin();
    vector<int>::const_iterator ivec_first = ivec.begin();
    
    cout <<"String: "<< *it_first << endl;
    cout<<"( " <<it_first->size() <<" ): " <<*it_first<<endl; //size()返回的是字节数
    while(it_first != svec.end())
    {
        cout << *(it_first) << endl;
        it_first++;
    }

    cout << endl;

    while(ivec_first != ivec.end())
    {
        cout << *(ivec_first) << endl;
        ivec_first++; 
    }
    

    return 0;
}