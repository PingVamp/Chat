// Chat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include "Message.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	vector<Message> messages;
	messages.push_back(Message("Привет", "Вася"));
	messages.push_back(Message("Хэллоу", "Петя"));
	messages.push_back(Message("Хэллоу", "Петя", "Вася"));
	for (int i = 0; i < messages.size(); i++)
	{
		messages[i].Showmessage();
	}

}


