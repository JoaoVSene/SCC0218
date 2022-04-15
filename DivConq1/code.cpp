// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//return the array
long long *readArray(int n){
    long long *array = new long long[n];

    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    return array;
}

long long nSwapsMergeSort(long long *array, int start, int end){

    if(start>=end) return 0;

    int mid = start + (end-start)/2;

    long long nSwaps1 = nSwapsMergeSort(array,start,mid);
    long long nSwaps2 = nSwapsMergeSort(array,mid+1,end);

    long long nSwapsTotal=0;

    int i=start;
    int j=mid+1;
    int k=0;
    long long *arrayAux = new long long[end-start+1];
    long long count=0;

    while(i <= mid && j<=end){
        if(array[i]<array[j]){
            arrayAux[k] = array[i];
            i++;
            nSwapsTotal+=count;
        }else{
            arrayAux[k] = array[j];
            j++;
            count++;
        }
        k++;
    }

    for(;i<=mid;i++,k++){
        arrayAux[k] = array[i];
        nSwapsTotal+=count;
    }
    for(;j<=end;j++,k++){
        arrayAux[k] = array[j];
    }

    for(i=start,k=0;i<=end;i++,k++){
        array[i]=arrayAux[k];
    }
    delete arrayAux;

    return nSwapsTotal + nSwaps1 + nSwaps2;
}

int main(){
    int nIntegers;
    long long *array;

    while(cin >> nIntegers && nIntegers != 0){
        array = readArray(nIntegers);
        cout << nSwapsMergeSort(array,0,nIntegers-1) << endl;
        delete array;
    }

    return 0;
}