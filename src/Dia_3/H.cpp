#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> nodos(n);

    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        nodos[u].push_back(v);
        nodos[v].push_back(u);
    }

    ll cantidad_hojas = 0;

    for(int i=0;i<n;i++){
        if(nodos[i].size() == 1){cantidad_hojas++;}
    }
    //cout<< "hojas : "<< cantidad_hojas << endl;
    if(cantidad_hojas % 2 == 0){cout << cantidad_hojas / 2 << endl;}
    else{cout << ((cantidad_hojas-1)/2)+1 << endl;}

    return 0;
}