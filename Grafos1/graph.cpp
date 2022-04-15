// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int number;
    int incomingEdges;
};

struct nodeAdjacency{
    int number;
    vector<int> edges;
};

struct nodeVisited{
    int number;
    bool visited;
};

void freeList(vector<nodeAdjacency> *adjacencyList){
    for(auto i=(*adjacencyList).begin();i!=(*adjacencyList).end();i++){
        (*i).edges.clear();
    }
    (*adjacencyList).clear();
}

vector<node> readEdges(bool *endRead, int *nEdges, vector<nodeAdjacency> *adjacencyList){
    vector<node> nodeList;
    int node1,node2;
    (*nEdges)=0;

    do{
        cin >> node1 >> node2;

        if(node1<0 && node2<0){
            (*endRead) = true;
            break;
        }
        if(node1==0 && node2==0){
            break;
        }
        (*nEdges)++;
        
        auto aux1 = nodeList.begin();

        while(aux1 != nodeList.end()){
            if((*aux1).number == node1) break;
            aux1++;
        }
        if(aux1 == nodeList.end()){
            node aux2;
            aux2.number = node1;
            aux2.incomingEdges = 0;
            nodeList.push_back(aux2);

            nodeAdjacency aux3;
            aux3.number=node1;
            aux3.edges.push_back(node2);
            (*adjacencyList).push_back(aux3);
        }else{
            auto aux3 = (*adjacencyList).begin();
            while(aux3 != (*adjacencyList).end()){
                if((*aux3).number == node1)break;
                aux3++;
            }
            if(aux3 != (*adjacencyList).end()){
                (*aux3).edges.push_back(node2);
            }else{
                nodeAdjacency aux3;
                aux3.number=node1;
                aux3.edges.push_back(node2);
                (*adjacencyList).push_back(aux3);
            }
        }

        aux1 = nodeList.begin();

        while(aux1 != nodeList.end()){
            if((*aux1).number == node2) break;
            aux1++;
        }

        if(aux1 != nodeList.end()){
            (*aux1).incomingEdges++;
        }else{
            node aux2;
            aux2.number = node2;
            aux2.incomingEdges = 1;

            nodeList.push_back(aux2);
        }
    }while(true);

    return nodeList;
}

void dfs(int vertex, vector<nodeVisited> *visited, vector <nodeAdjacency> adjacencyList){

    auto aux1 = (*visited).begin();

    while(aux1 != (*visited).end()){
        if((*aux1).number == vertex) break;
        aux1++;
    }
    if((*aux1).visited==true) return;
    (*aux1).visited=true;

    auto aux2 = adjacencyList.begin();

    while(aux2 != adjacencyList.end()){
        if((*aux2).number == vertex) break;
        aux2++;
    }
    if(aux2 != adjacencyList.end()){
        for(auto i = (*aux2).edges.begin();i != (*aux2).edges.end(); i++){
            
            dfs((*i),visited,adjacencyList);
        }
    }
    
}

bool ifIsTree(vector<node> nodeList, int nEdges, vector<nodeAdjacency> adjacencyList){
    int nRoots=0,root;
    vector<nodeVisited> visited;

    if((int)nodeList.size() == 0) return true;
    else if(nEdges != (int)nodeList.size() - 1) return false;

    for(auto i=nodeList.begin();i!=nodeList.end();i++){
        nodeVisited aux;
        aux.number=(*i).number;
        aux.visited=false;
        visited.push_back(aux);

        if((*i).incomingEdges==0){
            nRoots++;
            root = (*i).number;
        }else if((*i).incomingEdges>1){
            return false;
        }
    }
    if(nRoots!=1) return false;

    dfs(root,&visited,adjacencyList);

    for(auto i=visited.begin();i!=visited.end();i++){
        if((*i).visited==false) return false;
    }

    return true;
}
int main(){

    bool endRead;
    int nEdges,nCases=1;
    vector<node> nodeList;
    vector<nodeAdjacency> adjacencyList;

    while(!endRead){
        endRead=false;
        nodeList = readEdges(&endRead,&nEdges,&adjacencyList);
        if(endRead) break;
        //printList(nodeList);
        if(ifIsTree(nodeList,nEdges,adjacencyList)){
            cout << "Case " <<nCases<< " is a tree."<<endl;
        }else{
            cout << "Case " <<nCases<< " is not a tree."<<endl;
        }
        freeList(&adjacencyList);
        nCases++;
    }

    return 0;
}