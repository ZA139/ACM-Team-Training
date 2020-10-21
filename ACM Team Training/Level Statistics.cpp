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
int main(void) {
	getT;
	while (t--)
	{
		ll ta=0, tb=0, a, b;
		bool flag = true;
		getN;
		for0(n) {
			scanf("%lld%lld", &a, &b);
			if (a < b) {
				flag = false;
			}
			if (a < ta || b < tb) {
				flag = false;
			}
			if ((a-ta)<(b-tb)) {
				flag = false;
			}
			ta = a;
			tb = b;
		}
		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}