// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//return the array
int *readArray(int n){
    int *array = new int[n];

    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    return array;
}

int minValueIndex(int *array, int start, int end){
    int min = INT_MAX, minIndex;

    for(int i=start;i<=end;i++){
        if(array[i]<min){
            min = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int maxS(int *array, int start, int end){

    if(start>end) return 0;
    if(start==end) return array[start];

    int minIndex = minValueIndex(array,start,end);

    int maxS1 = maxS(array,start,minIndex-1);
    int maxS2 = maxS(array,minIndex+1,end);

    int maxS = (end-start+1) * array[minIndex];

    return max(max(maxS1,maxS2),maxS);
}

int main(){
    int nIntegers;
    int *array;

    cin >> nIntegers;

    array = readArray(nIntegers);
    cout << maxS(array,0,nIntegers-1) << endl;
    delete array;

    return 0;
}