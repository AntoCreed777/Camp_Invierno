#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

ll tiendas(ll monedas, multiset <ll>& precios){
    auto it = upper_bound(precios.begin(), precios.end(), monedas);
    return  distance(precios.begin(), it);
}
    
int main() {
    ll n,m;
    cin >> n;
    
    multiset <ll> precios;
    vector <ll> resultados;
    
    for(int i=0;i<n;i++){
        ll aux;
        cin >> aux;
        precios.insert(aux);
    }
    cin >> m;
    
    for(int i=0;i<m;i++){
        ll aux;
        cin >> aux;
        resultados.push_back(tiendas(aux,precios));
    }
    
    for(int i=0;i<m;i++){
        cout << resultados[i] <<endl;
    }
    
    return 0;
}