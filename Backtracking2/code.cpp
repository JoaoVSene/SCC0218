// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void readDictionaryRules(int nDictionary, string **dictionary, int *nRules, string **rules){

    (*dictionary) = new string[nDictionary];
    for(int i=0; i < nDictionary;i++){

        cin >> (*dictionary)[i];
    }

    cin >> (*nRules);

    (*rules) = new string[(*nRules)];
    for(int i=0; i < (*nRules);i++){
        cin >> (*rules)[i];
    }
}

void generatePasswords(string password,string rule, int nDictionary,string *dictionary, int counter){

    if(counter >= (int)rule.size()){
        cout << password << endl;
        return;
    }

    string aux;

    if(rule.at(counter)=='0'){
        for(int i=0;i<10;i++){
            aux = password;
            aux.append(to_string(i));
            generatePasswords(aux,rule,nDictionary,dictionary,counter+1);
        }
    }else{
        for(int i=0;i<nDictionary;i++){
            aux = password;
            aux.append(dictionary[i]);
            generatePasswords(aux,rule,nDictionary,dictionary,counter+1);
        }
    }
}

void printDic(int nDictionary, string *dictionary){
    cout << nDictionary << endl;
    for(int i=0;i<nDictionary;i++){
        cout << dictionary[i] << endl;
    }
    cout << endl;
}

int main(){
    int i=0,nDictionary;

    while(cin >> nDictionary){
        string *dictionary,*rules,password;
        int nRules;

        readDictionaryRules(nDictionary,&dictionary,&nRules,&rules);

        cout << "--"<< endl;
        for(int j=0;j<nRules;j++){
            generatePasswords(password,rules[j],nDictionary,dictionary,0);
        }

        i++;
    }

    return 0;
}