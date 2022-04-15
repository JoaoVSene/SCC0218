// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define NQUEENS 8

int **readTable(){
    int **table = new int*[NQUEENS];

    for(int i=0;i<NQUEENS;i++){
        table[i] = new int[NQUEENS];
        for(int j=0;j<NQUEENS;j++){
            cin >> table[i][j];
        }
    }

    return table;
}

void freeTable(int **table){
    for(int i=0;i<NQUEENS;i++){
        delete table[i];
    }
    delete table;
}

int queen(int **table,bool column[NQUEENS], bool mainD[2*NQUEENS -1], bool secundaryD[2*NQUEENS -1], int nQueens){
    int maxSum=-1,aux;

    if(nQueens >= NQUEENS){
        return 0;
    }

    for(int i=0;i<NQUEENS;i++){
        if(column[i] == false && secundaryD[nQueens+i] == false && mainD[NQUEENS-1 + nQueens - i] == false){
            column[i] = true;
            secundaryD[nQueens+i] = true;
            mainD[NQUEENS-1 + nQueens - i] = true;

            aux = queen(table,column,mainD,secundaryD,nQueens+1);
            if(aux + table[nQueens][i] > maxSum && aux != -1){
                
                maxSum = aux + table[nQueens][i];
                //cout << nQueens << " " << i << " : " << maxSum <<  endl;
            }

            column[i] = false;
            secundaryD[nQueens+i] = false;
            mainD[NQUEENS-1 + nQueens - i] = false;
        }
    }

    return maxSum;
}


int main(){
    int nTables, **table;
    bool column[NQUEENS], mainD[2*NQUEENS -1], secundaryD[2*NQUEENS -1];

    cin >> nTables;

    for(int i=0;i<nTables;i++){
        table = readTable();

        for(int i=0;i<NQUEENS;i++){
            column[i] = false;
        }
        for(int i=0;i<2*NQUEENS -1;i++){
            mainD[i] = false;
            secundaryD[i] = false;
        }

        cout << setw(5) << queen(table,column,mainD,secundaryD,0) << endl;

        freeTable(table);
    }

    return 0;
}