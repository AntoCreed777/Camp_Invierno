#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x,movimientos_totales=0;

    cin >> x;

    //Movimientos permitidos 1,2,3,4,5
    movimientos_totales+= x/5;
    x%=5;
    movimientos_totales+= x/4;
    x%=4;
    movimientos_totales+= x/3;
    x%=3;
    movimientos_totales+= x/2;
    x%=2;
    movimientos_totales+= x;

    cout << movimientos_totales << "\n";

    return 0;
}