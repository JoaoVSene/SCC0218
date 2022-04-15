// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*  Lê e retorna a fila de preferência de cada homem 'x', de modo que:
    queueMen[x-1]->firstWoman->secondWoman->thirdWoman...
*/
queue <int> *readMenQueue(int size){
    queue <int> *queueMen;

    queueMen = new queue <int> [size];

    for(int i=0;i<size;i++){
        int man;

        cin >> man;

        for(int j=0;j<size;j++){
            int woman;

            cin >> woman;

            queueMen[man-1].push(woman);
        }
    }

    return queueMen;
}


/*  Guarda na matriz[mulher-1][homem-1] a colocação do homem para a mulher
*/
int **readWomenMatrix(int size){
    int **matrix = new int*[size];

    for(int i=0;i<size;i++){
        matrix[i] = new int[size];

        cin >> matrix[i][0]; // descarta o primeiro dígito

        for(int j=1;j <= size;j++){
            int aux;
            cin >> aux;

            matrix[i][aux-1] = j;
        }
    }

    return matrix;
}

void freeMatrix(int **matrix,int size){
    for(int i=0;i<size;i++){
        delete matrix[i];
    }
    delete matrix;
}

void freeQueue(queue <int> *q, int size){

    for(int i=0;i<size;i++){
        queue<int>().swap(q[i]);
    }
    delete[] q;
}

/*  Realiza o casamento entre os 'n' homens e mulheres, retornando o vetor
    menMarriage, na qual:
    menMarriage[x-1] = y, onde o homem x é casado com a mulher y 
*/
int *stableMatch(queue <int> *queueMen,int **womenMatrix,int nMarriages){
    int *womenMarriage = new int[nMarriages], *menMarriage = new int[nMarriages];

    queue<int> singleMen;

    for(int i=0;i<nMarriages;i++){ // Marca todos as pessoas como não casadas e inicializa a fila
        womenMarriage[i] = 0;
        menMarriage[i] = 0;
        singleMen.push(i+1);
    }

    while(!singleMen.empty()){

        int man = singleMen.front();

        int woman = queueMen[man-1].front();
        queueMen[man-1].pop();

        if(womenMarriage[woman-1] == 0){
            womenMarriage[woman-1] = man;
            menMarriage[man-1] = woman;

            singleMen.pop();
        }else if(womenMatrix[woman-1][man-1] < womenMatrix[woman-1][womenMarriage[woman-1]-1]){
            menMarriage[womenMarriage[woman-1]-1] = 0;
            singleMen.push(womenMarriage[woman-1]-1);
            
            womenMarriage[woman-1] = man;
            menMarriage[man-1] = woman;
            singleMen.pop();
        }
    }

    delete womenMarriage;

    return menMarriage;
}

void printMarriages(int *menMarriages,int nMarriages){
    for(int i=0;i<nMarriages;i++){
        cout << i+1 << " " << menMarriages[i] << endl;
    }
}

int main(){
    int nTests, **womenMatrix, nMarriages, *menMarriages;
    queue <int> *queueMen;

    cin >> nTests;
    
    for(int i=0;i<nTests;i++){
        cin >> nMarriages;

        womenMatrix = readWomenMatrix(nMarriages);
        queueMen = readMenQueue(nMarriages);

        menMarriages = stableMatch(queueMen,womenMatrix,nMarriages);
        printMarriages(menMarriages,nMarriages);

        freeQueue(queueMen,nMarriages);
        freeMatrix(womenMatrix,nMarriages);
        delete menMarriages;
    }

    return 0;
}