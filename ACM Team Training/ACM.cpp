#include<cstdio>
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
#define INF 0x3f3f3f3f3f3f
#define maxn 10000
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
ll euler(ll n)
{
	ll ans = n;
	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0)
		{
			ans = ans - ans / i;
			while (n%i == 0)
				n /= i;
		}
	if (n > 1)
		ans = ans - ans / n;
	return ans;
}
void release_que(queue <ll>q) {
	while (!q.empty())
	{
		q.pop();
	}
	return;
}
double fabs(double a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}
double Newtonsqrt(double n,double errors) {
	if (n < 0) {
		return -1;
	}
	double root = n;
	while (fabs(n-root*root)>=errors)
	{
		root = (n / root + root) / 2.0;
	}
	return root;
}
int main(void) {
	return 0;
}