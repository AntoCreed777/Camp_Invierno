#include <iostream>
#include <bits/stdc++.h>   //Se incluyen todas las librerias estandar

using namespace std;    //Se define el uso de librerias estandar en todo el trabajo
typedef long long ll;   //Defino un "apodo" a long long

int main(){

    string mi_string = "hola";
    char mi_letra = 'a';

    int arr1[10];
    vector <int> arr2(10);      //matriz
    vector <vector<int>> arr3;    //Matriz

    vector <int> arr4(10,0);    //Array de tamaño 10 inicializando con 0
    
    cout << "Hello Wolrd" << endl;  //output

    int n;
    cin >> n;       //input

    arr4.size();
    sort(arr4.begin(), arr4.end);
    arr4.assign(50,3);  //Redimenciona con nuevos valores iniciales
    arr4.pushback(61);  //Agregar un elemento
    arr4.pop_back();    //Elimina el primer elemento
    arr4.erase(5)   //Elimina el elemento   O(log n)

    return 0;
}