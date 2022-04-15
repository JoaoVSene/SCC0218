// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <algorithm>

using namespace std;

int *readArray(int size){
    int *array = new int[size];

    for(int i=0;i<size;i++){
        cin >> array[i];
    }

    return array;
}

int LongestIncreasingSubsequence(int n, int *array){
    int *aux = new int[n],maxNSequence=0;

    for(int i=0;i<n;i++) aux[i]=0;

    aux[0]=1;

    for(int i=1;i<n;i++){
        int maxI=1;
        for(int j=0;j<i;j++){
            if(array[j]<array[i]) maxI = max(aux[j]+1,maxI);
        }
        aux[i] = maxI;
        maxNSequence = max(maxNSequence,maxI);
    }

    delete aux;

    return maxNSequence;
}

int main(){
    int n,*array;

    cin >> n;
    array = readArray(n);

    cout << n - LongestIncreasingSubsequence(n,array) << endl;
    delete array;

    return 0;
}