// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <algorithm>

using namespace std;

int *readArray(int size, int *sum){
    int *array = new int[size];

    (*sum)=0;

    for(int i=0;i<size;i++){
        cin >> array[i];
        (*sum)+=array[i];
    }

    return array;
}

int minimumDifferenceGold(int nCoins, int *coins, int half){
    int *array = new int[half+1];

    for(int i=0;i<=half;i++) array[i]=0;

    for(int i=0;i<nCoins;i++){
        for(int j=half;j>=0;j--){
            if(coins[i]<=j){
                array[j]=max(array[j],coins[i]+array[j-coins[i]]);
            }
        }
    }

    return array[half];
}

int main(){
    int nTests,nCoins,*coins,sum;

    cin >> nTests;

    for(int i=0;i<nTests;i++){

        cin >> nCoins;
        coins = readArray(nCoins,&sum);
        sort(coins,coins+nCoins);
        
        cout << sum - 2*minimumDifferenceGold(nCoins,coins,sum/2) << endl;
        delete coins;
    }

    return 0;
}