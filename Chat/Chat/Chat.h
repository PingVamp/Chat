#pragma once
#include "Message.h"
#include "User.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<Message> myVector;

class Chat
{
public:
    void Show(const User& user, std::vector<Message>& message);
    void Write(Message message);
};

