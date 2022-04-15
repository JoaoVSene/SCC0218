// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long minimalQ(long long n){
    int p=9,j=0;
    long long q = 0;

    if(n==1 || n==0) return n;

    while(n!=1 && p>1){
        if(n%p!=0) {
            p--;
        }
        else {
            q += pow(10,j)*p;
            j++;
            n = n/p;
        }
    }

    if(p==1 || n!=1) return -1;

    return q;
}

int main(){
    int nNumbers;
    long long number;

    cin >> nNumbers;

    while(nNumbers--){
        cin >> number;
        cout << minimalQ(number) << endl;
    }

    return 0;
}