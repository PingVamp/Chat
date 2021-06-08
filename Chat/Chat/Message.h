#pragma once

#include <string>
#include <iostream>

using namespace std;

class Message
{
	string _message;
	string _senderName;
	string _senderLogin;
	string _recieverLogin;
	bool isprivate;
public:
	Message(string message, string senderLogin, string senderName);
	Message(string message, string senderLogin, string senderName, string reciever);
	~Message() = default;
	string GetSenderName();
	string GetRecieverName();
	string GetMessage();
	bool GetBool() const; // ���������� �������� ���������� isprivate 
	void Showmessage(); // ����� �� ����� ��������� � ������� "��� �����������": "���������"
};