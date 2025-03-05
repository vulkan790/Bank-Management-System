#include "Operations.h"
#include <iostream>
#include <fstream>

using namespace std;

Operations::Operations(string name, int code, long double balance) : name(name), code(code), balance(balance){}
Operations::~Operations() {}
void Operations::deposit(long double amout)
{
	if (amout > 0) {
		balance += amout;
		fstream in;
		in.open("Balance.txt", ios::out);
		in << balance;
		in.close();
	}
	else {
		cout << "�� ��������� ����� ������!";
	}
}
void Operations::withdraw(long double amout)
{
	if (amout <= balance) {
		balance -= amout;
		fstream in;
		in.open("Balance.txt", ios::out);
		in << balance;
		in.close();
	}
	else {
		cout << "������������";
	}
}
void Operations::show()
{
	fstream in;
	in.open("Balance.txt", ios::in);
	in >> balance;
	cout << "�������: " << name << "\n������: " << balance << endl;
}
void Operations::registration(string name, int code, long double balance)
{
	cout << "������� �����: " << endl;
	cin >> name;
	cout << "������� ���: " << endl;
	cin >> code;
	fstream read;
	read.open("Account.txt", ios::out);
	read << name << endl << code << endl;
	read.close();
}