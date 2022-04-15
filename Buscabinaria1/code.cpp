// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//return the array
int *readArray(int n, int *max){
    int *array = new int[n], aux1, aux2;

    (*max) = 0;

    aux1=0;
    for(int i=0;i<n;i++){
        cin >> aux2;
        array[i] = aux2-aux1;
        if(array[i]>(*max)){
            (*max) = array[i];
        }
        aux1=aux2;
    }

    return array;
}

int minimalStrength(int *distance,int n,int max){
    int aux=max;

    for(int i=0;i<n;i++){
        if(distance[i]==aux){
            aux--;
        }else if(distance[i]>aux){
            return max+1;
        }
    }
    return max;
}

int main(){
    int nTests, *distance, max, n;

    cin >> nTests;

    for(int i=0;i<nTests;i++){
        cin >> n;
        distance = readArray(n,&max);
        cout << "Case " << i+1 << ": " << minimalStrength(distance,n,max) << endl;

    }

    return 0;
}