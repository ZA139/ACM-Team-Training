#include<iostream>
using namespace std;
void save() {
	FILE *fp;
	char a[20];
	int age;
	cout << "name" << endl;
	cin >> a;
	fp = fopen(a, "w");
	fprintf(fp, "%s", a);
	cout << "age" << endl;
	cin >> age;
	fprintf(fp, "\n%d", age);
	fclose(fp);
	return;
}
void load() {
	char a[20];
	char b[20];
	FILE *fp;
	int age;
	cout << "Input the name want load:" << endl;
	cin >> a;
	fp = fopen(a, "r");
	fscanf(fp, "%s", b);
	fscanf(fp, "%d", &age);
	cout << a << endl << age << endl;
	fclose(fp);
	return;
}
int main(void) {
	save();
	load();
		return 0;
}