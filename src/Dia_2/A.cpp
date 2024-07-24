    #include <bits/stdc++.h>
        
    using namespace std;
        
    int main() {
        long long t,h,n;  //h es vida del boos, n son la cantidad de ataques
        vector <long long> resultados;
     
        cin >> t;
     
        for(int i=0;i<t;i++){
            cin >> h >> n;
     
            vector <long long> damage;
            vector <long long> cooldown;
     
            for(int j=0;j<n;j++){
                long long aux;
                cin >> aux;
                damage.push_back(aux);
            }
            for(int j=0;j<n;j++){
                long long aux;
                cin >> aux;
                cooldown.push_back(aux);
            }
     
            long long total_movimientos = 0;
            vector <long long> ataque(n,1);
     
            while(h > 0){
                vector <long long> posiciones;
                for(int i=0;i<n;i++){
                    if(i==0){total_movimientos = ataque[0];}
                    if(ataque[i]< total_movimientos){total_movimientos = ataque[i];posiciones.push_back(i);}
                    else{posiciones.clear();}
                }
     
                for(size_t i=0; i<posiciones.size(); i++){
                    h -= damage[posiciones[i]];
                    ataque[posiciones[i]] += cooldown[posiciones[i]];
                }
            }
     
            resultados.push_back(total_movimientos);
        }
     
        for(int i=0;i<t;i++){
            cout << resultados[i] << endl;
        }
        
        return 0;
    }