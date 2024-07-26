#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main() {
    ll n,p,a;
    cin >> n;

    vector <bool> pasar(n,false);

    cin >> p;

    for(int i=0;i<p;i++){
        cin >> a;
        pasar[a-1] = true;
    }

    cin >> p;

    for(int i=0;i<p;i++){
        cin >> a;
        pasar[a-1] = true;
    }
    
    for(int i=0;i<n;i++){
        if(!pasar[i]){cout << "Oh, my keyboard!" << endl;return 0;}
    }

    cout << "I become the guy." << endl;
    return 0;
}