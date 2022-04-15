// João Victor Sene Araújo - nUSP: 11796382 - SCC0218

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct PRODUCT{
    int price;
    int weight;
}product;

int *readArray(int size){
    int *array = new int[size];

    for(int i=0;i<size;i++){
        cin >> array[i];
    }

    return array;
}

product *readArrayProduct(int size){
    product *array = new product[size];

    for(int i=0;i<size;i++){
        cin >> array[i].price >> array[i].weight;
    }

    return array;
}

int maximalValueGoods(int nProducts, product *products, int nPeople, int *people){
    int maxValue=0;

    for(int k=0;k<nPeople;k++){
        int *array = new int[people[k]+1];

        for(int i=0;i<=people[k];i++) array[i]=0;

        for(int i=0;i<nProducts;i++){
            for(int j=people[k];j>=0;j--){
                if(products[i].weight<=j){
                    array[j]=max(array[j],products[i].price + array[j - products[i].weight]);
                }
            }
        }
        maxValue += array[people[k]];
    }
    return maxValue;
}

int main(){
    int nTests,nProducts,nPeople,*people;
    product *products;

    cin >> nTests;

    for(int i=0;i<nTests;i++){

        cin >> nProducts;
        products = readArrayProduct(nProducts);

        cin >> nPeople;
        people = readArray(nPeople);
        
        cout << maximalValueGoods(nProducts,products,nPeople,people) << endl;
        delete products;
        delete people;
    }

    return 0;
}