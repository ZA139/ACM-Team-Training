#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long arrays[1000000];
//queue<vector<int>>q;
queue<queue<int>>q;
void judge(long long a)
{
	long long sum = 0;
	for (size_t i = 0; i < a; i++)
	{
		sum += arrays[i];
	}
}
bool slove() {
	long long n, k;
	bool ans = false;
	memset(arrays, 0, sizeof(arrays));
	cin >> n >> k;
	for (long long i = 0; i < n; i++)
	{
		cin >> arrays[i];
	}
	for (long long i = 1; i <= n-k+1; i++)
	{
		judge(i);
	}
}
void print() {
	
}
int main(void) {
	long long T = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (T--)
	{
		if (slove())
		{
			print();
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}