// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include "Message.h"
#include "User.h"
#include "Chat.h"
#include <Windows.h>
using namespace std;


vector<Message> messages = {Message("Сообщение от Васи в common","Вася"), Message("Сообщение от Васи Пете","Вася", "Петя")};
vector<User> users = { User("Вася", "123"), User("Петя","321"), User("Олег", "345")};
User* currentuser = nullptr;

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
	regpass = 0;
}

void enter()
{
	string username;
	string password;
	bool enterpass = 0;
	while (enterpass == 0)
	{
		cout << "Введите имя пользователя" << endl;
		cin >> username;
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getUserName() == username)
			{
				cout << "Введите пароль" << endl;
				cin >> password;
				if (users[i].getPassword() == password)
				{
					cout << "Вход успешен" << endl;
					currentuser = &users[i];
					enterpass = 1;
					break;
				}
				else
				{
					cout << "Неверный пароль" << endl;
					break;
				}
			}
			else if ((i + 1 == users.size()))
			{
				cout << "Нет такого пользователя" << endl;
			}
		}
	}
	enterpass = 0;
}


int main()
{
	Chat* chat = new Chat();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	bool exit = 0;
	string reciever;
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
			if (command == "enter")
			{
				enter();
			}
			if (currentuser != nullptr)
			{
				while (command != "exit")
				{
					chat->ShowAveilableChats(users, *currentuser);
					cout << "Введите имя пользователя, которому желаете написать или common для общего чата" << endl;
					cout << "Введите exit для выхода" << endl;
					cin >> command;
					if (command == "exit")
					{
						continue;
					}
					if (command == "common")
					{
						chat->ShowCommon(messages);
						while (command != "endchat")
						{
							cout << "Можете писать сообщения" << endl;
							cout << "Введите endchat для выхода из чата" << endl;
							cin >> command;
							if (command == "endchat")
							{
								break;
							}
							else
							{
								messages.push_back(Message(command, currentuser->getUserName()));
								messages[messages.size() - 1].Showmessage();
							}
						}
					}
					else
					{
						reciever = command;
						chat->ShowPrivate(currentuser->getUserName(), command, messages);
						while (command != "endchat")
						{
							cout << "Можете писать сообщения" << endl;
							cout << "Введите endchat для выхода из чата" << endl;
							cin >> command;
							if (command == "endchat")
							{
								break;
							}
							else
							{
								messages.push_back(Message(command, currentuser->getUserName(), reciever));
								messages[messages.size() - 1].Showmessage();
							}
						}
					}
				}
			}
			command = "";
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

