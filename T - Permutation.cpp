#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define misakamywaifu 
#define pb push_back
#define mem(i,j) memset(i,j,sizeof(i))
#define pii pair<int,int>
const int mod = 1000000007;
const int MAXN = 100005;
const int INF = 0x3F3F3F3F;
const long long LINF = 4611686018427387903;
//--------------------------------------------------//
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s1;
	cin >> n;
	cin>> s1;
	ll ans = 0;
	vector<vector<ll>> dp(n + 2,vector<ll>(n + 2));
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		if (s1[i - 2] == '<') {
			dp[i][1] = 0;
			for (int j = 2; j <= i; j++) {
				dp[i][j] = (dp[i][j-1] + dp[i-1][j - 1]) % mod;
			}
		}
		else {
			dp[i][i] = 0;
			for (int j = i - 1; j; j--) {
				dp[i][j] = (dp[i-1][j] + dp[i][j + 1]) % mod;
			}
		}
	}
	for (int i = 1; i <= n; i++) ans =(ans+dp[n][i])%mod;
	cout << ans << "\n";
	return 0;
} 
