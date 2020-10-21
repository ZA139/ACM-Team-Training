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
ll a[100][100];
ll n, m, k;
bool flag = false;
void dfs(ll now,ll ans) {
	if (now == n) {
		if (ans%k == 0) {
			printf("%lld\n", ans);
			flag = 1;
			return;
		}
	}
	for (ll i = 0; i < m; i++) {
		ans += a[now][i];
		for (ll j = i+1; j < m; j++) {
			ans += a[now][j];
			dfs(now + 1, ans);
			if (flag)
				return;
			ans -= a[now][j];
		}
		ans -= a[now][i];
	}
}
int main(void){
	scanf("%lld%lld%lld", &n, &m, &k);
	for0(n) {
		for (ll j = 0; j < m; j++) {
			scanf("%lld", &a[i][j]);
		}
		sort(a+i*m, a+i*m+ m, [](ll a, ll b)->bool {
			return a > b;
			});
	}
	dfs(0, 0);
	return 0;
}