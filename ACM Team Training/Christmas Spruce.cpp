//#include<iostream>
//#include<cstring>
//#include<stack>
//#include<algorithm>
//using namespace std;
//int tree[1005],nodes[1005];
//stack<int>s;
//int main(void)
//{
//	memset(tree, 0, sizeof(tree));
//	memset(nodes, 0, sizeof(tree));
//	bool ans = true;
//	int n,a;
//	cin >> n;
//	while (--n)
//	{
//		cin >> a;
//		tree[a]++;
//	}
//	int len = s.size();
//	/*for (int i = 0; i < len; i++)
//	{
//		if (tree[s.top()]<3)
//		{
//			ans = false;
//			break;
//		}
//		else
//		{
//			s.pop();
//		}*/
//	//}
//	for (int i = 2; i < 1000; i++)
//	{
//
//	}
//	if (ans)
//	{
//		cout << "Yes" << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//	return 0;
//}

#include<iostream>

using namespace std;

int main()

{

	int n, a[1010], vis[1010], i;

	while (cin >> n)

	{

		memset(vis, 0, sizeof(vis));

		for (i = 2; i <= n; i++)

			cin >> a[i], vis[a[i]] = 1;///vis�����Ƿ�Ҷ�ӽڵ�Ϊ1

		for (i = n; i >= 1; i--)

			if (!vis[i]) ///��Ҷ�ӽڵ�ʹ����Ǹ����ڵ�����������Ҷ�Ӻ���

				vis[a[i]]++;  ///��Ҷ�ӽڵ��Ҷ�Ӹ���++

		for (i = 1; i <= n; i++)

			if (vis[i] && vis[i] < 4) ///��ɨ��Ҷ�ӽڵ㣩С������Ҷ�Ӻ��ӣ����Ҳ���Ҷ�ӽڵ㣬��ʼ��Ϊ1�ģ�����<4

				break;

		if (i > n)

			puts("Yes");

		else   puts("No");

	}

	return 0;

}
