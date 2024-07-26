#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

vector <ll> dolaresV;
vector <ll> eurosV;
    
int main() {
    ll n,d,e;
    cin >> n >> d >> e;

    //Todas las monedas de dolares se pueden expreser en convinacion de un billete de 1 dolar
    //Todas las monedas de euro se pueden expresar como convinacion de biletes de 5 euros

    // a*d + b*(e*5) <= n       //Con a y b constantes
    // a*d <= n - b*(e*5)

    int mn = n;
    int b = 1;

    while(n-5*e*b >=0){
        mn = min(mn, (n-5*e*b) % d);
    }

    cout << mn << endl;

    return 0;
}