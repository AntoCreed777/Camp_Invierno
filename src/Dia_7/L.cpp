#include <bits/stdc++.h>
#include <ios>

using namespace std;
typedef long long ll;

#define MAXLARGE 10

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    string input;

    cin >> n;

    for(ll i=0;i<n;i++){
        cin >> input;
        if(input.size() <= MAXLARGE)cout << input << "\n";
        else cout << input[0] << input.size()-2 << input[input.size()-1] << "\n";
    }

    return 0;
}

// abcdabc abcdabc