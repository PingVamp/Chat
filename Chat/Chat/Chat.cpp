#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> myVector;

class Chat
{
public:
    void ShowCommon()
    {
        vector<string>::const_iterator it;
        it = myVector.begin();
        while (it != myVector.end())
        {
            cout << *it << endl;
            ++it;
        }
    }
    void WriteCommon(string str)
    {
        myVector.push_back(str);
    }

    //void ShowPrivate() {}
    //void WritePrivate() {}
};

auto main() -> int
{
    Chat chat;
    chat.WriteCommon("Hello");
    chat.WriteCommon("World!");
    chat.ShowCommon();


    return 0;
}

