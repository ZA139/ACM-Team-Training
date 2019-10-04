#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
long long ans[11][1000] = { {0}, {0,1,2,3,4,5,6,7,8,9,-1},{-1},{153,370,371,407,-1},{1634,8208,9474,-1},{54748,92727,93084,-1},{548834,-1},{1741725,4210818,9800817,9926315,-1},{24678050,24678051,88593477,-1},{146511208,472335975,534494836,912985153,-1},{4679307774,-1}};
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < 100; i++)
	{
		if (ans[n][i] != -1)
			printf("%intd\n", ans[n][i]);
		else
			break;
	}
	return 0;
}