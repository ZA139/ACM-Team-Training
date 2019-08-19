#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h> 
#define MAX 10000  
#define _CRT_SECURE_NO_DEPRECATE  
void menu();
void open(char text[]);
void input(char text[]);
void Query(char text[], int l);
void add(char text[], int l);
void delete_P(char p[], int l);
void replace(char text[], int l);
void print(char text[]);
void save(char text[]);
void exit_P(int status);
int strindex(char text[], char t[], int i2, int l);
void clear(char text[]);
char text[MAX] = ""; //�ı��༭�� 
char name[20] = ""; //�ļ������λ�� 
int status = 0;//��ʾ�Ƿ񱣴����״̬ 
int ntext; //�ı��༭��λ��
//�� 
void open()
{
	system("cls"); //�����һ�λس������
	FILE* fp;
	char pd, ch;
	char name[30];
	int i = 0;
	printf("����A��ȷ�����ļ�(δ��������ݽ��ᶪʧ) B���������˵�");
	fflush(stdin);
	pd = getchar();
	if (pd == 'A' || pd == 'a')
	{
		printf("������Ҫ���ļ�����:");
		scanf("%s", name);
		while ((fp = fopen(name, "r")) == NULL)
		{
			printf("\n���ļ�ʧ�ܣ�����������Ҫ�򿪵��ļ�����");
			scanf("%s", name);
		}
		//	clear(text); 
		while (!feof(fp))//�ļ��������ط�0��һֱ��ȡ��������
		{
			ch = fgetc(fp);
			text[i] = ch;
			i++;
		}
		text[i] = '\0';                                             //������� 
		ntext = i;                                                  //ͳ���ַ���Ŀ 
		fclose(fp);
		printf("\n�ļ���ȡ�ɹ�\n�ļ�����Ϊ\n");
		print(text);
	}
	if (pd == 'B' || pd == 'b')
		menu();
}
//���� 
void input(char text[])
{
	system("cls");
	printf("����������(����#�������벢�������˵�):\n");
	printf("%s", text);//����ı�����������
	char c;
	int i = ntext;
	fflush(stdin);
	while ((c = getchar()) != '#')//������#�������ȡ�洢
	{
		text[i] = c;
		i++;
		ntext = i;
		//		 continue; 
	}
	int cout = 0, zf = 0, h = 1;
	for (; cout < ntext; cout++)
	{
		zf++;//�ַ���+1
		if (text[cout] == '\n')//�����ȡ���ġ��ַ����ǻ��У��ַ���-1������+1
		{
			h++; zf--;
		}
		if (text[cout] == ' ')//��������ո��ַ���-1
			zf--;
	}

	printf("ͳ�ƣ��ı�һ����%d���ַ���%d��\n", zf, h);
}
//���� 
void Query(char text[], int l)
{
	system("cls");
	int i, t, a = -1;
	char pattern[20], bd = NULL, pd = NULL;
	printf("ԭ��Ϊ��\n");
	print(text);
	printf("��������Ҫ���ҵ�����");
	scanf("%s", pattern);
	printf("�����ҵ�������:%s\n", pattern);
	t = strlen(pattern);
loop:
	a = strindex(text, pattern, t, l);//����ƥ����Ӵ��ĵ�һ���ַ�������
	//	if (a!=-1) 
	//	{ 
	//		l=a+t; 
	//	} 
	int hs = 1, ls = 0;
	for (i = 0; i <= a; i++)
	{
		ls++;
		if (text[i] == '\n')
		{
			hs++; ls = 0;
		}
	}
	if (a == -1)
	{
		printf("���ҵ���βû���ҵ�\n����B����ͷ���ң�������������˵�");
		l = 0;
		fflush(stdin);
		pd = getchar();
	}
	else
	{
		printf("�Ѿ��ҵ��ڵ�%d�е�%d�У�����B����������һ����������������˵�", hs, ls);
		fflush(stdin);
		getchar();//����'\n'
		bd = getchar();
		if (bd == 'B' || bd == 'b')
		{
			l = a + 1;//��l+1���ٴο�ʼ����
			goto loop;
		}
	}
	if (pd == 'B' || pd == 'b')
	{
		l = 0; Query(text, l);
	}
}
//���� 
void add(char text[], int l)                //���ı��в�������
{
	bool found = true;
	system("cls");
	int i = 0, t = 0, t2 = 0, a = -1, b;
	char cr[20] = "", pd, x[500], c, d;
	printf("\n��ǰ�ı���ϢΪ��\n");
	printf("%s", text);
	printf("\n������Ҫ���ĸ�����ǰ����,��#������");
	fflush(stdin);
	getchar();
	while ((c = getchar()) != '#')            //��һ���������Ҫ�������ĸ�����֮ǰ
	{
		if (c == '#')
		{
			break;
		}
		else
		{
			cr[t] = c;
			t++;
			continue;
		}
	}
loop:
	a = strindex(text, cr, t, l);                  //���Ҳ�����Ҫ�����λ�õ�
	int hs = 1, ls = 0;
	for (b = 0; b < a; b++)
	{
		ls++;
		if (text[b] == '\n')
		{
			hs++;
			ls = 0;
		}
	}
	if (a == -1)
	{
		printf("\n���ҵ���βû���ҵ������,����B���������������������ز˵�:\n");
		l = 0;
		fflush(stdin);
		d = getchar();
		fflush(stdin);
		found = false;
	}
	else
	{
		found = true;
		printf("\n��Ҫ�����λ���ǵ�%d��,��%d��֮ǰ\n A.���Ǵ�λ���������Ҳ����\n B.�ڴ�λ�ò���\n�����������ز˵�\n��ѡ��", hs, ls + 1);
		fflush(stdin);
		getchar();
		pd = getchar();
		if (pd == 'a' || pd == 'A')
		{
			l = a + t;                         //l��ʾҪ������ַ�����ĩβ   a��ʾƥ�䵽��Ҫ�����λ��  t�Ǵ��ĳ��� 
			goto loop;
		}
		else if (pd == 'b' || pd == 'B')
		{
			printf("\n\n������Ҫ���������,��#������");
			fflush(stdin);
			while ((c = getchar()) != '#')
			{
				if (c == '#')
				{
					break;
				}
				else
				{
					x[t2] = c;
					t2++;
					continue;
				}
			}
			for (i = ntext; i >= a; i--)
			{
				text[i + t2] = text[i];                                             //Ųλ�� 
			}
			for (i = 0; i < t2; i++)
			{
				text[i + a] = x[i];                                                //���� 
			}

			ntext = ntext + t2;
			printf("\n��ǰ�ı���ϢΪ��\n");
			for (i = 0; i <= ntext - 1; i++)
				printf("%c", text[i]);
			printf("\n�ı�����ɹ�\n");
			fflush(stdin);
			getchar();
		}
	}
	if (!found) {
		if (d == 'r' || d == 'R')
		{
			l = 0;
			add(text, l);
		}
	}
	status = 0;
}
//ɾ�� 
void delete_P(char p[], int l)
{
	bool found = true;
	int i, a = -1, t2 = 0;
	char x[20], px, pd, pdx, c;
	system("cls");
	printf("%s", p);
	printf("\n����Aִ�в���ɾ�����ݣ�������������˵�:");
	fflush(stdin);
	getchar();
	px = getchar();
	if (px == 'a' || px == 'A')
	{
		printf("\ ������Ҫɾ��������,��#����:");
		fflush(stdin);
		while ((c = getchar()) != '#')//��X����Ҫɾ�����Ӵ�
		{
			if (c == '#')
			{
				break;
			}
			else
			{
				x[t2] = c;
				t2++;
				continue;
			}
		}
	loop:
		a = strindex(p, x, t2, l);
		int hs = 1, ls = 0;
		for (i = 0; i <= a; i++)
		{
			ls++;
			if (p[i] == '\n')
			{
				hs++; ls = 0;
			}
		}
		if (a == -1)
		{
			printf("�Ѳ��ҽ���,��Ҫɾ�������ݲ�����\n����B��������Ҫɾ��������;���������������˵�:");
			l = 0;
			fflush(stdin);
			pdx = getchar();
			found = false;
		}
		else
		{
			found = true;
			printf("��Ҫɾ���������ڵ�%d�е�%d��\n ����Aȷ��ɾ��;����CѰ���¸���;���������������˵�:", hs, ls);
			fflush(stdin);
			pd = getchar();
			// l=t2+a;
			if (pd == 'a' || pd == 'A')
			{
				for (i = a; i < ntext; i++)
				{
					p[i] = p[i + t2];                                   //ǰ�Ƹ���ɾ�� 
				}
				ntext = ntext - t2;
				printf("ɾ���ɹ���ɾ���������Ϊ��\n%s\n", text);
			}
			else if (pd == 'b' || pd == 'B')
				goto loop;
		}
		if (!found) {
			if (pdx == 'r' || pdx == 'R')
				delete_P(text, l);
		}
	}
}

