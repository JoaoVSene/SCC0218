// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <stdio.h>
#include <stdlib.h>

//return the array
long long *readArray(int n){
    long long *array = malloc(sizeof(long long)*n);

    for(int i=0;i<n;i++){
        scanf("%lld",&array[i]);
    }

    return array;
}

int nSwapsSort(long long *array, int n){
    int nSwaps=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(array[j]>array[j+1]){
                int aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                nSwaps++;
            }
        }
    }

    return nSwaps;
}

int main(){
    int nIntegers;
    long long *array;

    scanf("%d",&nIntegers);
    while(nIntegers!=0){
        array = readArray(nIntegers);
        printf("%d\n",nSwapsSort(array,nIntegers));
        free(array);

        scanf("%d",&nIntegers);
    }

    return 0;
}