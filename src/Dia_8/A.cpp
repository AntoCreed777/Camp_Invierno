#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k,n,w;

    cin >> k >> n >> w; //Valor priemera banana, dolares iniciales, bananas que quiero

    ll total_incremento= (w*(w+1)) /2;
    ll precio_total=total_incremento*k;

    ll prestado = precio_total-n;

    if(prestado < 0)prestado=0;

    cout <<  prestado << "\n";

    return 0;
}   