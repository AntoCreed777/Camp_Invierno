#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
 
int count(int n, int x, const vector<int>& monedas){
    vector<int> dp(x + 1, 0);
    
    dp[0] = 1;
 
    for (int i = 1; i <= x; ++i) {
        for (int moneda : monedas) {
            if (i - moneda >= 0) {
                dp[i] = (dp[i] + dp[i - moneda]) % MOD;
            }
        }
    }
 
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {cin >> coins[i];}
    
    cout << count(n,x, coins) << endl;
    
    return 0;
}