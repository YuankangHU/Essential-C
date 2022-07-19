#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
    ifstream infile("string.txt");
    ofstream outfile("string_sort.txt");
    if(!infile || !outfile)
        cerr << "Unable to open file" << endl;
    else
    {
        string words;
        vector<string> text_vec;
        while(infile >> words)
            text_vec.push_back(words);
        int index = 0;
        cout << "Unsorted text: " << endl;
        for(index = 0; index < text_vec.size(); index++)
            cout <<text_vec[index] << endl;
        
        sort(text_vec.begin(), text_vec.end());
        
        cout << "Sorted text: " << endl;
        for(index = 0; index < text_vec.size(); index++){
          outfile <<text_vec[index] << endl;          
          cout << text_vec[index] << endl;
        }
    }
}