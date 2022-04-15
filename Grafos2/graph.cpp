// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
    Struct da lista de adjacencia
    Guarda o vertice que está no final do arco em 'vertex' e o peso em 'weight'
*/
struct node{
    int vertex;
    int weight;
};

/*
    Struct da fila de prioridade
    Guarda o arco de um grafo, sendo vertex1 -> vertex 2, com peso weight
*/
struct arc{
    int vertex1;
    int vertex2;
    int weight;

    arc(int vertex1, int vertex2, int weight)
        : vertex1(vertex1),vertex2(vertex2),weight(weight)
    {
    }
};

struct compareWeight{
    bool operator()(arc const& a1, arc const& a2){
        return a1.weight > a2.weight;
    }
};

int binSearch(string *names, string key, int size){
    int start=0, end=size-1,mid;

    while(start<=end){
        mid = (start+end)/2;
        if(names[mid]==key){
            return mid;
        }
        
        if(names[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}

vector <node> *readGraph(int *nVertices,bool *stopTest,int *startNode){
    vector <node> *adjacencyList;
    string *names,startNodeName;
    int nEdges;
    
    cin >> (*nVertices) >> nEdges;

    if((*nVertices)==0){
        (*stopTest) = true;
        return nullptr;
    }

    adjacencyList = new vector <node> [(*nVertices)];
    names = new string[(*nVertices)];

    for(int i=0;i<(*nVertices);i++){
        cin >> names[i];
    }
    sort(names,names+(*nVertices));

    while(nEdges--){
        string nodeName1,nodeName2;
        int node1,node2,weight;
        node newArc;

        cin >> nodeName1 >> nodeName2 >> weight;

        node1 = binSearch(names,nodeName1,(*nVertices)) + 1;
        node2 = binSearch(names,nodeName2,(*nVertices)) + 1;

        newArc.vertex = node2;
        newArc.weight = weight;
        adjacencyList[node1-1].push_back(newArc);

        newArc.vertex = node1;
        adjacencyList[node2-1].push_back(newArc);
    }

    cin >> startNodeName;
    (*startNode) = binSearch(names,startNodeName,(*nVertices))+1;

    return adjacencyList;
}

void freeList(vector <node> *adjacencyList, int nVertices){
    for(int i=0;i<nVertices;i++){
        vector<node>().swap(adjacencyList[i]);
    }
    delete[] adjacencyList;
}

int prim(int x, int nVertices, bool *mark, vector <node> *adjacencyList){
    int sumWeight=0;
    priority_queue<arc, vector<arc>, compareWeight> pQueue;

    for(int i=0;i<nVertices;i++){
        int sizeList = (int) adjacencyList[x-1].size();

        mark[x-1]=true; // Marca o vertice como visitado

        for(int i=0;i<sizeList;i++){
            node y = adjacencyList[x-1][i];

            pQueue.push(arc(x,y.vertex,y.weight));
        }

        while(!pQueue.empty()){
            arc aux = pQueue.top();

            if(mark[aux.vertex2-1] == false){
                sumWeight += aux.weight;
                x = aux.vertex2;
                pQueue.pop();
                break;
            }
            pQueue.pop();
        }
    }

    for(int i=0;i<nVertices;i++){
        if(mark[i]==false) return -1;
    }

    return sumWeight;
}

int main(){
    bool stopTest = false;
    int nVertices,sumWeight,startNode;
    vector <node> *adjacencyList;
    bool *mark;

    while(!stopTest){
        adjacencyList = readGraph(&nVertices,&stopTest,&startNode);
        if(stopTest) break;

        mark = new bool[nVertices];
        for(int i=0;i<nVertices;i++){
            mark[i]=false;
        }

        sumWeight = prim(startNode,nVertices,mark,adjacencyList);

        if(sumWeight==-1){
            cout << "Impossible"<<endl;
        }else{
            cout << sumWeight << endl;
        }

        freeList(adjacencyList,nVertices);
    }

    return 0;
}