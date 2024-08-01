#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;

    cin >> n;

    vector<ll> numeros(n);
    vector<ll> primos;
    vector<ll> naturales(1000001);


    for(ll i=0;i<n;i++)cin >> numeros[i];
    

    for(ll i=2;i<=1000000;i++){
        if(naturales[i] == 0){
            primos.push_back(i);
            for(ll j=i;j<=1000000;j+=i)naturales[j] = 1;
        }
    }

    for(ll i=0;i<n;i++){
        if(binary_search(primos.begin(),primos.end(),sqrt(numeros[i])))cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}