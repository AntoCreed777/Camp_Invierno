#include <bits/stdc++.h>

using namespace std;

vector<int> mergeA(vector<int>& izquierda,vector<int>& derecha){
    vector<int> resultado;
    size_t intI=0,intD=0;
    
    while(intI < izquierda.size() && intD < derecha.size()){
        if(izquierda[intI]<derecha[intD]){
            resultado.push_back(izquierda[intI]);
            intI++;
        }
        else{
            resultado.push_back(derecha[intD]);
            intD++;
        }
    }

    while(intI < izquierda.size()){
        resultado.push_back(izquierda[intI]);
        intI++;
    }

    while(intD < derecha.size()){
        resultado.push_back(derecha[intD]);
        intD++;
    }

    return resultado;
}

vector<int> merge_sort(vector<int> vec){
    if(vec.size() <= 1){return vec;}

    size_t mitad = vec.size() / 2;
    vector<int> izquierda(vec.begin(), vec.begin() + mitad);
    vector<int> derecha(vec.begin() + mitad, vec.end());

    izquierda = merge_sort(izquierda);
    derecha = merge_sort(derecha);

    return mergeA(izquierda,derecha);
}

int main(){
    vector<int> vector1 = {8,2,4,9,1,7,-4,3,0,9,1,3,7};

    vector1 = merge_sort(vector1); 

    for (size_t i = 0; i < vector1.size(); i++) {
        cout << vector1[i] << " ";
    }
    cout << endl;

    return 0;
}