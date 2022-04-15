// INTEGER VECTOR EXAMPLE
// CPP program to illustrate
// Implementation of begin() function
#include <iostream>
#include <vector>
using namespace std;


int func(vector<int> myvector){
    auto i = myvector.begin();
    i++;

    (*i) = 1;    
}

int main()
{
    // declaration of vector container
    vector<int> myvector{ 1, 2, 3, 4, 5 };
 
    // using begin() to print vector
    for (auto it = myvector.begin();
         it != myvector.end(); ++it)
        cout << ' ' << *it;

    for (auto it = myvector.begin();
         it != myvector.end(); ++it)
        (*it) = 1;

    for (auto it = myvector.begin();
         it != myvector.end(); ++it)
        cout << ' ' << *it;

    return 0;
}