// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_CHARACTERS 1001

int findMaxSubsequence(char *array1, char *array2, int size1, int size2){
    int **dp = new int*[size1+1];

    for(int i=0;i<=size1;i++){
        dp[i] = new int[size2+1];
        dp[i][0]=0;
    }
    for(int i=0;i<=size2;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=size1;i++){
        for(int j=1;j<=size2;j++){
            if(array1[i-1] == array2[j-1]){
                dp[i][j] = max({ dp[i-1][j-1]+1 , dp[i][j-1] , dp[i-1][j] });
            }else{
                dp[i][j] = max({ dp[i-1][j-1] , dp[i][j-1] , dp[i-1][j]});
            }
        }
    }
    int result = dp[size1][size2];

    for(int i=0;i<=size1;i++){
        delete dp[i];
    }
    delete dp;

    return result;
}

int main(){
    char array1[MAX_CHARACTERS],array2[MAX_CHARACTERS];

    while(cin.getline(array1,MAX_CHARACTERS,'\n')){
        cin.getline(array2,MAX_CHARACTERS,'\n');

        cout << findMaxSubsequence(array1,array2,strlen(array1),strlen(array2)) <<endl;
    }

    return 0;
}