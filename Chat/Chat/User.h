#pragma once

#include <iostream>
#include "Message.h"
#include <string>

using namespace std;

class User
{
private:
    string _username; // ќтображаемое им€ пользовател€. ћожет быть одинаковым у разных пользователей
    string _password; // пароль
    string _login;    // логин. ”никален дл€ каждого пользовател€
    Message* _ptrCurrentMessage = 0; // указатель на текущее сообщение

public:
    User(string username, string password, Message* ptrCurrentMessage);
    User(string username);
    User(string username, string login, string password);
    User();

    ~User();

    string getUserName() const; 
    string getPassword() const; 
    string getLogin() const;
    Message* getCurrentMessage() const; 
    void DisplayUserName() const; // вывод на экран имени пользовател€
    void DisplayUserLogin() const;// ¬ывод на экран логина пользовател€
    void setUserName(string username); 
    void setPassword(string password); 
    void setCurrentMessage(Message& ptrCurrentMessage); 
};