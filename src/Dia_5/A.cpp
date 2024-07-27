#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int minCoins(int n, int x, const vector<int>& coins) {
    const int INF = INT_MAX;
    vector<int> dp(x + 1, INF);
    
    dp[0] = 0;
    for (int coin : coins) {
        for (int j = coin; j <= x; ++j) {
            if (dp[j - coin] != INF) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }
    if(dp[x] == INF) {
    	return -1;
	}
    return dp[x];
}
 
int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    cout << minCoins(n, x, coins) << endl;
    
    return 0;
}