#pragma once

#include <string>
#include <iostream>

using namespace std;

class Message
{
	string _message;	//���� ������ ���������
	string _senderName;	//��� �����������
	string _recieverName;	//��� ����������
	bool isprivate;		//��������� �� ���������
public:
	Message(string message, string sender);	//����������� ��� ����� ���������
	Message(string message, string sender, string reciever);	//����������� ��� ������ ���������
	~Message() = default;
	string GetSenderName();
	string GetRecieverName();
	string GetMessage();
	bool GetBool() const;	//���������� isprivate
	void Showmessage();		//���������� ���������
};