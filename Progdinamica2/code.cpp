// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <algorithm>

using namespace std;

bool determineHowWins(int n, int m, int *nRocks){
    bool *array = new bool[n+1];

    for(int i=0;i<=n;i++) array[i]=false;

    for(int i=0;i<n;i++){
        if(array[i]==false){
            for(int j=0;j<m;j++){
                if(i+nRocks[j]<=n){
                    array[i+nRocks[j]]=true;
                }
            }
        }
    }

    bool aux = array[n];
    delete array;

    return aux;
}

int *readArray(int size){
    int *array = new int[size];

    for(int i=0;i<size;i++) cin >> array[i];

    return array;
}

int main(){
    int n,m,*nRocks;

    while(cin >> n >> m){

        nRocks = readArray(m);

        if(determineHowWins(n,m,nRocks)){
            cout <<"Stan wins";
        }else{
            cout <<"Ollie wins";
        }
        cout << endl;
        delete nRocks;
    }

    return 0;
}