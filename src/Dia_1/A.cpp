#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, mask = 1, contador=0;
    cin >> n >> k;

    //Valida que k no sea mayor que la cantidad maxima de sumandos para obtener n (que es sumar puros 1)
    if(k > n){cout << "NO" << "\n";return 0;}

    vector <ll> sumandos;

    //Obtiene las posiciones que representan a las potencias que suman n
    while(n != 0){
        if(mask & n){sumandos.push_back(1);contador++;}
        else {sumandos.push_back(0);}
        n >>= 1;
    }

    //Valida que k no sea menor a la cantidad minima de sumandos para obtener n
    if(k < contador){cout << "NO" << "\n";return 0;}

    while (k > contador) {
        ll mayor = sumandos[sumandos.size()-1]; //Obtengo el elemento mayor
        if(mayor == 0){
            sumandos.pop_back();
            continue;
        }
        sumandos[sumandos.size()-2]+=2; //Agrego los sumandos
        sumandos[sumandos.size()-1]--;

        contador++;
    }

    cout << "YES" << "\n";

    for(size_t i=0;i<sumandos.size();i++){  //Recorro las potencias
        for(ll j=0;j<sumandos[i];j++){  //Recorro la cantidad de elementos en esa potencia
            cout << pow(2,i) << "\n";
        }
    }

    return 0;
}