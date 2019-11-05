//#include<cstdio>
long long gcd(long long a, long long b) {
	while (b ^= a ^= b ^= a %= b); return a;
}
//int main(void) {
//	long long a, b, c, d, w, l, dd;
//	bool ans = true;
//	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
//	w = b / c;
//	long long tt = b - (w*c);
//	long long gg = c*d/gcd(c, d);
//	dd = tt/d;
//	while (1) {
//		if (tt%d == 0 && (w*c + dd * d) == b)
//			break;
//		w--;
//		tt += c;
//		dd = tt / d;
//		if (w + dd > a||w<0) {
//			ans = false;
//			break;
//		}
//	}
//	if (!ans)
//		printf("-1\n");
//	else
//	printf("%lld %lld %lld\n", w,dd, a - w -dd);
//	return 0;
//}
#include<cstdio>
int main(void) {
	long long a, b, c, d;
	bool ans = true;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	long long cha = c - d;
	long long quanwin =(b/c+1)*c;
	long long chafeng =quanwin-b;
	long long draw = chafeng /cha;
	long long w = b - (draw*d);
	long long gg = chafeng*cha/gcd(chafeng,cha)/cha;
	w /= c;
	w = w - 1 - gg;
	if (w + draw <= a && w >= 0) {
		printf("%lld %lld %lld\n", w, gg, a - gg-w);
	}
	else if (b == 0)
		printf("0 0 %lld\n", a);
	else
		printf("-1\n");
	return 0;
}