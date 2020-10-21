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
	ll ans = 1;
	ll base = a % mod;
	while (b > 0) {
		if (b & 1 != 0) {
			ans = (ans*base) % mod;
		}
		base = (base*base) % mod;
		b >>= 1;
	}
	return ans % mod;
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
string s[105];
int main(void) {
	freopen("Input.txt", "r", stdin);
	freopen("txt.txt", "w", stdout);
	ll m;
	IOS;
	while (cin >> m)
	{
		ll len = 0;
		for0(m) {
			cin >> s[i];
			len = max(len, (long long)s[i].length());
		}
		for (ll i = 0; i < 60; i++) {
			cout << "-";
		}
		cout << endl;
		ll col, row;
		col = 62 / (len+2);
		row = m / col;
		if (m%col) {
			row++;
		}
		sort(s, s + m);
		for (ll i = 0; i < row; i++)
		{
			for (ll j = 0; j < col; j++) {
				if (i + j * row < m) {
					ll lim = len - s[i + j * row].length();
					if (j != col - 1) {
						lim += 2;
					}
					cout << s[i + j * row];
					for (ll k = 0; k < lim; k++) {
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}