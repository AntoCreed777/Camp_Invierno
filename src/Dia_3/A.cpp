#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main() {
    ll t, n;
    cin >> t;

    vector < vector <ll>> respuestas;

    for(int i=0; i<t;i++){
        cin >> n;
        vector <ll> numeros_suma;

        ll libres = 0;
        
        while(n != 0){
            ll aux = n%10;
            if(aux != 0){
                numeros_suma.push_back(aux * pow(10,libres));
                n -= aux;
            }
            else{
                libres++;
                n/=10;
            }
        }
        respuestas.push_back(numeros_suma);
    }

    for(int i = 0; i < t; i++){
        cout << respuestas[i].size() << endl;
        for(size_t j = 0; j < respuestas[i].size(); j++){
            cout << respuestas[i][j] << " ";
        }
        cout << endl;
    }   
    return 0;
}