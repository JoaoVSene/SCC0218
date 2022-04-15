// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <algorithm>

using namespace std;

int calculateBurgers(int m, int n, int t, int *timeBeer){
    int minB = min(m,n),maxB = max(m,n),nBurgers=0,aux=t,minBeer=(t%minB),minNBurgers=0;

    while((t%minB)!=0 && t>=maxB){
        t -=maxB;
        nBurgers++;
        if((t%minB)<minBeer){
            minBeer = t%minB;
            minNBurgers = nBurgers;
        }
    }

    (*timeBeer)=minBeer;
    return minNBurgers + (aux-minNBurgers*maxB)/minB;
}

int main(){
    int m,n,t,timeBeer;

    while(cin >> m){

        cin >> n >> t;
        cout << calculateBurgers(m,n,t,&timeBeer);
        if(timeBeer!=0){
            cout <<" "<<timeBeer;
        }
        cout << endl;
    }

    return 0;
}