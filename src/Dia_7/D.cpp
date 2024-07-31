#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, b;

    cin >> s >> b;
    
    int n = s.size(), m = b.size(), count = 0;

    for (int i=0; i<=n-m;i++){
        if (s.substr(i, m) == b)count++;
    }

    cout << count << endl;

    return 0;
}