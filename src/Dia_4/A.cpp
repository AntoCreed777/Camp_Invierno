#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main() {
    ll t, rating;
    cin >> t;

    vector <string> resultados;

    for(int i=0; i<t;i++){
        cin >> rating;
        if(rating <= 1399) resultados.push_back("Division 4");
        if(rating <= 1599 && rating >= 1400) resultados.push_back("Division 3");
        if(rating <= 1899 && rating >= 1600) resultados.push_back("Division 2");
        if(rating >= 1900) resultados.push_back("Division 1");
    }

    for(int i=0; i<t;i++){
        cout << resultados[i] << endl;
    }



    return 0;
}