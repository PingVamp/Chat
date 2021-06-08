#include "Chat.h"
#include <iostream>

void Chat::ShowCommon(std::vector<Message>& message) //����� ��������� �� ������ ����
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
            cout << "��� ���������" << endl;
        }
    }
}

void Chat::ShowPrivate(string senderLogin, string recieverLogin, std::vector<Message>& message) //����� ������ ���������
{
    size_t size = message.size();
    for (size_t c = 0; c < size; c++)
    {
        if (message[c].GetBool() == true) //�������� ����, ��� ��������� ������
        {
            if (senderLogin == message[c].GetSenderName() && recieverLogin == message[c].GetRecieverName()) // ����� ���� �������� ��������� ��� ������������
            {
                message[c].Showmessage();
            }
            else if (senderLogin == message[c].GetRecieverName() && recieverLogin == message[c].GetSenderName()) // ����� ���� ��������� �� ������������
            {
                message[c].Showmessage();
            }
        }
        else if (c + 1 == size)
        {
            cout << "��� ���������" << endl;
        }
    }
}

void Chat::ShowAveilableChats(vector<User> users, const User& user) // ����� ��������� �����
{
    cout << "common" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == user.getLogin()) 
        {
            continue; // ������� �������� ������������
        }
        else
        {
            users[i].DisplayUserLogin();; // ����� ���� �������������
        }
    }
}
