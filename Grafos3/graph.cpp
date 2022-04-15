// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int **readGraph(int *nVertices,int *source,int *sink){
    int **matrix, nEdges,x,y, weight;

    cin >> (*nVertices);
    if((*nVertices)==0) return nullptr;

    matrix = new int*[(*nVertices)];
    for(int i=0;i<(*nVertices);i++){
        matrix[i]=new int[(*nVertices)];
        for(int j=0;j<(*nVertices);j++){
            matrix[i][j]=0;
        }
    }

    cin >> (*source) >> (*sink) >> nEdges;

    (*source) = (*source)-1;
    (*sink) = (*sink)-1;

    while(nEdges--){
        cin >> x >> y >> weight;
        matrix[x-1][y-1] += weight;
        matrix[y-1][x-1] += weight;
    }

    return matrix;
}


//Return true if exist path between two nodes 
bool bfs(int **matrix,int size, int source, int sink, int *trail){
    queue<int> vertices;
    bool *visited = new bool[size];

    for(int i=0;i<size;i++) visited[i]=false;

    vertices.push(source);
    visited[source]=true;

    while(!vertices.empty()){
        int vertice = vertices.front();
        vertices.pop();

        for(int i=0;i<size;i++){
            if(matrix[vertice][i]!=0 && !visited[i]){
                vertices.push(i);
                trail[i]=vertice;
                visited[i]=true;
            }
        }
    }

    return visited[sink];
}

int maxFlow(int **matrix, int size, int source, int sink){
    int maxF=0, *trail = new int[size], x, y, limit;

    while(bfs(matrix,size,source,sink,trail)){
        limit = INT32_MAX;

        y = sink;
        while(y != source){
            x = trail[y];
            limit = min(limit,matrix[x][y]);
            y = x;
        }

        y = sink;
        while(y != source){
            x = trail[y];
            matrix[x][y] -= limit;
            matrix[y][x] += limit;
            y = x;
        }
        maxF += limit;
    }

    return maxF;
}

int main(){
    int nVertices=1,source,sink,**matrix;

    for(int i=1;nVertices;i++){
        matrix = readGraph(&nVertices,&source,&sink);
        if(!nVertices) break;

        cout << "Network " << i << endl;
        cout << "The bandwidth is "<< maxFlow(matrix,nVertices,source,sink) << "."<<endl<<endl;
    }

    return 0;
}