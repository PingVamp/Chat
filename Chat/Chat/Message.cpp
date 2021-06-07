#include "Message.h"

Message::Message(string message, string sender)
{
	this->_message = message;
	this->_senderName = sender;
}

Message::Message(string message, string sender, string reciever)
{
	bool isprivate = 1;
	this->_message = message;
	this->_senderName = sender;
	this->_recieverName = reciever;
}

string Message::GetSenderName()
{
	return this->_senderName;
}

string Message::GetRecieverName()
{
	return this->_recieverName;
}

string Message::GetMessage()
{
	return this->_message;
}

void Message::Showmessage()
{
	cout << this->_senderName <<":" << this->_message << endl;
}
