#include <iostream>
#include <string>
#include <vector>
#include "Message.h"
#include "User.h"
#include "Chat.h"
#include <Windows.h>
#include <fstream>

using namespace std;

vector<Message> messages = {Message("Сообщение от Васи в common","Вася"), Message("Сообщение от Васи Пете","Вася", "Петя")}; //Вектор сообщений
vector<User> users = { User("Вася", "123"), User("Петя","321"), User("Олег", "345")}; //Вектор пользователей
User* currentuser = nullptr; //Указатель на активного сейчас пользователя

void registration()		//Функция регистрации новых пользователей
{
	bool regpass = 0;	//Переменная для проверки успешности регистрации
	string regname;		//Ввеодимое пользователем имя
	string regpassword;	//Вводимый пользователем пароль
	while (regpass == 0)	//Пока регистрация не успешна
	{
		cout << "Регистрация" << endl;
		cout << "Введите желаемое имя пользователя" << endl;
		cin >> regname;			//Считываем желаемое пользователем имя
		for (int i = 0; i < users.size(); i++)		//Сверяем его с именами других пользователей
		{
			if (regname == users[i].getUserName())	//Если оно занято, то выходим из цикла
			{
				cout << "Имя занято. Введите другое имя" << endl;
				break;
			}
			else if (i + 1 == users.size())		//Если в векторе пользоваталей нет с таким же именем
			{
				cout << "Введите пароль" << endl;
				cin >> regpassword;				//Считываем желаемый пароль
				if (regpassword == "")			//Если пароль пустой, то жалуемся на это и не даем пройти регистраци
				{
					cout << "Пароль должен содержать как минимум 1 символ" << endl;
				}
				else							//Если пароль содержит хотя бы  символ
				{
					ofstream out("users.txt", std::ios::app);	//Создаем поток для записи в фаил

					if (out.is_open())		//Если получилось открыть фаил
					{
							out << regname << " " << regpassword << std::endl;	//Записываем имя и пароль введенне пользоватлем
					}
					out.close();		//Закрываем поток
					users.push_back(User(regname, regpassword));	//Записываем пользователя в вектор пользователей
					cout << "Регистрация успешна" << endl;
					regpass = 1;		//Указываем успешность регистрации для выхода из цикла
					break;
				}
			}
		}
	}
	regpass = 0;
}

void enter()		//Функция входа зарегестрированных пользователей
{
	string username;	//Переменная для считывагия ввода имени пользователя
	string password;	//Переменная для считывания ввода пароля
	bool enterpass = 0;	//Переменная проверки успешности входа для выхода из цикла
	while (enterpass == 0)		//Пока вход не успешен
	{
		cout << "Введите имя пользователя" << endl;
		cin >> username;		//Считываем имя пользователя
		for (int i = 0; i < users.size(); i++)		//Сверяем его с именами зарегестрированных пользователей
		{
			if (users[i].getUserName() == username)	//Если есть совпадение
			{
				cout << "Введите пароль" << endl;
				cin >> password;					//Считываем пароль
				if (users[i].getPassword() == password)	//Если пароль совпадает с паролем пользователя с данным именем
				{
					cout << "Вход успешен" << endl;
					currentuser = &users[i];		//Делаем данного пользователя активныс
					enterpass = 1;					//Делаем вход успешным
					break;
				}
				else								//Если пароль не верен
				{
					cout << "Неверный пароль" << endl;	//Жалуемся на это и выходим из цикла
					break;
				}
			}
			else if ((i + 1 == users.size()))	//Если мы прошли по всему массиву пользователей и не нашли подхлдящего
			{
				cout << "Нет такого пользователя" << endl;		//Жалуемся на это
			}
		}
	}
	enterpass = 0;
}

