#pragma once
#include "Message.h"
#include "User.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//vector<Message> myVector;
//const User& user,

class Chat
{
public:
    void ShowCommon(std::vector<Message>& message); //вывод сообщений из общего чата
    void ShowPrivate(string senderName, string recieverName, std::vector<Message>& message); //вывод личных сообщений
    void ShowAveilableChats(vector<User> users, const User& user); //вывод доступных чатов
};

