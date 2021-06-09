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
	cin >> n;
	vector<vector<ll> >arr(n + 1, vector<ll>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}
	vector<ll> dp((1 << n)), res(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) tmp.push_back(j);
		}
		ll a = 0;
		for (int i = 0; i < tmp.size(); i++) {
			for (int j = i; j < tmp.size(); j++) {
				a += arr[tmp[i]][tmp[j]];
			}
		}
		res[i] = a;
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = i; j; j = (j - 1) & i) {
			dp[i] = max(dp[i], res[j] + dp[i^j]);
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
	return 0;
} 
