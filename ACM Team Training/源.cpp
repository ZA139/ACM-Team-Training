#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define MAX 1000000
typedef int Status;
typedef struct article {
	char s[MAX];
	int line_num;
	int lenth;
}article, *art;
article wenzhang;
art text = &wenzhang;
void menu()
{
	system("cls");
	cout << "******************简易文本编辑器*****************" << endl << endl;
	cout << "\t\t----0.清空内容--\n";
	cout << "\t\t----1.打开文件--\n";
	cout << "\t\t----2.输入内容--\n";
	cout << "\t\t----3.查找------\n";
	cout << "\t\t----4.插入------\n";
	cout << "\t\t----5.删除------\n";
	cout << "\t\t----6.替换------\n";
	cout << "\t\t----7.显示内容--\n";
	cout << "\t\t----8.保存------\n";
	cout << "\t\t----9.退出------\n";
	cout << "\n*********************选项************************\n";
	cout << "\n\t\t输入选项0-9：";
}
Status Input(art text)
{
	system("cls");
	cout << "请输入文本，输入”#”结束。" << endl;
	int i = 0;
	char ch;
	while ((ch = getchar()) != '#')
	{
		text->s[i] = ch;
		i++;
	}
	text->lenth = i;
	text->line_num = 0;
	for (int j = 0; j < i; j++)
	{
		if (text->s[j] == '\n')
		{
			text->lenth--;
			text->line_num++;
		}
	}
	if (text->s[i - 1] == '\n')
		text->line_num--;
	cout << "输入完毕，您输入了" << text->lenth << "个字符，共" << text->line_num << "行。" << endl;
	return OK;
}
int check(char a[], char b[], int i)
{
	int lb = strlen(b);
	int k = 0;
	for (int j = i; j < i + lb; j++)
	{
		if (a[j] != b[k++])
			return 0;
	}
	return 1;
}
Status Index(char a[], char b[], int front, int& line, int& num, int& x)
{
	int lb = strlen(b);
	int la = strlen(a);
	line = 0; num = 0;
	int flag;
	int i;
	for (i = 0; i < la; i++)
	{
		if (check(a, b, i) == 1)
		{
			flag = i;
			break;
		}
	}
	if (i == la)
		return 0;
	for (int i = 0; i <= flag; i++)
	{
		if (a[i] == '\n')
		{
			line++;
			num = 0;
		}
		num++;
	}
	num--;
	return OK;
}
Status Find(art text)
{
	system("cls");
	cout << "原文为：";
	cout << text->s << endl;
	cout << "请输入您要查找的内容。" << endl;
	char pattern[20];
	cin >> pattern;
	int line, num, x, front;
	int is = Index(text->s, pattern, 0, line, num, x);
	if (is == 1)
		cout << "您要查找的字符串在第" << line << "行,第" << num << "个。" << endl;
	else
		cout << "您要查找的字符串不在文本内。" << endl;
	return OK;
}
Status Insert(art text)
{
	system("cls");
	cout << "您的文本为：";
	cout << text->s << endl;
	cout << "输入您要插入的元素的行数和序数，中间用空格隔开。：" << endl;
	int line, num;
	cin >> line >> num;
	cout << "输入您要插入的内容，以#结束。" << endl;
	fflush(stdin);
	char x[20], c;
	int i = 0;
	while ((c = getchar()) != '#')
		x[i++] = c;
	int lx = strlen(x);
	int ls = strlen(text->s);
	int address = 0;
	int lines = 0, nums = 0;
	for (int j = 0; j < ls; j++)
	{
		nums++;
		if (text->s[j] == '\n')
		{
			lines++;
			nums = 0;
		}
		if (lines == line && nums == num)
		{
			address = j;
			break;
		}
	}
	for (i = ls - 1; i >= address; i--)
	{
		text->s[i + lx] = text->s[i];
	}
	for (i = 0; i < lx; i++)
	{
		text->s[i + address] = x[i];
	}
	//	system("cls");
	cout << "\n当前文本信息为：";
	cout << text->s << endl;
	cout << "文本插入成功\n";
	getchar();
	return 0;
}
Status Delete(art text)
{
	system("cls");
	char c, x[20];
	int i = 0;
	int flag = 0;
	int line, num, address;
	while (flag == 0)
	{
		cout << "您的文本为：";
		cout << text->s << endl;
		cout << "输入您要删除的内容,以#结束：" << endl;
		fflush(stdin);
		getchar();
		while ((c = getchar()) != '#')
			x[i++] = c;
		flag = Index(text->s, x, 0, line, num, address);
		if (flag == 0)
			cout << "已查找结束,您要删除的内容不存在,请重新输入内容。" << endl;
	}
	cout << "你要删除的内容在第" << line << "行" << "第" << num << "列吗？" << endl;
	cout << "输入【A】确定删除;输入【B】寻找下个词" << endl;
	fflush(stdin);
	char pd = getchar();
	while (pd == 'b' || pd == 'B')
	{
		Index(text->s, x, address + 1, line, num, address);
		cout << "你要删除的内容在第" << line << "行第" << num << "列吗？" << endl;
		cout << "输入【A】确定删除;输入【B】寻找下个词" << endl;
		fflush(stdin);
		pd = getchar();
	}
	if (pd == 'a' || pd == 'A')
	{
		int lx = strlen(x);
		for (i = address; i < address + lx; i++)
		{
			text->s[i] = text->s[i + lx];
		}
		cout << "删除成功，删除后的内容为：\n";
		cout << text->s << endl;
	}
	return	0;
}
//void tihuan(char p[], int l)                 //内容替换
//{
//	int t = 0, t1 = 0, i, a, b;
//	char c, th[20], d, d1, bth[20];
//	int i2;
//	system("cls");
//	printf("\n当前文本信息为：\n");
//	for (i2 = 0; i2 <= ntext - 1; i2++)
//		printf("%c", p[i2]);
//
//	printf("\n输入要被替换的内容,以@结束：");
//
//	fflush(stdin);
//	while ((c = getchar()) != '@')              //t指替换前内容的长度
//	{
//		if (c == '@')
//		{
//			break;
//		}
//		else
//		{
//			bth[t] = c;
//			t++;
//
//			continue;
//		}
//	}
//loop:
//	a = strindex(p, bth, t, l);              //查找要被替换的内容的位置
//
//	int hs = 1, ls = 0;
//	for (b = 0; b < a; b++)
//	{
//		ls++;
//		if (p[b] == '\n')
//		{
//			hs++;
//			ls = 0;
//		}
//	}
//
//	if (a == -1)
//	{
//		printf("\n查找到结尾没有找到要被替换的内容\n输入【R】查找其他内容,按其他键返回主菜单键\n");
//		l = 0;
//		d = getchar();
//		fflush(stdin);
//	}
//	else
//	{
//		printf("\n\n已经找到要查找的数据在第%d行第%d列\n输入【A】继续向后查找相同内容\n输入其他键将进行替换操作\n请选择：", hs, ls + 1);
//		fflush(stdin);
//		l = t + a;
//		char pd;
//		pd = getchar();
//		if (pd != 'a' && pd != 'A')
//		{
//			printf("\n是否要替换该内容？\nA:替换给内容；其他键返回主菜单\n请选择：");
//			fflush(stdin);
//			d1 = getchar();
//			if (d1 == 'a' || d1 == 'A')
//			{
//				printf("\n输入要替换的内容,以@结束：");
//				fflush(stdin);
//				while ((c = getchar()) != '@')              //t1指替换后的内容长度
//				{
//					if (c == '@')
//					{
//						break;
//					}
//					else
//					{
//						th[t1] = c;
//						t1++;
//						continue;
//					}
//				}
//				if (t == t1)                            //将要被替换的内容和替换后的内容进行长度比较
//				{
//					for (i = 0; i < t1; i++)
//						p[i + a] = th[i];
//				}
//				else
//				{
//					if (t > t1)
//					{
//						for (i = 0; i < t1; i++)
//						{
//							p[i + a] = th[i];
//						}
//						for (i = a + t1; i < ntext; i++)
//						{
//							p[i] = p[i + t - t1];
//						}
//						ntext = ntext + t1 - t;
//
//					}
//					else
//					{
//						for (i = ntext; i >= a; i--)
//						{
//							p[i + t1 - t] = p[i];
//						}
//						for (i = 0; i < t1; i++)
//						{
//
//							p[i + a] = th[i];
//						}
//						ntext = ntext + t1 - t;
//					}
//				}
//				printf("替换成功");
//				printf("\n当前文本信息为：\n");
//				for (i2 = 0; i2 <= ntext - 1; i2++)
//					printf("%c", p[i2]);
//				getchar();
//				status = 0;
//			}
//		}
//		else
//			goto loop;
//	}
//	if (d == 'r' || d == 'R')
//		tihuan(text, l);
//}
int main()
{
	while (1)
	{
		menu();
		char n;
		cin >> n;
		switch (n)
		{
			//		case '0': cs(text); break;
			//		case '1': dakai(text); break;
		case '2': Input(text); break;
		case '3': Find(text); break;
		case '4': Insert(text); break;
		case '5': Delete(text); break;
			//		case '6': tihuan(text, 0); break;
			//		case '7': dayin(text); break;
			//		case '8': bc(text); break;
			//		case '9': tuichu(status);
		default: break;
		}
		system("pause");
	}
	return 0;
}
