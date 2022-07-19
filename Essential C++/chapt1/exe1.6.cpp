#include<iostream>
#include<vector>
using namespace std;

int main(void){
    vector<int> ivec;
    int ival = 0;
    int sum = 0;

    while(cin >> ival){
        ivec.push_back(ival);
    }

    for(int i =0; i<ivec.size(); i++){
        sum+=ivec[i];
    }

    cout << "sum = " << sum <<endl;

    return 0;
}