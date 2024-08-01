#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;


const ll LOG = 25, mxN = 2e5+5;
int parent[mxN], depth[mxN], up[LOG][mxN];
vector<ll> empresa[mxN];
//vector<ll> adj[mxN];
// up[x][v] = salto a 2^x ancestros desde el nodo v
void preproceso(ll u=0,ll p=0){
    parent[u] = up[0][u] = p;
    for(ll x=1;x<LOG;++x){
        up[x][u] = up[x-1][up[x-1][u]];
    }
    for(ll v : empresa[u]){
        if(v == p)continue;

        depth[v] = depth[u] +1;
        preproceso(v,u);
    }
}

ll k_ancestro(ll u, ll k){
    for(ll bit=0;bit<LOG; ++bit){
        if(k & (1<<bit)){
            u = parent[u];
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,q;

    cin >> n >> q;  // Empleados >> Consultas(Querys)
    
    //empresa.resize(n+1);
    //empresa[0] = -1;
     //El input representa al jefe del i-esimo empleado
    for(ll i=1;i<n;i++){
        ll jefe;
        cin >> jefe; 
        empresa[jefe].push_back(i);
    }

    preproceso();
    for(ll i=0;i<q;i++){
        ll x,k;
        cin >> x >> k;  //Empleado >> niveles que quiero subir en los jefes

        cout << k_ancestro(x,k) << "\n";
        /*
        ll nodo_actual = x;
        for(ll j=0;j<k;j++){
            if(nodo_actual-1 < 0){
                nodo_actual = -1;
                break;
            }
            nodo_actual = empresa[nodo_actual-1];
            //cout << nodo_actual << "\n";
        }
        cout << nodo_actual << "\n";
        */
    }

    return 0;
}