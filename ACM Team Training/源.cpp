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
	cout << "******************�����ı��༭��*****************" << endl << endl;
	cout << "\t\t----0.�������--\n";
	cout << "\t\t----1.���ļ�--\n";
	cout << "\t\t----2.��������--\n";
	cout << "\t\t----3.����------\n";
	cout << "\t\t----4.����------\n";
	cout << "\t\t----5.ɾ��------\n";
	cout << "\t\t----6.�滻------\n";
	cout << "\t\t----7.��ʾ����--\n";
	cout << "\t\t----8.����------\n";
	cout << "\t\t----9.�˳�------\n";
	cout << "\n*********************ѡ��************************\n";
	cout << "\n\t\t����ѡ��0-9��";
}
Status Input(art text)
{
	system("cls");
	cout << "�������ı������롱#��������" << endl;
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
	cout << "������ϣ���������" << text->lenth << "���ַ�����" << text->line_num << "�С�" << endl;
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
	cout << "ԭ��Ϊ��";
	cout << text->s << endl;
	cout << "��������Ҫ���ҵ����ݡ�" << endl;
	char pattern[20];
	cin >> pattern;
	int line, num, x, front;
	int is = Index(text->s, pattern, 0, line, num, x);
	if (is == 1)
		cout << "��Ҫ���ҵ��ַ����ڵ�" << line << "��,��" << num << "����" << endl;
	else
		cout << "��Ҫ���ҵ��ַ��������ı��ڡ�" << endl;
	return OK;
}
Status Insert(art text)
{
	system("cls");
	cout << "�����ı�Ϊ��";
	cout << text->s << endl;
	cout << "������Ҫ�����Ԫ�ص��������������м��ÿո��������" << endl;
	int line, num;
	cin >> line >> num;
	cout << "������Ҫ��������ݣ���#������" << endl;
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
	cout << "\n��ǰ�ı���ϢΪ��";
	cout << text->s << endl;
	cout << "�ı�����ɹ�\n";
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
		cout << "�����ı�Ϊ��";
		cout << text->s << endl;
		cout << "������Ҫɾ��������,��#������" << endl;
		fflush(stdin);
		getchar();
		while ((c = getchar()) != '#')
			x[i++] = c;
		flag = Index(text->s, x, 0, line, num, address);
		if (flag == 0)
			cout << "�Ѳ��ҽ���,��Ҫɾ�������ݲ�����,�������������ݡ�" << endl;
	}
	cout << "��Ҫɾ���������ڵ�" << line << "��" << "��" << num << "����" << endl;
	cout << "���롾A��ȷ��ɾ��;���롾B��Ѱ���¸���" << endl;
	fflush(stdin);
	char pd = getchar();
	while (pd == 'b' || pd == 'B')
	{
		Index(text->s, x, address + 1, line, num, address);
		cout << "��Ҫɾ���������ڵ�" << line << "�е�" << num << "����" << endl;
		cout << "���롾A��ȷ��ɾ��;���롾B��Ѱ���¸���" << endl;
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
		cout << "ɾ���ɹ���ɾ���������Ϊ��\n";
		cout << text->s << endl;
	}
	return	0;
}
//void tihuan(char p[], int l)                 //�����滻
//{
//	int t = 0, t1 = 0, i, a, b;
//	char c, th[20], d, d1, bth[20];
//	int i2;
//	system("cls");
//	printf("\n��ǰ�ı���ϢΪ��\n");
//	for (i2 = 0; i2 <= ntext - 1; i2++)
//		printf("%c", p[i2]);
//
//	printf("\n����Ҫ���滻������,��@������");
//
//	fflush(stdin);
//	while ((c = getchar()) != '@')              //tָ�滻ǰ���ݵĳ���
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
//	a = strindex(p, bth, t, l);              //����Ҫ���滻�����ݵ�λ��
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
//		printf("\n���ҵ���βû���ҵ�Ҫ���滻������\n���롾R��������������,���������������˵���\n");
//		l = 0;
//		d = getchar();
//		fflush(stdin);
//	}
//	else
//	{
//		printf("\n\n�Ѿ��ҵ�Ҫ���ҵ������ڵ�%d�е�%d��\n���롾A��������������ͬ����\n�����������������滻����\n��ѡ��", hs, ls + 1);
//		fflush(stdin);
//		l = t + a;
//		char pd;
//		pd = getchar();
//		if (pd != 'a' && pd != 'A')
//		{
//			printf("\n�Ƿ�Ҫ�滻�����ݣ�\nA:�滻�����ݣ��������������˵�\n��ѡ��");
//			fflush(stdin);
//			d1 = getchar();
//			if (d1 == 'a' || d1 == 'A')
//			{
//				printf("\n����Ҫ�滻������,��@������");
//				fflush(stdin);
//				while ((c = getchar()) != '@')              //t1ָ�滻������ݳ���
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
//				if (t == t1)                            //��Ҫ���滻�����ݺ��滻������ݽ��г��ȱȽ�
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
//				printf("�滻�ɹ�");
//				printf("\n��ǰ�ı���ϢΪ��\n");
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
