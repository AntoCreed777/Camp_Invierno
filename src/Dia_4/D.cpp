#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

ll total_pruebas(ll l, ll r, vector<ll> pruebas_suma){
    return pruebas_suma[r] - pruebas_suma[l];
}

ll total_ganancias(ll ganancias, ll cuantas_pruebas){
    return ganancias*cuantas_pruebas - (cuantas_pruebas*(cuantas_pruebas-1))/2;
}

ll busqueda_binaria(vector <ll> pruebas_suma,ll l,ll n,ll ganancias){   //Maximizar ganancias totales
    ll inicio = l;
    ll fin = n;
    ll medio = (fin+inicio)/2;
    ll posicion_encontrada;

    while(inicio<=fin){
        ll tGanancias = total_ganancias(ganancias,total_pruebas(l,medio,pruebas_suma));
        if(tGanancias > 0){
            inicio = medio + 1;
            posicion_encontrada = medio;
        }
        else{
            fin = medio - 1;
        }
    }

    return posicion_encontrada;

}

int main() {
    //Faltara agregar el t de los casos de prueba
    ll n,q,l,ganancias;
    cin >> n;

    vector <ll> pruebas(n);
    vector <ll> pruebas_suma(n);
    vector <ll> resultados(n);

    for(int i=0;i<n;i++){
        cin >> pruebas[i];
        if(i==0) {pruebas_suma[i] = pruebas[i];continue;}
        pruebas_suma[i] = pruebas_suma[i-1] + pruebas[i];
    }

    cin >> q;

    for(int i=0;i<q;i++){
        cin >> l >> ganancias;
        resultados[i]= busqueda_binaria(pruebas_suma,l,n,ganancias);
    }

    return 0;
}