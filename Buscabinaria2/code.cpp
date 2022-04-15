// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//return the array
int *readArray(int n, int *sum){
    int *array = new int[n];

    (*sum) = 0;

    for(int i=0;i<n;i++){
        cin >> array[i];
        (*sum) += array[i];
    }

    return array;
}

bool fillContainers(int *capacityVessel,int nVessels,int nContainers, int capacityContainers){
    int containerSum=0,i=0,j=0;

    while(i<nContainers && j<nVessels){
        while(containerSum<capacityContainers){
            containerSum += capacityVessel[j];

            if(containerSum<=capacityContainers){
                j++;
            }
        }
        containerSum=0;
        i++;
    }
    if(i==nContainers && j<nVessels ) return false;

    return true;
}


int minimalContainerCapacity(int *capacityVessel,int nVessels,int nContainers, int sumCapacityVessels){
    int mid,start=1,end=sumCapacityVessels,minimal;

    mid=(start+end)/2;

    while(start<=end){
        if(fillContainers(capacityVessel,nVessels,nContainers,mid)){
            minimal = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = (start+end)/2;
    }
    return minimal;
    
}

int main(){
    int nVessels,nContainers,*capacityVessel,sumCapacityVessels;

    while(cin >> nVessels){

        cin >> nContainers;

        capacityVessel = readArray(nVessels, &sumCapacityVessels);
        cout << minimalContainerCapacity(capacityVessel,nVessels,nContainers,sumCapacityVessels) << endl;
    }

    return 0;
}