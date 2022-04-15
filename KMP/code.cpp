// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool kmp(char *text, char *pattern){
    int aux=0, sizePattern = strlen(pattern), sizeText = strlen(text);
    
    int lps[sizePattern];

    lps[0]=0;
    int k = 1;
    while(k<sizePattern){
        if(pattern[k] != pattern[aux]){
            if(aux==0){
                lps[k]=0;
                k++;
            }else{
                aux = lps[aux-1];
            }
        }else{
            aux++;
            lps[k]=aux;
            k++;
        }
    }

    int i = 0;
    int j = 0;
    while(i<sizeText){
        if(text[i]==pattern[j]){
            i++; j++;
        }
        if(j==sizePattern){
            return true;

        }else if(i<sizeText && pattern[j] != text[i]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i = i + 1;
            }
        }
    }

    return false;
}

int main(){
    int nTests,nPatterns;
    char text[100001], pattern[1001];

    cin >> nTests;
    getchar();
    getchar();

    while(nTests--){
        cin.getline(text,100001,'\r');
        getchar();
        cin >> nPatterns;
        getchar();
        getchar();

        while(nPatterns--){
            cin.getline(pattern,1001,'\r');
            getchar();
            if(kmp(text,pattern)){
                cout << "y";
            }else{
                cout << "n";
            }
            cout << endl;
        }
    }
}
