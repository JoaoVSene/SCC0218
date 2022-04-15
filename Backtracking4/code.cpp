// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct NODE{
    int config[4];
    int dist;
    int weight;
} node;

bool operator<(const node& n1, const node& n2){
    return n1.weight > n2.weight;
}

//return the matrix
bool ****readConfiguration(int **initial, int **target){
    int nForbidden, aux[4];
    bool ****matrix;

    (*initial) = new int[4];
    for(int i=0;i<4;i++) cin >> (*initial)[i];

    (*target) = new int[4];
    for(int i=0;i<4;i++) cin >> (*target)[i];

    matrix = new bool***[10];
    for(int i=0;i<10;i++){
        matrix[i] = new bool**[10];
        for(int j=0;j<10;j++){
            matrix[i][j] = new bool*[10];
            for(int k=0;k<10;k++){
                matrix[i][j][k] = new bool[10];
                for(int m=0;m<10;m++){
                    matrix[i][j][k][m] = false;
                }
            }   
        }
    }

    cin >> nForbidden;

    for(int i=0;i<nForbidden;i++){
        for(int j=0;j<4;j++) cin >> aux[j];

        matrix[aux[0]][aux[1]][aux[2]][aux[3]] = true;
    }

    return matrix;
}

bool ifEqual(int *first, int *second){
    return (first[0]==second[0] && first[1]==second[1] && first[2]==second[2] && first[3]==second[3]);
}

int calculateWeight(node aux, int *target){

    return (min((aux.config[0]-target[0]+10)%10,(target[0]-aux.config[0]+10)%10)+
            min((aux.config[1]-target[1]+10)%10,(target[1]-aux.config[1]+10)%10)+
            min((aux.config[2]-target[2]+10)%10,(target[2]-aux.config[2]+10)%10)+
            min((aux.config[3]-target[3]+10)%10,(target[3]-aux.config[3]+10)%10));
}

//way = (direction of the rotation) false(left), true(right)
node rotateWheel(int index, node aux, bool way, int *target){
    if(way){
        aux.config[index] = (aux.config[index]+11)%10;
    }else{
        aux.config[index] = (aux.config[index]+9)%10;
    }
    aux.dist++;
    aux.weight = calculateWeight(aux,target);
    return aux;
}

int foundPath(int *initial, int *target,bool ****matrix){

    priority_queue <node> configQueue;
    node aux1;

    memcpy(aux1.config,initial,4*sizeof(int));
    aux1.dist = 0;
    aux1.weight = 0;

    configQueue.push(aux1);

    while(!configQueue.empty()){
        aux1 = configQueue.top();
        configQueue.pop();

        if(ifEqual(aux1.config,target)){
            return aux1.dist;
            
        }else if(!matrix[aux1.config[0]][aux1.config[1]][aux1.config[2]][aux1.config[3]]){
            matrix[aux1.config[0]][aux1.config[1]][aux1.config[2]][aux1.config[3]] = true;

            node aux2 = aux1;
            for(int i=0;i<4;i++){
                aux1 = rotateWheel(i,aux2,true,target);
                configQueue.push(aux1);
                aux1 = rotateWheel(i,aux2,false,target);
                configQueue.push(aux1);
            }
        }
    }
    return -1;
}

int main(){
    int nTests;

    cin >> nTests;

    for(int i=0;i<nTests;i++){
        int *initial, *target;
        bool ****matrix;

        matrix = readConfiguration(&initial,&target);

        cout << foundPath(initial,target,matrix) << endl;
    }

    return 0;
}