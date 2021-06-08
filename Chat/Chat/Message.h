#pragma once

#include <string>
#include <iostream>

using namespace std;

class Message
{
	string _message;	//Поле текста сообщения
	string _senderName;	//Имя отправителя
	string _recieverName;	//Имя получателя
	bool isprivate;		//Приватное ли сообщение
public:
	Message(string message, string sender);	//Конструктор для общих сообщений
	Message(string message, string sender, string reciever);	//Конструктор для дичных сообщений
	~Message() = default;
	string GetSenderName();
	string GetRecieverName();
	string GetMessage();
	bool GetBool() const;	//Возвращает isprivate
	void Showmessage();		//Показывает сообщение
};