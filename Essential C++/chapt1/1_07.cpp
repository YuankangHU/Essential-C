#include<iostream>
#include<fstream>
using namespace std;

int main (void){
    string name;
    int num_tries;
    int num_rights;

    fstream iofile("data.txt", ios_base::in| ios_base::app);
    
    if (!iofile)
    {
        cerr << "Oops, unable to save session data!" << endl;
    }else{
            int i = 0;
            
            while(i<2)
            {
            cout <<"Enter your name: ";
            cin >> name;
            cout << "Enter your num_tries, num_rights: ";
            cin >> num_tries >> num_rights;
            i++;
            iofile << name << ' ' << num_tries << ' ' << num_rights <<endl;
            }                       
            
            iofile.seekg(0); //因为使用app方法，需要将光标重新移动到起始位置
            
            while(iofile >> name >> num_tries >> num_rights)
            {
            cout << "name: " << name << endl;
            cout << "tot: " << num_tries << endl;
            cout << "right: " << num_rights << endl;
            }            

              
    }
    
    return 0;
}