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
vector<vector<int> >edge;
vector<int> deg;
vector<int> dp;
void topo(vector<int> r) {
	queue<int>q;
	for (auto e : r) q.push(e);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (auto e : edge[p]) {
			deg[e]--;
			if (!deg[e]) q.push(e);
			dp[e] = max(dp[p] + 1, dp[e]);
		}
	}
}
signed main() {
	mikumywaifu;
	misakamywaifu;
	int n, m;
	cin >> n >> m;
	edge.resize(n + 1);
	deg.resize(n + 1);
	dp.resize(n + 1);
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		deg[y]++;
	}
	vector<int> rt;
	for (int i = 1;i <=n;i++) {
		if (!deg[i]) rt.push_back(i);
	}
	topo(rt);
	int ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}
