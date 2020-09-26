#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
using namespace std;

#define getT long long t;scanf("%lld",&t)
#define getN long long n;scanf("%lld",&n)
#define for0n(n) getN; for(long long i=0;i<n;i++)
#define for1n(n) getN; for(long long i=1;i<=n;i++)
#define for0(n) for(long long i=0;i<n;i++)
#define for1(n)  for(long long i=1;i<=n;i++)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

typedef long long ll;
ll mod;
ll gcd(ll a, ll b) {
	return a % b == 0 ? b : gcd(b, a%b);
}

ll pow(ll a, ll b) {
	ll an = 1;
	ll base = a % mod;
	while (b > 0) {
		if (b & 1 != 0) {
			an = (an*base) % mod;
		}
		base = (base*base) % mod;
		b >>= 1;
	}
	return an % mod;
}

ll inv(ll a) {
	return pow(a, mod - 2);
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
ll Arithmetic(ll a1, ll n, ll d) {
	ll sum = 0;
	sum += n * a1;
	sum %= mod;
	ll temp = n * (n - 1);
	temp %= mod;
	temp *= d;
	temp %= mod;
	temp /= 2;
	temp %= mod;
	return (sum + temp) % mod;
}
enum skills {
	Y, V, G, C, X, Z, T, F, D, B
};
string key[11][11];
ll dp[100005][10];
void init() {
	memset(dp, 0x3f3f3f3f3f3f3f3f, sizeof(dp));
	for0(10) {
		dp[0][i] = 3;
	}
	key[Y][0] = { "QQQ" };
	key[Y][1] = { "QQQ" };
	key[Y][2] = { "QQQ" };
	key[Y][3] = { "QQQ" };
	key[Y][4] = { "QQQ" };
	key[Y][5] = { "QQQ" };

	key[V][0] = { "QQW" };
	key[V][1] = { "WQQ" };
	key[V][2] = { "QWQ" };
	key[V][3] = { "QWQ" };
	key[V][4] = { "QWQ" };
	key[V][5] = { "QWQ" };

	key[G][0] = { "QQE" };
	key[G][1] = { "EQQ" };
	key[G][2] = { "QEQ" };
	key[G][3] = { "QEQ" };
	key[G][4] = { "QEQ" };
	key[G][5] = { "QEQ" };

	key[C][0] = { "WWW" };
	key[C][1] = { "WWW" };
	key[C][2] = { "WWW" };
	key[C][3] = { "WWW" };
	key[C][4] = { "WWW" };
	key[C][5] = { "WWW" };

	key[X][0] = { "QWW" };
	key[X][1] = { "WQW" };
	key[X][2] = { "WWQ" };
	key[X][3] = { "WWQ" };
	key[X][4] = { "WWQ" };
	key[X][5] = { "WWQ" };

	key[Z][0] = { "WWE" };
	key[Z][1] = { "WEW" };
	key[Z][2] = { "EWW" };
	key[Z][3] = { "EWW" };
	key[Z][4] = { "EWW" };
	key[Z][5] = { "EWW" };

	key[T][0] = { "EEE" };
	key[T][1] = { "EEE" };
	key[T][2] = { "EEE" };
	key[T][3] = { "EEE" };
	key[T][4] = { "EEE" };
	key[T][5] = { "EEE" };

	key[F][0] = { "QEE" };
	key[F][1] = { "EQE" };
	key[F][2] = { "EEQ" };
	key[F][3] = { "EEQ" };
	key[F][4] = { "EEQ" };
	key[F][5] = { "EEQ" };

	key[D][0] = { "WEE" };
	key[D][1] = { "EWE" };
	key[D][2] = { "EEW" };
	key[D][3] = { "EEW" };
	key[D][4] = { "EEW" };
	key[D][5] = { "EEW" };

	key[B][0] = { "QWE" };
	key[B][1] = { "WQE" };
	key[B][2] = { "QEW" };
	key[B][3] = { "WEQ" };
	key[B][4] = { "EQW" };
	key[B][5] = { "EWQ" };
}
ll dif(string a, string b) {
	if (a == b)
		return 0;
	if (a.substr(1, 2) == b.substr(0, 2)) {
		return 1;
	}
	if (a[2] == b[0]) {
		return 2;
	}
	return 3;
}
ll getid(char a) {
	if (a == 'Y') {
		return 0;
	}
	if (a == 'V') {
		return 1;
	}
	if (a == 'G') {
		return 2;
	}
	if (a == 'C') {
		return 3;
	}
	if (a == 'X') {
		return 4;
	}
	if (a == 'Z') {
		return 5;
	}
	if (a == 'T') {
		return 6;
	}
	if (a == 'F') {
		return 7;
	}
	if (a == 'D') {
		return 8;
	}
	if (a == 'B') {
		return 9;
	}
}
int main(void) {
	IOS;
	init();
	string order;
	cin >> order;
	ll len = order.length();
	char pre = ' ';
	ll ans = 0, cnt = 0;
	string temp = order.substr(0, 1);
	for (ll i = 1; i < len; i++) {
		if (order[i - 1] == order[i]) {
			cnt++;
		}
		else {
			temp += order[i];
		}
	}
	ll lim = len - cnt;
	order = temp;
	pre = order[0];
	for (ll i = 1; i < lim; i++) {
		for (ll j = 0; j < 6; j++) {
			for (ll k = 0; k < 6; k++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + dif(key[getid(pre)][k], key[getid(order[i])][j]));
			}
		}
		pre = order[i];
	}
	ll mi = 0x3f3f3f3f3f3f;
	for0(6) {
		mi = min(mi, dp[lim - 1][i]);
	}
	cout << mi + len << endl;
	return 0;
}