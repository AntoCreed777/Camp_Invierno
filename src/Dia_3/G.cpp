#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main() {
    ll n,m;
    cin >> n >> m;

    if(n > m){
        cout << n-m << endl;
    }
    else{
        ll pulsaciones = 0;
        while(m > n){
            if(m %2 != 0){
                m++;
                pulsaciones++;
            }
            m/=2;
            pulsaciones++;
        }
        pulsaciones += n-m;
        cout << pulsaciones << endl;
    }
    return 0;
}