#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

ll pintar(vector<ll> lienzos){
    if(lienzos.size() <= 2){
        ll aux=0;
        for(size_t i=0;i<lienzos.size();i++){
            aux += lienzos[i];
        }
        return aux;
    }

    size_t mitad = lienzos.size() / 2;
    vector<ll> izquierda(lienzos.begin(), lienzos.begin() + mitad);
    vector<ll> derecha(lienzos.begin() + mitad, lienzos.end());

    if(izquierda.size() <= 1){
        return pintar(izquierda) + pintar(derecha) * 2;
    }
    if(derecha.size() <= 1){
        return pintar(izquierda)*2 + pintar(derecha);
    }

    return (pintar(izquierda) + pintar(derecha))*2;
}

int main() {
    ll t, n;
    cin >> t;
    vector <ll> resultados;

    for(int i=0; i<t;i++){
        cin >> n;
        vector <ll> lienzos;
        //ll suma = 0;

        for(int j=0;j<n;j++){
            ll aux;
            cin >> aux;
            lienzos.push_back(aux);
        }
        resultados.push_back(pintar(lienzos));
    }

    for(int i=0; i<t;i++){
        cout << resultados[i] << endl;
    }

    return 0;
}

// 3 5 5 7
// 3 5
// 7 5