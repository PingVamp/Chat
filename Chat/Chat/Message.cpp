#include "Message.h"

Message::Message(string message, string senderLogin, string senderName)
{
	this->_message = message;
	this->_senderLogin = senderLogin;
	this->_senderName = senderName;
	isprivate = false;
}

Message::Message(string message, string senderLogin, string senderName, string reciever)
{
	isprivate = true;
	this->_message = message;
	this->_senderLogin = senderLogin;
	this->_senderName = senderName;
	this->_recieverLogin = reciever;
}

string Message::GetSenderName()
{
	return this->_senderLogin;
}

string Message::GetRecieverName()
{
	return this->_recieverLogin;
}

string Message::GetMessage()
{
	return this->_message;
}

bool Message::GetBool() const
{
	return this->isprivate;
}

void Message::Showmessage()
{
	cout << this->_senderName <<":" << this->_message << endl;
}
