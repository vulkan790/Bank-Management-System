#include <iostream>
#include "Operations.h"
#include <regex>
#include <fstream>

using namespace std;
string name{};
int code{};
long double balance{};
Operations account(name, code, balance);
bool IsValidLogin(string login) {
    regex reg("^[a-z0-9_][a-z0-9_\.-]*[a-z0-9_]@([a-z0-9_]+[a-z0-9_-]\.)+[a-z0-9]{2,}$", regex_constants::icase);
    return regex_search(login, reg);
}
bool IsLogged() {
    string username, code, un, cd;
    cout << "Введите логин: ";
    cin >> username;
    cout << "Введите код: ";
    cin >> code;
    fstream read;
    read.open("Account.txt", ios::in);
    read >> un;
    read >> cd;
    if ((username == un) && (code == cd)) {
        return true;
    }
    else {
        return false;
    }
}
int op() {
    double amout;
    cout << "Выберите операцию: " << endl;
    cout << "1) Пополнить баланс " << endl;
    cout << "2) Снять баланс " << endl;
    cout << "3) Посмотреть баланс " << endl;
    int choice;
    cin >> choice;
    do {
        switch (choice) {
        case 1:
            cout << "Введите сумму: ";
            cin >> amout;
            account.deposit(amout);
            break;
        case 2:
            cout << "Введите сумму: ";
            cin >> amout;
            account.withdraw(amout);
            break;
        case 3:
            account.show();
            break;
        default:
            break;
        }
    } while (choice < 1 || choice > 4);
    return op();
}
int main()
{
    setlocale(LC_ALL, "");
    cout << "Выберите операцию: " << endl;
    cout << "1) Регистрация " << endl;
    cout << "2) Авторизация " << endl;
    int choice;
    cin >> choice;
    bool status = IsLogged();
    do {
        switch (choice) {
        case 1:
            account.registration(name, code, balance);
            if (IsValidLogin(name)) {
                cout << "Неправильный логин";
                return 0;
            }
            break;
        case 2:
            if (!status) {
                cout << "Неправильный логин" << endl;
                return 0;
            }
            else {
                cout << "Вы успешно вошли" << endl;
            }
            break;
        default:
            break;
        }
    } while (choice < 1 || choice > 3);
    op();
}