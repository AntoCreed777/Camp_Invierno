#include <bits/stdc++.h>
#include <cstddef>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    string binario;
    bool primo = false;

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> binario;

        for(size_t i=0;i<binario.size()-1;i++){
            if(binario[i] == '1'){
                cout << "Yes" << "\n";
                primo = true;
                break;
            }
        }
        if(!primo)cout << "No" << "\n";
        primo = false;
    }

    return 0;
}