// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include "Message.h"
#include "User.h"
#include <Windows.h>
using namespace std;


vector<Message> messages;
vector<User> users = { User("Вася", "123"), User{"Петя","321"} };
void registration()
{
	bool regpass = 0;
	string regname;
	string regpassword;
	while (regpass == 0)
	{
		cout << "Регистрация" << endl;
		cout << "Введите желаемое имя пользователя" << endl;
		cin >> regname;
		for (int i = 0; i < users.size(); i++)
		{
			if (regname == users[i].getUserName())
			{
				cout << "Имя занято. Введите другое имя" << endl;
				break;
			}
			else if (i + 1 == users.size())
			{
				cout << "Введите пароль" << endl;
				cin >> regpassword;
				if (regpassword == "")
				{
					cout << "Пароль должен содержать как минимум 1 символ" << endl;
				}
				else
				{
					users.push_back(User(regname, regpassword));
					cout << "Регистрация успешна" << endl;
					regpass = 1;
					break;
				}
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	
	bool exit = 0;

	string command = "";

	//раз раз раз
	while (exit != 1)
	{
		while (command != "exit")
		{
			cout << "Введите enter для входа или register для регистрации" << endl;
			cout << "Для выхода введите exit" << endl;
			cin >> command;
			if (command == "exit")
			{
				exit = 1;
				continue;
			}
			if (command == "register")
			{
				registration();
			}
			for (int i = 0; i < users.size(); i++)
			{
				users[i].DisplayUserName();
			}
		}
	}

	/*messages.push_back(Message("Привет", "Вася"));
	messages.push_back(Message("Хэллоу", "Петя"));
	messages.push_back(Message("Хэллоу", "Петя", "Вася"));
	for (int i = 0; i < messages.size(); i++)
	{
		messages[i].Showmessage();
	}*/

}

