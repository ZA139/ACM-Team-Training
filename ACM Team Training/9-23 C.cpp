#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int zhangwentaodashuaibi[100][100];
int list[100];
int main() {
	scanf("%d %d", &n, &m);
	int be, en;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &be, &en);
		zhangwentaodashuaibi[be][en] = 1;
		zhangwentaodashuaibi[en][be] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= 7; i++) {
		for (int j = i + 1; j <= 7; j++) {
			if (zhangwentaodashuaibi[i][j]) {
				list[i]++;
			}
		}
	}

	int ans = 100000;
	for (int i = 1; i <= 7; i++) {
		cnt += list[i];
		//cout<<list[i]<<" "<<i<<endl;
	}
	if (cnt >15) cout << 16 << endl;
	else cout << cnt << endl;
	return 0;
}
