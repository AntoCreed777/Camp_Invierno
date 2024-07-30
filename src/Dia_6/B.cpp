#include <bits/stdc++.h>
#include <ios>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a,b,c;

    cin >> a >> b >> c; //Costo >> Ganancia >> Meta de Edificios

    ll edificios = 1, meses = 0,dinero=0;

    while(edificios < c){
        dinero+= (edificios*b);
        if(dinero >= a){
            edificios+= dinero/a;
            dinero%=a;
        }
        meses++;
    }

    cout << meses << "\n";

    
    return 0;
}