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
using mat = vector<vector<ll>>;
int n;
mat operator*(mat& a, mat& b) {
	mat tmp(n, vector<ll>(n));
	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				tmp[i][j] =(tmp[i][j]+ (a[i][k] * b[k][j]))%mod;
			}
		}
	}
	return tmp;
}
mat qpow(mat x, ll a) {
	mat b(n,vector<ll>(n,0));
	for (int i = 0;i < n;i++) {
		b[i][i] = 1;
	}
	while (a) {
		if (a & 1) b = x * b;
		x = x * x;
		a >>= 1;
	}
	return b;
}
signed main() {
	mikumywaifu;
	misakamywaifu;
	ll k;
	cin >> n >> k;
	mat c(n, vector<ll>(n));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> c[i][j];
		}
	}
	mat ans=qpow(c, k);
	ll ouo = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			ouo =(ouo+ans[i][j])%mod;
		}
	}
	cout << ouo << "\n";
	return 0;
}
