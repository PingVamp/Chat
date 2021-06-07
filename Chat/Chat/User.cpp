#include <iostream>
#include "User.h"


User::User(string username, string password, Message* ptrCurrentMessage)
{
    _username = username;
    _password = password;
    this->_ptrCurrentMessage = ptrCurrentMessage;
}

User::User(string username) 
{
    _username = username;
}

User::User(string username, string password)
{
    _username = username;
    _password = password;
}

User::User()
{
}

User::~User()
{
}

string User::getUserName() const
{
    return string(_username);
}

Message* User::getCurrentMessage() const
{
    return this->_ptrCurrentMessage;
}

void User::setUserName(string username)
{
    _username = username;
}

void User::DisplayUserName() const
{
    cout << this->_username << endl;
}

void User::setPassword(string password)
{
    _password = password;
}

void User::setCurrentMessage(Message& ptrCurrentMessage)
{
    this->_ptrCurrentMessage = &ptrCurrentMessage;
}