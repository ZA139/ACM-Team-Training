#include<stack>
#include<iostream>
using namespace std;
int input[1050], n;
int main(void)
{
	while (scanf("%d",&n)==1)
	{
		if (n == 0) break;
		stack <int> s;
		scanf("%d", &input[1]);
		if (input[1] == 0) break;
		for (int i = 2; i <=n; i++)
		{
			scanf("%d", &input[i]);
		}
		bool ans = true;
		int A = 1, B = 1;
		while (B<=n)
		{
			if (A == input[B])
			{
				A++;
				B++;
			}
			else if (1)
			{
				int a = s.top();
				s.pop();
				B++;
			}
			else if (A <= n)
			{
				s.push(A++);
			}
			else
			{
				ans = false;
				break;
			}
		}
		printf("%s\n", ans ? "Yes" : "No");
	}
	return 0;
}