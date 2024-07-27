#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

int main() {
    string superior,inferior;

    cin >> superior >> inferior;

    ll contador = 0;

    for(size_t i=0;i<superior.size()-1;i++){
        if(superior[i] == '0' && superior[i+1] == '0'){
            if(inferior[i] == '0'){
                superior[i] = 'X';
                superior[i+1] = 'X';
                inferior[i] = 'X';
                contador++;
            }
            else if (inferior[i+1] == '0'){
                superior[i] = 'X';
                superior[i+1] = 'X';
                inferior[i+1] = 'X';
                contador++;
            }
        }
        if(inferior[i] == '0' && inferior[i+1] == '0'){
            if(superior[i]=='0'){
                inferior[i] = 'X';
                inferior[i+1] = 'X';
                superior[i] = 'X';
                contador++;
            }
            else if (superior[i+1] == '0'){
                inferior[i] = 'X';
                inferior[i+1] = 'X';
                superior[i+1] = 'X';
                contador++;
            }
        }
    }

    cout << contador << endl;


    return 0;
}