// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool nPrimes(int div, int fac, int n){
    int j=0;
    int k=div;

    for(int i=2;k<=fac;i++){
        j += fac/k;
        if(j>=n){
            return true;
        }
        k = pow(div,i);
    }
    return false;
}

bool primeFactors(int n, int m){
    int i;

    if((m==0 || m==1)&&(n==0 || n==1)) {
        return true;
    }

    if(m<=n){
        return true;
    }

    i=0;
    while(!(m%2)){
        m=m/2;
        i++;
    }

    if(!nPrimes(2,n,i)){
        return false;
    }

    i=0;
    for(int j=3; j <= sqrt(m); j+=2){
        while(!(m%j)){
            m=m/j;
            i++;
        }
        if(!nPrimes(j,n,i)){
            return false;
        }
        i=0;
    }
    if(m!=1 && m>n) return false;

    return true;
}

int main(){
    long long n,m;

    while(cin >> n){
        cin >> m;

        if(primeFactors(n, m)){
            cout <<m<<" divides "<<n<<"!"<<endl;
        }else{
            cout <<m<<" does not divide "<<n<<"!"<<endl;
        }
    }

    return 0;
}