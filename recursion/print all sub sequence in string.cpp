#include<iostream>
using namespace std;

void subString(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op2.push_back(s[0]);

    s.erase(s.begin()+0);

    subString(s, op2);
    subString(s, op1);
}

int main()
{
    subString("abcd", "");
    return 0;
}
