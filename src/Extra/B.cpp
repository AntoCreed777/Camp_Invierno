#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

int main() {
    ll t, n, k;
    cin >> t;

    vector <vector <vector <ll>>> resultados(t);


    for(ll i=0;i<t;i++){
        cin >> n >> k;

        vector<vector<ll>> celdas(n, vector<ll>(n));
        vector<vector<ll>> celda_resultados(n / k, vector<ll>(n / k));

        for(ll j = 0; j < n; j++) {     // Rellenar celdas
            for(ll l = 0; l < n; l++) {
                cin >> celdas[j][l];
                if((j%k == 0) && (l % k == 0)){
                    celda_resultados[j / k][l / k] = celdas[j][l];  //Para que no lo haga muchas veces
                }
                
            }
        }   

        resultados[i]=celda_resultados;
    }

    for(int i=0;i<t;i++){
        for(size_t j=0;j<resultados[i].size();j++){
            for(size_t l=0;l<resultados[i].size();l++){
                cout << resultados[i][j][l];
            }
            cout << endl;
        }
        cout << endl;       //no olvidar de sacar
    }

    return 0;
}