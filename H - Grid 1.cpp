#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mikumywaifu ios_base::sync_with_stdio(0)
#define misakamywaifu cin.tie(0)
#define pb push_back
#define S second
#define F first
#define mem(i,j) memset(i,j,sizeof(i))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define lowbit(x) x&-x
const ll mod = 1000000007;
const int INF = 0x3F3F3F3F;
const long long LINF = 4611686018427387903;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}
void debug() {
	cout << "DEBUG :";
}
/*-----------------------------------------------*/

signed main() {
	mikumywaifu;
	misakamywaifu;
	int n, m;
	cin >> n >> m;
	vector<vector<int> >arr(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1,0));
	for (int i = 0;i < n;i++) {
		string s1;
		cin >> s1;
		for (int j = 0;j < m;j++) arr[i][j] = s1[j];
	}
	dp[1][1] = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (i == j && j == 1) continue;
			if (arr[i - 1][j - 1] == '.') dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			//else dp[i][j] = 0;
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}
