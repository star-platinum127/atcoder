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
int d;
string s;
vector<int> arr;
ll dp[10025][125];
int len;
ll dfs(int p,int nw,bool l) {
	if (p == len) {
		dp[p][nw] = (nw==0);
		return dp[p][nw];
	}
	if (!l && dp[p][nw]!=-1) {
		return dp[p][nw];
	}
	int h = l ? arr[p] : 9;
	ll s = 0;
	for (int i = 0;i <= h;i++) {
		s += dfs(p + 1, (nw + i) % d, l && (i == h));
		s %= mod;
	}
	if (!l) dp[p][nw] = s;
	return s;
}
signed main() {
	mikumywaifu;
	misakamywaifu;
	cin >> s;
	cin >> d;
	arr.resize(s.length() + 1);
	len = s.length();
	for (int i = 0;i < len;i++) arr[i] = s[i] - '0';
	mem(dp, -1);
	cout << (dfs(0, 0, 1)-1+mod) % mod << "\n";
	return 0;
}
