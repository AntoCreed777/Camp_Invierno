#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

int main() {
    ll t, n;
    cin >> t;

    vector <ll> resultados(t);

    for(ll i=0;i<t;i++){
        cin >> n;
        ll vacas = n / 4;
        ll sobrantes = n%4;
        ll patos =  sobrantes / 2;
        resultados[i] = vacas + patos;
    }

    for(ll i=0;i<t;i++){
        cout << resultados[i] << endl;
    }


    return 0;
}