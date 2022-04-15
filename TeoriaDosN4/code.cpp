// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int nTests,gcd,lcm;

    cin >> nTests;

    while(nTests--){
        cin >> gcd >> lcm;

        if(lcm%gcd==0){
            cout <<gcd<<" "<<lcm<<endl;
        }else{
            cout <<-1<<endl;
        }
    }

    return 0;
}