#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main() {
    ll t, n,k;
    cin >> t;

    vector <ll> resultados;

    for(int i=0; i<t;i++){
        cin >> n >> k;
        if(k >= (n-1)){resultados.push_back(1);}
        else{resultados.push_back(n);}
    }

    for(int i=0; i<t;i++){
        cout << resultados[i] << endl;;
    }
    return 0;
}