int strindex(char text[], char t[], int i2, int l) //����Ҫ���������ݵ�λ�� 
{
	int i1 = l, j = 0;
	while (i1 < ntext&&j < i2)
	{
		if (text[i1] == t[j]) //����ƥ����һ���ַ�
		{
			j++;
			i1++; //�������Ӵ�����ƥ����һ���ַ�
		}
		else //�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
		{
			i1 = i1 - j + 1; //��������һ��λ�ÿ�ʼƥ��
			j = 0; //�Ӵ���ͷ��ʼƥ��
		}
	}
	if (j >= i2)
	{
		return(i1 - i2);
	} //����ƥ��ĵ�һ���ַ����±�
	else
		return(-1);//ģʽƥ�䲻�ɹ�
}
//�滻 
void replace(char p[], int l)                //�����滻
{
	bool found = true;
	int t = 0, t1 = 0, i, a, b;
	char c, th[20], d, d1, bth[20];
	int i2;
	system("cls");
	printf("\n��ǰ�ı���ϢΪ��\n");
	for (i2 = 0; i2 <= ntext - 1; i2++)
		printf("%c", p[i2]);
	printf("\n����Ҫ���滻������,��#������");
	fflush(stdin);
	getchar();
	while ((c = getchar()) != '#')              //tָ�滻ǰ���ݵĳ���
	{
		if (c == '#')
		{
			break;
		}
		else
		{
			bth[t] = c;
			t++;
			continue;
		}
	}
loop:
	a = strindex(p, bth, t, l);              //����Ҫ���滻�����ݵ�λ��

	int hs = 1, ls = 0;
	for (b = 0; b < a; b++)
	{
		ls++;
		if (p[b] == '\n')
		{
			hs++;
			ls = 0;
		}
	}
	if (a == -1)
	{
		printf("\n���ҵ���βû���ҵ�Ҫ���滻������\n����B������������,���������������˵���\n");
		l = 0;
		d = getchar();
		fflush(stdin);
		found = false;
	}
	else
	{
		found = true;
		printf("\n\n�Ѿ��ҵ�Ҫ���ҵ������ڵ�%d�е�%d��\n����A������������ͬ����\n�����������������滻����\n��ѡ��", hs, ls + 1);
		fflush(stdin);
		l = t + a;
		char pd;
		pd = getchar();
		if (pd != 'a'&&pd != 'A')
		{
			printf("\n�Ƿ�Ҫ�滻�����ݣ�\nA:�滻�����ݣ��������������˵�\n��ѡ��");
			fflush(stdin);
			d1 = getchar();
			if (d1 == 'a' || d1 == 'A')
			{
				printf("\n����Ҫ�滻������,��#������");
				fflush(stdin);
				while ((c = getchar()) != '#')              //t1ָ�滻������ݳ���
				{
					if (c == '#')
					{
						break;
					}
					else
					{
						th[t1] = c; t1++; continue;
					}
				}
				if (t == t1)                            //Ҫ���滻�����ݺ��滻������ݳ�����ȣ���ֱ�Ӹ���
				{
					for (i = 0; i < t1; i++)
						p[i + a] = th[i];
				}
				else
				{
					if (t > t1)//С��ǰ�ƣ�������ƣ�aΪҪ�滻���ַ����������±꣩
					{
						for (i = 0; i < t1; i++)
						{
							p[i + a] = th[i];
						}
						for (i = a + t1; i < ntext; i++)
						{
							p[i] = p[i + t - t1];
						}
						ntext = ntext + t1 - t;
					}
					else
					{
						for (i = ntext; i >= a; i--)
						{
							p[i + t1 - t] = p[i];
						}
						for (i = 0; i < t1; i++)
						{
							p[i + a] = th[i];
						}
						ntext = ntext + t1 - t;
					}
				}
				printf("�滻�ɹ�");
				printf("\n��ǰ�ı���ϢΪ��\n\n");
				for (i2 = 0; i2 <= ntext - 1; i2++)
					printf("%c", p[i2]);
				getchar();
				status = 0;
			}
		}
		else
			goto loop;
	}
	if (!found)
	{
	if (d == 'b' || d == 'B')
		replace(text, l);
	}
}
//��ӡ 
void print(char text[])
{
	system("cls");
	printf("�����ı�������Ϊ��\n");
	printf("%s\n", text);
	int hs = 1, i;
	for (i = 0; i < ntext; i++)
	{
		if (text[i] == '\n')
		{
			hs++;
		}
	}
	printf("\n�ı�����%d��\n", hs);
}
//���� 
void save(char text[])
{
	system("cls");
	FILE *fp;                         //�����ļ�ָ�� 
	char pd;
	char tmp;
	int i;
	printf("\n����A����;������������˵�������\n");
	fflush(stdin);
	pd = getchar();
	if (!(pd == 'A' || pd == 'a'))
	{
		menu();
	}
	else
	{
		if (name[20] == NULL)
		{
			printf("\n �����뱣���ļ���:");
			scanf("%s", name);
		}
		while ((fp = fopen(name, "w+")) == NULL)                   //w+�Դ��ı���ʽ��д 

		{
			printf("�ļ������ڣ������������ļ�����");
			scanf("%s", name);
		}
		printf("\nA:ȷ��;B:ȡ����");
		while (scanf("%c", &tmp) != EOF)
		{
			if (tmp == 'A' || tmp == 'a')
			{
				for (i = 0; i < ntext; i++)
					fprintf(fp, "%c", text[i]);
				fclose(fp);
				status = 1;
				printf("\n�ļ�����ɹ�\n");
				break;
			}
			if (tmp == 'B' || tmp == 'b')
			{
				break;
			}
		}
	}
}
//��� 
void clear(char text[])
{
	int i;
	for (i = 0; i < ntext; i++)
	{
		text[i] = '\0';
	}
	ntext = 0;
	status = 0;
}

