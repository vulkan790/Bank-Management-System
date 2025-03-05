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
		cout << "Вы пытаетесь снять баланс!";
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
		cout << "Недостаточно";
	}
}
void Operations::show()
{
	fstream in;
	in.open("Balance.txt", ios::in);
	in >> balance;
	cout << "Аккаунт: " << name << "\nБаланс: " << balance << endl;
}
void Operations::registration(string name, int code, long double balance)
{
	cout << "Введите логин: " << endl;
	cin >> name;
	cout << "Введите код: " << endl;
	cin >> code;
	fstream read;
	read.open("Account.txt", ios::out);
	read << name << endl << code << endl;
	read.close();
}