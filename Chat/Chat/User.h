#pragma once

#include <iostream>
#include "Message.h"
#include <string>

using namespace std;

class User
{
private:
    string _username; // ��� ������������
    string _password; // ������
    Message* _ptrCurrentMessage = 0; // ��������� �� ������� ���������

public:
    User(string username, string password, Message& ptrCurrentMessage);
    User(string username);
    User(string username, string password);
    User();

    ~User();

    string getUserName() const;
    Message& getCurrentMessage() const;
    void DisplayUserName() const;
    void setUserName(string username);
    void setPassword(string password);
    void setCurrentMessage(Message& ptrCurrentMessage);
};