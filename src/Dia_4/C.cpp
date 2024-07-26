#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

vector <ll> dolaresV;
vector <ll> eurosV;

ll minimo_dinero(ll n, int posicion){
    if(n == 0) return 0;
    if(posicion < 0) return n;
    ll minimo = n;

    for(int i = posicion;i>=0;i--){
        //cout << minimo << endl;
        if(n >= dolaresV[i]){
            ll nuevo_n = n % dolaresV[i];
            ll aux = minimo_dinero(nuevo_n, i - 1);
            if (minimo > aux) minimo = aux;
        }
    }
    return minimo;
}
    
int main() {
    ll n,d,e;
    cin >> n >> d >> e;

    ll dolares[7] = {1, 2, 5, 10, 20, 50, 100};
    ll euros[6] = {5, 10, 20, 50, 100, 200};

    for(int i=6;i>=0;i--){dolaresV.push_back(dolares[i]*d);}
    for(int i=5;i>=0;i--){eurosV.push_back(euros[i]*e);}

    dolaresV.insert(dolaresV.end(),eurosV.begin(),eurosV.end());
    sort(dolaresV.begin(),dolaresV.end());

    //Buscar con recursividad

    /*
    for(int i = dolaresV.size() -1;i>=0;i--){
        cout << dolaresV[i] << endl;
        if(n >= dolaresV[i]){
            n = n % dolaresV[i];
        }
    }
    */

    cout << minimo_dinero(n,dolaresV.size() -1) << endl;

    return 0;
}