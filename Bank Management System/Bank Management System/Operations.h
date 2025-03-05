#pragma once
#include <iostream>

using namespace std;
class Operations
{
private:
	string name;
	long double balance;
	int code;
public:
	Operations(string name, int code, long double balance);
	~Operations();
	void deposit(long double amout);
	void withdraw(long double amout);
	void show();
	void registration(string name, int code, long double balance);
};