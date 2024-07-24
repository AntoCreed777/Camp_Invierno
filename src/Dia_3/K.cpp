#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

void dfs(ll actual, ll meta, vector<vector<ll>>& caminos, vector<bool>& visitado, vector<ll>& camino, vector<vector<ll>>& todos_los_caminos) {
    visitado[actual] = true;
    camino.push_back(actual);

    if (actual == meta) {
        todos_los_caminos.push_back(camino);
    } else {
        for (size_t i = 0; i < caminos[actual].size(); ++i) {
            if (caminos[actual][i] == 1 && !visitado[i]) {
                dfs(i, meta, caminos, visitado, camino, todos_los_caminos);
            }
        }
    }

    camino.pop_back();
    visitado[actual] = false;
}


int main() {
    ll n,m,s,t,u,v;
    cin >> n >> m;
    cin >> s >> t;  //Llegar desde "s" hasta "t"
    
    vector<vector<ll>> caminos(n, vector<ll>(n, 0));

    for(int i=0;i<m;i++){
        cin >> u >> v;
        caminos[u-1][v-1] = 1;
    }

    vector <bool> visitado(n, false);
    vector<vector<ll>> todos_los_caminos;
    vector <ll> camino;

    dfs(s-1, t-1, caminos, visitado, camino, todos_los_caminos);

    cout << todos_los_caminos.size() << endl;

    for(size_t i=0; i< todos_los_caminos.size();i++){
        //cout << todos_los_caminos[i].size() << endl;
        for(size_t j=0;j< todos_los_caminos[i].size();j++){cout << todos_los_caminos[i][j] + 1 << " ";}
        cout << endl;
        if((todos_los_caminos[i].size() - 1) %2 != 0){cout << "No" << endl;return 0;}
    }

    cout << "Yes" << endl;

    return 0;
}
