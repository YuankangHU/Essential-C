#include<iostream>
using namespace std;

bool fibon_elem(int pos, int &elem); //elem使用&引用

int main(){
    int pos;
    int elem;

    cout  << "Enter a position: ";
    cin >> pos;

    if(fibon_elem(pos, elem)){
        cout << "element dans " << pos << " est: " << elem << endl;
    }
    else{
        cout << "Sorry, element marche pas dans " << pos << endl;
    }
    return 0;
}

bool fibon_elem(int pos, int &elem){
    if(pos <= 0 || pos >1024){
        elem = 0;
        return false;
    }
    elem = 1;
    int n1 = 1;
    int n2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem; 
    }
    return true;
}
