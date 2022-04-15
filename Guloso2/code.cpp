// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void bridgeAlg(){
    int nPeople;
    list <int> side1;

    //Leitura das pessoas que irão atravesar
    cin >> nPeople;

    int person;
    for(int i=0;i<nPeople;i++){
        cin >> person;
        side1.push_back(person);
    }
    side1.sort();

    list <int> :: iterator pFirst; // Usados para apontar para os primeiro e últimos elementos, respectivamente
    list <int> :: reverse_iterator pLast;
    int first,second,last,penultimate,totalTime=0;
    stringstream strategy;

    if((int) side1.size() == 1){
        strategy << side1.front() << endl;
        totalTime += side1.front();
        side1.pop_front();
    }

    while(!side1.empty()){
        pFirst = side1.begin();
        pLast = side1.rbegin();

        first = *pFirst;    //Pega o primeiro e o segundo da lista
        ++pFirst;
        second = *pFirst;

        last = *pLast;      //Pega o ultimo e o penultimo da lista
        ++pLast;
        penultimate = *pLast;

        if(2*second <= penultimate + first || (int)side1.size() <= 3){
            strategy << first << " " << second << endl;
            side1.pop_front();
            side1.pop_front();
            totalTime += second;

            if(side1.empty()){              // Para o algoritmo na situação em que há somente duas pessoas para atravessar
                break;
            }

            strategy << first << endl;
            totalTime += first;
            if((int)side1.size() == 1){     // Evita a continuação na situação em que só há duas pessoas na segunda parte da leva
                strategy << first << " " << last << endl;
                totalTime += last;
                side1.pop_back();
                break;
            }else{
                strategy << penultimate << " " << last << endl;
                side1.pop_back();
                side1.pop_back();
                strategy << second << endl;
                side1.push_front(second);
                side1.push_front(first);
                totalTime += (last+second);
            }
        }else{
            strategy << first << " " << penultimate << endl;
            strategy << first << endl;
            strategy << first << " " << last << endl;
            strategy << first << endl;
            side1.pop_back();
            side1.pop_back();

            totalTime += (penultimate+2*first+last);
        }
    }
    cout << totalTime << endl << strategy.str();
}

int main(){
    int nTests;

    cin >> nTests;

    for(int i=0;i<nTests;i++){
        bridgeAlg();
        if(i<nTests-1) cout << endl;
    }
    
    return 0;
}