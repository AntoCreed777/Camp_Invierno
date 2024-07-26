#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t, n, k, puntaje;
    string a, b;
    cin >> t;
    vector <ll> resultados;
    multiset <pair<ll>> aNumeros;
    vector <ll>  bNumeros;

    for (ll i = 0; i < t; i++) {
        cin >> n >> k;

        bNumeros.resize(n);

        for(ll j=0;j<n;j++){
            ll aux;
            cin >> aux;
            aNumeros[j].insert({aux,j});
        }
        for(ll j=0;j<n;j++){cin >> bNumeros[j];}

        for(ll j=0;j<k;j++){
            puntaje += aNumeros.end().first;
        }


        aNumeros.clear();
    }

    for (size_t i = 0; i < resultados.size(); i++) {
        cout << resultados[i] << endl;
    }

    return 0;
}