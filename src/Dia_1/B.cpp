#include <bits/stdc++.h>
    
using namespace std;
    
int main() {
    int n, total = 0;
    string k;
    
    cin >> n >> k;
    
    int valor[n];
    
    for (int j = 0; j < n; j++){
        valor[j] = k[j] - '0';
    }
    
    for (int i = 0; i < n; i++){
        for (int k = i; k < n; k++){
            if (((valor[i] % 2 != 0) || (valor[i] % 2 == 0 )) && ( valor[k] % 2 == 0)){
                total += 1;
            }
        }
    }
    
    cout << total << endl;
    return 0;
}