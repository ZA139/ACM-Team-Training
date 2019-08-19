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
char text[MAX] = ""; //文本编辑域 
char name[20] = ""; //文件保存的位置 
int status = 0;//显示是否保存过的状态 
int ntext; //文本编辑的位置
//打开 
void open()
{
	system("cls"); //清除上一次回车的输出
	FILE* fp;
	char pd, ch;
	char name[30];
	int i = 0;
	printf("输入A：确定打开文件(未保存的数据将会丢失) B：返回主菜单");
	fflush(stdin);
	pd = getchar();
	if (pd == 'A' || pd == 'a')
	{
		printf("请输入要打开文件名字:");
		scanf("%s", name);
		while ((fp = fopen(name, "r")) == NULL)
		{
			printf("\n打开文件失败，请重新输入要打开的文件名：");
			scanf("%s", name);
		}
		//	clear(text); 
		while (!feof(fp))//文件结束返回非0（一直读取到结束）
		{
			ch = fgetc(fp);
			text[i] = ch;
			i++;
		}
		text[i] = '\0';                                             //输入结束 
		ntext = i;                                                  //统计字符数目 
		fclose(fp);
		printf("\n文件读取成功\n文件内容为\n");
		print(text);
	}
	if (pd == 'B' || pd == 'b')
		menu();
}
//输入 
void input(char text[])
{
	system("cls");
	printf("请输入内容(输入#结束输入并返回主菜单):\n");
	printf("%s", text);//输出文本中已有内容
	char c;
	int i = ntext;
	fflush(stdin);
	while ((c = getchar()) != '#')//若不是#则继续读取存储
	{
		text[i] = c;
		i++;
		ntext = i;
		//		 continue; 
	}
	int cout = 0, zf = 0, h = 1;
	for (; cout < ntext; cout++)
	{
		zf++;//字符数+1
		if (text[cout] == '\n')//如果读取到的“字符”是换行，字符数-1，行数+1
		{
			h++; zf--;
		}
		if (text[cout] == ' ')//如果读到空格，字符数-1
			zf--;
	}

	printf("统计：文本一共有%d个字符，%d行\n", zf, h);
}
//查找 
void Query(char text[], int l)
{
	system("cls");
	int i, t, a = -1;
	char pattern[20], bd = NULL, pd = NULL;
	printf("原文为：\n");
	print(text);
	printf("请输入您要查找的内容");
	scanf("%s", pattern);
	printf("您查找的内容是:%s\n", pattern);
	t = strlen(pattern);
loop:
	a = strindex(text, pattern, t, l);//返回匹配该子串的第一个字符的序数
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
		printf("查找到结尾没有找到\n输入B将重头查找；任意键返回主菜单");
		l = 0;
		fflush(stdin);
		pd = getchar();
	}
	else
	{
		printf("已经找到在第%d行第%d列，输入B继续查找下一处；任意键返回主菜单", hs, ls);
		fflush(stdin);
		getchar();//吸掉'\n'
		bd = getchar();
		if (bd == 'B' || bd == 'b')
		{
			l = a + 1;//从l+1初再次开始查找
			goto loop;
		}
	}
	if (pd == 'B' || pd == 'b')
	{
		l = 0; Query(text, l);
	}
}
//插入 
void add(char text[], int l)                //向文本中插入内容
{
	bool found = true;
	system("cls");
	int i = 0, t = 0, t2 = 0, a = -1, b;
	char cr[20] = "", pd, x[500], c, d;
	printf("\n当前文本信息为：\n");
	printf("%s", text);
	printf("\n输入您要在哪个内容前插入,以#结束：");
	fflush(stdin);
	getchar();
	while ((c = getchar()) != '#')            //用一个数组接收要插入在哪个内容之前
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
	a = strindex(text, cr, t, l);                  //查找并返回要插入的位置点
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
		printf("\n查找到结尾没有找到插入点,输入B查找其他；按其他键返回菜单:\n");
		l = 0;
		fflush(stdin);
		d = getchar();
		fflush(stdin);
		found = false;
	}
	else
	{
		found = true;
		printf("\n您要插入的位置是第%d行,第%d列之前\n A.不是此位置向后继续找插入点\n B.在此位置插入\n按其他键返回菜单\n请选择：", hs, ls + 1);
		fflush(stdin);
		getchar();
		pd = getchar();
		if (pd == 'a' || pd == 'A')
		{
			l = a + t;                         //l表示要插入的字符串的末尾   a表示匹配到的要插入的位置  t是串的长度 
			goto loop;
		}
		else if (pd == 'b' || pd == 'B')
		{
			printf("\n\n输入您要插入的内容,以#结束：");
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
				text[i + t2] = text[i];                                             //挪位置 
			}
			for (i = 0; i < t2; i++)
			{
				text[i + a] = x[i];                                                //插入 
			}

			ntext = ntext + t2;
			printf("\n当前文本信息为：\n");
			for (i = 0; i <= ntext - 1; i++)
				printf("%c", text[i]);
			printf("\n文本插入成功\n");
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
//删除 
void delete_P(char p[], int l)
{
	bool found = true;
	int i, a = -1, t2 = 0;
	char x[20], px, pd, pdx, c;
	system("cls");
	printf("%s", p);
	printf("\n输入A执行查找删除内容；任意键返回主菜单:");
	fflush(stdin);
	getchar();
	px = getchar();
	if (px == 'a' || px == 'A')
	{
		printf("\ 输入您要删除的内容,以#结束:");
		fflush(stdin);
		while ((c = getchar()) != '#')//用X来存要删除的子串
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
			printf("已查找结束,您要删除的内容不存在\n输入B重新输入要删除的内容;其他键将返回主菜单:");
			l = 0;
			fflush(stdin);
			pdx = getchar();
			found = false;
		}
		else
		{
			found = true;
			printf("你要删除的内容在第%d行第%d列\n 输入A确定删除;输入C寻找下个词;其他键将返回主菜单:", hs, ls);
			fflush(stdin);
			pd = getchar();
			// l=t2+a;
			if (pd == 'a' || pd == 'A')
			{
				for (i = a; i < ntext; i++)
				{
					p[i] = p[i + t2];                                   //前移覆盖删除 
				}
				ntext = ntext - t2;
				printf("删除成功，删除后的内容为：\n%s\n", text);
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

int strindex(char text[], char t[], int i2, int l) //查找要操作的数据的位置 
{
	int i1 = l, j = 0;
	while (i1 < ntext&&j < i2)
	{
		if (text[i1] == t[j]) //继续匹配下一个字符
		{
			j++;
			i1++; //主串和子串依次匹配下一个字符
		}
		else //主串、子串指针回溯重新开始下一次匹配
		{
			i1 = i1 - j + 1; //主串从下一个位置开始匹配
			j = 0; //子串从头开始匹配
		}
	}
	if (j >= i2)
	{
		return(i1 - i2);
	} //返回匹配的第一个字符的下标
	else
		return(-1);//模式匹配不成功
}
//替换 
void replace(char p[], int l)                //内容替换
{
	bool found = true;
	int t = 0, t1 = 0, i, a, b;
	char c, th[20], d, d1, bth[20];
	int i2;
	system("cls");
	printf("\n当前文本信息为：\n");
	for (i2 = 0; i2 <= ntext - 1; i2++)
		printf("%c", p[i2]);
	printf("\n输入要被替换的内容,以#结束：");
	fflush(stdin);
	getchar();
	while ((c = getchar()) != '#')              //t指替换前内容的长度
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
	a = strindex(p, bth, t, l);              //查找要被替换的内容的位置

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
		printf("\n查找到结尾没有找到要被替换的内容\n输入B查找其他内容,按其他键返回主菜单键\n");
		l = 0;
		d = getchar();
		fflush(stdin);
		found = false;
	}
	else
	{
		found = true;
		printf("\n\n已经找到要查找的数据在第%d行第%d列\n输入A继续向后查找相同内容\n输入其他键将进行替换操作\n请选择：", hs, ls + 1);
		fflush(stdin);
		l = t + a;
		char pd;
		pd = getchar();
		if (pd != 'a'&&pd != 'A')
		{
			printf("\n是否要替换该内容？\nA:替换给内容；其他键返回主菜单\n请选择：");
			fflush(stdin);
			d1 = getchar();
			if (d1 == 'a' || d1 == 'A')
			{
				printf("\n输入要替换的内容,以#结束：");
				fflush(stdin);
				while ((c = getchar()) != '#')              //t1指替换后的内容长度
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
				if (t == t1)                            //要被替换的内容和替换后的内容长度相等，则直接覆盖
				{
					for (i = 0; i < t1; i++)
						p[i + a] = th[i];
				}
				else
				{
					if (t > t1)//小则前移，大则后移（a为要替换的字符串的数字下标）
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
				printf("替换成功");
				printf("\n当前文本信息为：\n\n");
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
//打印 
void print(char text[])
{
	system("cls");
	printf("现在文本的内容为：\n");
	printf("%s\n", text);
	int hs = 1, i;
	for (i = 0; i < ntext; i++)
	{
		if (text[i] == '\n')
		{
			hs++;
		}
	}
	printf("\n文本共有%d行\n", hs);
}
//保存 
void save(char text[])
{
	system("cls");
	FILE *fp;                         //声明文件指针 
	char pd;
	char tmp;
	int i;
	printf("\n输入A保存;任意键返回主菜单不保存\n");
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
			printf("\n 请输入保存文件名:");
			scanf("%s", name);
		}
		while ((fp = fopen(name, "w+")) == NULL)                   //w+以纯文本方式读写 

		{
			printf("文件不存在，请重新输入文件名：");
			scanf("%s", name);
		}
		printf("\nA:确定;B:取消：");
		while (scanf("%c", &tmp) != EOF)
		{
			if (tmp == 'A' || tmp == 'a')
			{
				for (i = 0; i < ntext; i++)
					fprintf(fp, "%c", text[i]);
				fclose(fp);
				status = 1;
				printf("\n文件保存成功\n");
				break;
			}
			if (tmp == 'B' || tmp == 'b')
			{
				break;
			}
		}
	}
}
//清空 
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

//退出 
void exit_P(int status)
{
	char pd;
	if (status)
		exit(0);
	else
		printf("还未保存文件，确定退出？(Q.直接退出；Y.保存后退出");
	fflush(stdin);
	pd = getchar();
	if (!(pd == 'Q' || pd == 'q'))
		save(text);
	exit(0);
}
//菜单 
void menu()
{
	system("cls");
	time_t timep;
	time(&timep);
	printf("%s", ctime(&timep));//ctime获取系统时间
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\t\t\t\t 欢迎使用文本编辑器!\n");
	printf("\n\n\n\n\n\n\n\n\npress Enter to continue...\n");
	getchar();
loop:
	system("cls");
	printf("\n\n\n\n\t\t******************简易文本编辑器*****************\n\n");
	printf("\t\t\t\t----1.打开文件--\n");
	if (ntext == 0) {
		printf("\t\t\t\t----2.输入内容--\n");
	}
	else {
		printf("\t\t\t\t----2.继续输入--\n");
	}
	printf("\t\t\t\t----3.查找------\n");
	printf("\t\t\t\t----4.插入------\n");
	printf("\t\t\t\t----5.删除------\n");
	printf("\t\t\t\t----6.替换------\n");
	printf("\t\t\t\t----7.显示内容--\n");
	printf("\t\t\t\t----8.保存------\n");
	printf("\t\t\t\t----9.退出------\n");
	printf("\n\t\t*********************选项************************\n");
	printf("\n\t\t\t\t输入选项1-9: ");
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
		printf("\n输入有误，请重新输入:");
		scanf("%d", &n);
	}
	system("pause");
	goto loop;
}

int main()
{
	menu();
}