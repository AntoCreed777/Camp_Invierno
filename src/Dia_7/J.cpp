#include <bits/stdc++.h>
#include <algorithm>
#include <ios>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string frace;
    ll q,op,lf,rg;
    cin >> frace >> q;

    for(ll i=0;i<q;i++){
        cin >> op >> lf >> rg;
        if(op == 1){
            cout << "Entre a 1" << "\n";
            frace[lf-1] = rg + '0';
        }
        else{   // op == 2  // Numero de caracteres distintos en la sub-cadena
            cout << "Entre a 2" << "\n";
            ll caracteres_distintos = 0;
            for(int i=0;i<26;i++){
                auto buscar = find(frace.begin() + lf,frace.end()-rg,i);
                if(buscar != frace.end()) caracteres_distintos++;
            }
            cout << caracteres_distintos << "\n";
        }
    }

    return 0;
}