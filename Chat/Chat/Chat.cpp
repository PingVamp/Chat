#include "Chat.h"
#include <iostream>

void Chat::ShowCommon(std::vector<Message>& message) //вывод сообщений из общего чата
{
    size_t size = message.size();
    for (size_t c = 0; c < size; c++)
    {
        if (message[c].GetBool() == false)
        {
            message[c].Showmessage();
        }
        else if (c+1 == size)
        {
            cout << "Нет сообщений" << endl;
        }
    }
}

void Chat::ShowPrivate(string senderName, string recieverName, std::vector<Message>& message) //вывод личных сообщений
{
    size_t size = message.size();
    for (size_t c = 0; c < size; c++)
    {
        if (message[c].GetBool() == true) //проверка того, что сообщение личное
        {
            if (senderName == message[c].GetSenderName() && recieverName == message[c].GetRecieverName()) // вывод если входящее сообщение для пользователя
            {
                message[c].Showmessage();
            }
            else if (senderName == message[c].GetRecieverName() && recieverName == message[c].GetSenderName()) // вывод если исходящее от пользователя
            {
                message[c].Showmessage();
            }
        }
        else if (c + 1 == size)
        {
            cout << "Нет сообщений" << endl;
        }
    }
}

void Chat::ShowAveilableChats(vector<User> users, const User& user) // вывод доступных чатов
{
    cout << "common" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserName() == user.getUserName()) 
        {
            continue; // пропуск текущего пользователя
        }
        else
        {
            users[i].DisplayUserName(); // вывод всех пользователей
        }
    }
}
