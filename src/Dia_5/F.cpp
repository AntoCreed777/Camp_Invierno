#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

bool buscar(vector <ll> &numeros){
    if(numeros.size() < 2) return false;
    for(ll j=(ll)numeros.size()-2;j>=0;j--){
        if(numeros[j] == (ll)j+1){
            numeros.erase(numeros.begin()+j);
            numeros.erase(numeros.begin()+j);
            return true;
        }
    }
    return false;
}
    
int main() {
    ll t,n;
    vector <ll> numeros;

    cin >> t;
    vector <ll> resultados(t);

    for(ll i=0;i<t;i++){
        cin >> n;
        numeros.resize(n);
        ll contador = 0;

        for(ll j=0;j<n;j++){cin >> numeros[j];}

        while(buscar(numeros)) {contador++;}
        
        resultados[i] = contador;
    }

    for(ll i=0;i<t;i++){cout << resultados[i] << endl;}

    return 0;
}