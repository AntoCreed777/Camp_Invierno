#include <bits/stdc++.h>

using namespace std;
typedef int ll;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> celdas(n, vector<ll>(n));
    vector<vector<ll>> celda_resultados(n / k, vector<ll>(n / k));

    for (ll j = 0; j < n; j++) {     // Rellenar celdas
        for (ll l = 0; l < n; l++) {
            cin >> celdas[j][l];
        }
    }

    cout << n << endl;

    for (ll j = 0; j < n; j++) {     // Rellenar celdas
        for (ll l = 0; l < n; l++) {
            cout << celdas[j][l];
        }
        cout << endl;
    }

    /*

    // Procesar bloques
    for (ll i = 0; i < n; i += k) {
        for (ll j = 0; j < n; j += k) {
            celda_resultados[i / k][j / k] = celdas[i][j];
        }
    }

    // Imprimir resultados
    for (size_t j = 0; j < (n / k); j++) {
        for (size_t l = 0; l < (n / k); l++) {
            cout << celda_resultados[j][l] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}