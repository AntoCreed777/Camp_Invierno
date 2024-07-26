#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ab+ac+bc≤n y a+b+c≤xa+b+c≤x. 
int main() {
    ll t,n,x;
    cin >> t;

    vector <ll> resultados(t);
    for(ll i =0;i<t;i++){
        ll a,b,c;
        cin >> n >> x;
        if(x%3 == 0){
            a = x/3;
            b = a;
            c = a;
            
        }
        else if(x%3 == 1){

        }
        else{   //x%3 == 2

        }

    }

    for(ll i =0;i<t;i++){
        cout << resultados[i] <<endl;
    }


    return 0;
}