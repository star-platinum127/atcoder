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
const ll mod = 100000007;
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
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n + 1), dp(n + 1,1e9);
	dp[0] = 0;
	for (int i = 0;i < n;i++) cin >>arr[i];
	for (int i = 1;i < n;i++) {
		for (int j = 1;j <=k;j++) {
			if (j > i) break;
			dp[i] = min(dp[i - j] + abs(arr[i] - arr[i-j]), dp[i]);
		}
	}
	cout << dp[n - 1] << "\n";
	return 0;
}
