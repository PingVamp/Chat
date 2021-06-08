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

void Chat::ShowPrivate(string senderLogin, string recieverLogin, std::vector<Message>& message) //вывод личных сообщений
{
    size_t size = message.size();
    for (size_t c = 0; c < size; c++)
    {
        if (message[c].GetBool() == true) //проверка того, что сообщение личное
        {
            if (senderLogin == message[c].GetSenderName() && recieverLogin == message[c].GetRecieverName()) // вывод если входящее сообщение для пользователя
            {
                message[c].Showmessage();
            }
            else if (senderLogin == message[c].GetRecieverName() && recieverLogin == message[c].GetSenderName()) // вывод если исходящее от пользователя
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
        if (users[i].getLogin() == user.getLogin()) 
        {
            continue; // пропуск текущего пользователя
        }
        else
        {
            users[i].DisplayUserLogin();; // вывод всех пользователей
        }
    }
}
