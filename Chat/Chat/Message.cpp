#include "Message.h"

Message::Message(string message, string sender)
{
	this->_message = message;
	this->_senderName = sender;
	isprivate = false;
}

Message::Message(string message, string sender, string reciever)
{
	isprivate = true;
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

bool Message::GetBool() const
{
	return this->isprivate;
}

void Message::Showmessage()
{
	cout << this->_senderName <<":" << this->_message << endl;
}
