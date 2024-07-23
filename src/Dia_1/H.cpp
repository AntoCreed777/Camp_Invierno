#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned int t, n, k;
    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n >> k;
        if(k<2n){
            cout << 2n;
        }
    }

    return 0;
}