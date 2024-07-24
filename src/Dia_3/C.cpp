#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main() {
    ll t,n;
    cin >> t;

    vector <bool> resultado(t,true);

    for(int i=0;i<t;i++){
        cin >> n;
        string superior,inferior;
        cin >> superior >> inferior;

        bool puede_arriba = true;
        bool puede_abajo = true;

        for(size_t j=1;j<superior.size();j+=2){
            if(inferior[j] == '<'){puede_arriba = false;}
        }

        if(inferior[n-2] == '<'){puede_arriba = false;}

        for(size_t j=0;j<inferior.size();j+=2){
            if(inferior[j] == '<'){puede_abajo = false;}
        }
        resultado[i] = puede_abajo | puede_arriba;
    }

    for(int i=0;i<t;i++){
        if(resultado[i]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}