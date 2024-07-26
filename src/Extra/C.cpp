#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t, n, q, l, r;
    string a, b;
    cin >> t;
    vector<ll> resultados;

    for (ll i = 0; i < t; i++) {
        cin >> n >> q;
        cin >> a >> b;  // Entrada de string
        for (ll j = 0; j < q; j++) {
            cin >> l >> r;
            l--; r--;  // Convertir a índice 0

            //string aN = a.substr(l, r - l + 1);
            //string bN = b.substr(l, r - l + 1);

            //cout << aN << endl << bN << endl << endl;

            ll cantidad_cambiar = 0;
            
            // Crear un mapa para contar los caracteres en la subcadena de `b`
            unordered_map<char, int> cuenta_b;
            for (ll k = l; k <= r; k++) {
                cuenta_b[b[k]]++;
            }

            // Comparar caracteres en la subcadena de `a`
            for (ll k = l; k <= r; k++) {
                //size_t buscar = b.find(a[k],l)
                char c = a[k];
                if (cuenta_b[c] > 0) {
                    cuenta_b[c]--;
                } else {
                    cantidad_cambiar++;
                }
            }

            /*
            for (size_t k = 0; k < aN.size(); k++) {    
                size_t buscar = bN.find(aN[k]);
                if (buscar == string::npos) {
                    cantidad_cambiar++;
                }
                else{
                    bN[buscar] = '0';
                }
            }
            */
            resultados.push_back(cantidad_cambiar);
        }
    }

    for (size_t i = 0; i < resultados.size(); i++) {
        cout << resultados[i] << endl;
    }

    return 0;
}