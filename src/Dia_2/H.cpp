    #include <bits/stdc++.h>
        
    using namespace std;
    typedef long long ll;
        
    int main() {
        ll t;
        cin >> t;
     
        vector <ll> resultados; 
     
        for(int i=0;i<t;i++){
            ll n, q;
            multiset <ll> sugar;  //Azucar que me aporta cada uno
            vector <ll> meta;   //Cuanta azucar quiero comer
            vector <ll> suma_sugar;
            cin >> n >> q;      //n son los caramelos, q es las consultas
            int anterior = 0;

            for(int j=0;j<n;j++){
                ll aux;
                cin >> aux;
                sugar.insert(aux);
            }

            for (auto it = sugar.rbegin(); it != sugar.rend(); ++it) {
                anterior += *it;
                suma_sugar.push_back(anterior);
            }

            for(int j=0;j<q;j++){
                ll aux;
                cin >> aux;
                if(aux > suma_sugar.back()){
                    resultados.push_back(-1);
                }
                else{
                    auto it = lower_bound(suma_sugar.begin(), suma_sugar.end(), aux);
                    ll posicion = distance(suma_sugar.begin(), it) + 1;
                    resultados.push_back(posicion);
                }
            }
        }
     
        for(size_t i=0;i<resultados.size();i++){cout << resultados[i] << endl;}
     
     
        return 0;
    }