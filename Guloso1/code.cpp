// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*  Struct da fila de prioridade
    Guarda um job
*/
struct job{
    int time;
    int weight;

    job(int time, int weight)
        : time(time),weight(weight)
    {
    }
};

struct compareWeight{   // Ordem Descrescente
    bool operator()(job const& a1, job const& a2){
        if(a1.weight * a2.time != a2.weight * a1.time){
            return a1.weight * a2.time < a2.weight * a1.time;
        }else{
            return a1.weight < a2.weight;
        }
    }
};

void minimunSchedule(){
    int nJobs,jobWeight,jobTime,sumOfTimes=0,minSchedule=0;
    priority_queue<job, vector<job>, compareWeight> pQueue;

    cin >> nJobs;

    for(int i=0;i<nJobs;i++){
        cin >> jobTime >> jobWeight;

        pQueue.push(job(jobTime,jobWeight));
    }

    while(!pQueue.empty()){
        job aux = pQueue.top();

        sumOfTimes += aux.time;
        minSchedule += aux.weight * sumOfTimes;
        pQueue.pop();
    }

    cout << minSchedule << endl;
}

int main(){
    int nTests;

    cin >> nTests;

    for(int i=0;i<nTests;i++){
        minimunSchedule();
    }
    
    return 0;
}