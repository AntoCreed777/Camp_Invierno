#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
const int M = 1e9+7;

ll como_llegar(vector <string> &cuadricula, ll x, ll y, vector <vector <ll>> &formas){
    if(x <0 || y<0) return 0;
    if(formas[x][y] != -1)return formas[x][y];
    if(cuadricula[x][y] == '*') return 0;
    if(x == 0 && y == 0)return 1;

    ll aux = como_llegar(cuadricula,x-1,y,formas) + como_llegar(cuadricula,x,y-1,formas);   //izquierda + Arriba
    aux %= M;
    formas[x][y] = aux;

    return aux;
}

int main() {
    ll n;
    cin >> n;

    vector <string> cuadricula(n);
    vector <vector <ll>> formas(n,vector<ll>(n,-1));

    for(int i=0;i<n;i++){cin >> cuadricula[i];}

    cout << como_llegar(cuadricula,n-1,n-1,formas) << endl;

    return 0;
}