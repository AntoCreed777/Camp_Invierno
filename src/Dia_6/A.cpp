#include <bits/stdc++.h>
#include <ios>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t,n,m;

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n >> m;
        if(n == m){
            cout << "AC" << "\n";
        }
        else{
            cout << "WA" << "\n";
        }
    }   
    
    return 0;
}