//�˳� 
void exit_P(int status)
{
	char pd;
	if (status)
		exit(0);
	else
		printf("��δ�����ļ���ȷ���˳���(Q.ֱ���˳���Y.������˳�");
	fflush(stdin);
	pd = getchar();
	if (!(pd == 'Q' || pd == 'q'))
		save(text);
	exit(0);
}
//�˵� 
void menu()
{
	system("cls");
	time_t timep;
	time(&timep);
	printf("%s", ctime(&timep));//ctime��ȡϵͳʱ��
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\t\t\t\t ��ӭʹ���ı��༭��!\n");
	printf("\n\n\n\n\n\n\n\n\npress Enter to continue...\n");
	getchar();
loop:
	system("cls");
	printf("\n\n\n\n\t\t******************�����ı��༭��*****************\n\n");
	printf("\t\t\t\t----1.���ļ�--\n");
	if (ntext == 0) {
		printf("\t\t\t\t----2.��������--\n");
	}
	else {
		printf("\t\t\t\t----2.��������--\n");
	}
	printf("\t\t\t\t----3.����------\n");
	printf("\t\t\t\t----4.����------\n");
	printf("\t\t\t\t----5.ɾ��------\n");
	printf("\t\t\t\t----6.�滻------\n");
	printf("\t\t\t\t----7.��ʾ����--\n");
	printf("\t\t\t\t----8.����------\n");
	printf("\t\t\t\t----9.�˳�------\n");
	printf("\n\t\t*********************ѡ��************************\n");
	printf("\n\t\t\t\t����ѡ��1-9: ");
	int n;
	scanf("%d", &n);
	if (n >= 0 && n <= 9)
	{
		switch (n)
		{
		case 1: open(); break;
		case 2: input(text); break;
		case 3: Query(text, 0); break;
		case 4: add(text, 1); break;
		case 5: delete_P(text, 0); break;
		case 6: replace(text, 0); break;
		case 7: print(text); break;
		case 8: save(text); break;
		case 9: exit_P(status);
		default: break;
		}
	}
	else
	{
		printf("\n������������������:");
		scanf("%d", &n);
	}
	system("pause");
	goto loop;
}

int main()
{
	menu();
}