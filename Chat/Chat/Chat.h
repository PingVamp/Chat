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
    void ShowCommon(std::vector<Message>& message);
    void ShowPrivate(string senderName, string recieverName, std::vector<Message>& message);
    void Write(Message message);
    void ShowAveilableChats(vector<User> users, const User& user);
};

