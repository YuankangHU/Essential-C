#include "LibMat.hpp"

void print(const LibMat &mat)
{
    cout << "In global print(): about to print mat.print()" << endl;
    mat.print();
}

int main()
{
    // cout << "\nCreating a LibMat object to print()\n";
    // LibMat libmat;
    // print(libmat);
    
    // cout << "\nCreating a Book object to print()\n";
    // Book b("The Castle", "Franz Kafka");
    // print(b);

    cout << "\nCreating a AudioBook object to print()\n";
    AudioBook ab("Man Without Qualities", "Robert Musil", "Keneth Mayer");
    print(ab);
    //cout<< ab.title() <<endl;
    
    return 0;
}