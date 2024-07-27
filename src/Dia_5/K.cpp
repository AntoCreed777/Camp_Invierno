#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

int main() {
    string s;
    ll alto = 0,mayor=0,posicion=0;

    cin >> s;

    for(size_t i=0;i< s.size();i++){
        if(s[i] == '+'){
            alto++;
            if(alto > mayor){
                mayor =alto;
                posicion=i;
            }
        }
        else{
            alto--;
        }   
    }

    cout << posicion+1 << endl;
    return 0;
}