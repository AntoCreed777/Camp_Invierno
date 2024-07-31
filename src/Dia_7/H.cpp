#include <bits/stdc++.h>
#include <cstddef>
#include <ios>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string palabra;
    bool prefijo = true;

    cin >> palabra;

    for(size_t i=0;i<palabra.size()/2;i++){
        if(palabra[palabra.size()-1] == palabra[i]){
            prefijo = true;
            for(ll j=i;j>=0;j--){
                if(palabra[j] != palabra[palabra.size()-i+j-1]){
                    prefijo = false;
                    break;
                }
            }
            if(prefijo) cout << i+1 << "\n";
            //else cout << "NO" << "\n";
        }
    }

    return 0;
}

// abcdabc abcdabc