int main()
{
	Chat* chat = new Chat();	//Создаем объект чата
	SetConsoleCP(1251);			//Меняем настройки консоли для корректного ввода/вывода
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	bool exit = 0;				//Переменная для проверки желания пользователем выйти
	bool recieverexists = 0;	//Проверка на существование принимающего сообщения с определенным именем
	string inusername;			//Переменная для принятия имени из фаила
	string inpassword;			//Переменная для принятия пароля из фаила
	string reciever;			//Переменная для записи имени принимающего сообщение
	string command = "";		//Переменная для считывания пользовательских комманд
	ifstream in("users.txt");	// окрываем файл для чтения
	if (in.is_open())			//Если открытие успешно
	{
		while (in >> inusername >> inpassword)	//Пока что-либо не сломалось или не дошли до конца фаила, считываем имя и пароль
		{
			users.push_back(User(inusername,inpassword));	//Записываем в вектор пользователя с таким именем и паролем
		}
	}
	in.close();	//Когда закончили с фаилом закрываем поток

	while (exit != 1)	//Пока пользователь не решил выйти из программы
	{
		while (command != "exit")
		{
			cout << "Введите enter для входа или register для регистрации" << endl;
			cout << "Для выхода введите exit" << endl;
			cin >> command;		//Считываем комманду
			if (command == "exit")	//Если пользователь решил выйти, то выходим
			{
				exit = 1;
				continue;
			}
			if (command == "register")	//Если пользователь решил зарегестрироваться - регестрируемся
			{
				registration();
			}
			if (command == "enter")	//Если пользователь решил войти, то входим
			{
				enter();
			}
			if (currentuser != nullptr)	//Если у нас есть активный пользователь
			{
				while (command != "exit")//Пока он не решил выйти
				{
					chat->ShowAveilableChats(users, *currentuser);	//Показываем доступные этому пользователю чаты
					cout << "Введите имя пользователя, которому желаете написать или common для общего чата" << endl;
					cout << "Введите exit для выхода" << endl;
					cin >> command;	//Считываем комманду пользователя
					if (command == "exit")	//Если пользователь решил выйти - выходим
					{
						continue;
					}
					if (command == "common")	//Если пользователь решил войти в общий чат
					{
						chat->ShowCommon(messages);	//Показать общие сообщение
						cout << "Можете писать сообщения" << endl;
						cout << "Введите endchat для выхода из чата" << endl;
						while (command != "endchat")//Пока пользователь не решил выйти из чата
						{
							cin >> command;			//Считываем ввод пользователя
							if (command == "endchat")	//Если команда выход из чата. то выходим
							{
								break;
							}
							else					//Иначе записываем сообщение в вектор и показываем его 
							{
								messages.push_back(Message(command, currentuser->getUserName()));
								messages[messages.size() - 1].Showmessage();
							}
						}
					}
					else				//Если пользователь решил войти в приватный чат
					{
						for (int i = 0; i < users.size(); i++)		//Сверяем его с именами зарегестрированных пользователей
						{
							if (users[i].getUserName() == command)	//Если есть совпадение
							{
								reciever = command;	//Записываем имя того, кому польхователь решил отправить сообщение
								recieverexists = 1;
								break;
							}
							else if ((i + 1 == users.size()))	//Если мы прошли по всему массиву пользователей и не нашли подхлдящего
							{
								cout << "Нет такого пользователя" << endl;		//Жалуемся на это
							}

						}
						if (recieverexists == 1)
						{
							chat->ShowPrivate(currentuser->getUserName(), reciever, messages);	//Показываем сообщения между этими двумя пользователями
							while (command != "endchat") //Пока пользователь не решил выйти из чата
							{
								cout << "Можете писать сообщения" << endl;
								cout << "Введите endchat для выхода из чата" << endl;
								cin >> command;			//Считываем команду пользователя
								if (command == "endchat")	//Если выход - выходим
								{
									break;
								}
								else						//Если не выход, записываем сообщение в вектор сообщений и показываем
								{
									messages.push_back(Message(command, currentuser->getUserName(), reciever));
									messages[messages.size() - 1].Showmessage();
								}
							}
						}
						recieverexists = 0;
					}
				}
			}
			command = "";
		}
	}
}

