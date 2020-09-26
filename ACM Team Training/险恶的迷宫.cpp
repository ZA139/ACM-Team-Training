#include<cstdio>
#include<cmath>
const long long mod = 1e9 + 7;
long long ans[1000005];
long long prime[1000005];//��������
bool is_prime[1000005 + 10];//is_pri[i]��ʾi������
inline long long slove(long long k) {
	if (is_prime[k]) {
		return ((1 + k) / 2) % mod;
	}
	long long temp = sqrtl(k);
	if (temp*temp == k) {
		return temp % mod;
	}
	else {
		for (long long i = temp; i > 1; i--) {
			if (k%i == 0) {
				return ((temp + k / temp) / 2) % mod;
			}
		}
	}
}
//����n���������ĸ���
int sieve(long long n)
{
	int p = 0;//��������������
	for (int i = 0; i <= n; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;//���ȱ��0��1��������
	is_prime[2] = true;//���2������

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (is_prime[i]) //���i������
		{
			prime[++p] = i;//�������Ž�������
			for (int j = i * i; j <= n; j += 2 * i)//����i�ı�������������
				is_prime[j] = false;
		}
	}
	return p;
}
int main(void) {
	//sieve(1000005);
	for (long long i = 0; i < 1000001; i++) {
		ans[i] = ans[i - 1] + slove(i);
		ans[i] %= mod;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}