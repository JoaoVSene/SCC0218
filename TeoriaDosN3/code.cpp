// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkDivisible(int n, bool *stopReading){
    int number=0;
    char bit;

    while(cin >> bit && bit != '#'){
        if(bit=='1'){
            number = (number*2+1)%n;
        }else if(bit=='0'){
            number = (number*2)%n;
        }
    }

    if(cin.eof()){
        (*stopReading) = true;
        return true;
    }

    if(number==0) return true;

    return false;
}

int main(){
    bool stopReading=false;

    while(!cin.eof()){

        if(checkDivisible(131071,&stopReading)){
            if(stopReading) break;

            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }

    return 0;
}