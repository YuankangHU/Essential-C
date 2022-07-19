#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector<int> *fibon_seq(int pos, ostream &os = cout);

int main(){
    int pos;
    ofstream outfile("fibon_seq.txt");

    cout << "Enter a position please: " ;
    
    while(cin >> pos){
        if(fibon_seq(pos, outfile))
        {
        
        }
        else
        {
            cout << "Sorry, element marche pas dans " << pos << endl;
        }   
    cout << "Enter another position please: ";
    }    
    return 0;
}


vector<int> *fibon_seq(int pos, ostream &os) //使用函数指针
{
    static vector<int> elems;  //创建静态容器
    if(pos <= 0 || pos >1024){
        return NULL;
    }

    for (int i = elems.size(); i <pos; i++)
    {
        if(i==0 || i==1)
        {
            elems.push_back(1); //将值传入容器中
            os << 1 << " "; //将值输入到文件中
        }
            
        else
        {
            elems.push_back(elems[i-1]+elems[i-2]);
            os << elems[i-1]+elems[i-2] << " ";
        }
            
    }
    cout << endl;
    return &elems;
}
