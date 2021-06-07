#include "Chat.h"
#include <iostream>

void Chat::Show(const User& user, std::vector<Message>& message)
{
    size_t size = message.size();
    for (size_t c = 0; c < size; c++)
    {
        if (message[c].GetRecieverName() == user.getUserName() || message[c].GetBool() == 0)
        {
            Message::Showmessage;
        }
        else
        {
            cout << "Нет сообщений" << endl;
        }
    }
}

void Chat::Write(Message message)
{
    myVector.push_back(message);
}