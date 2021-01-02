#include<iostream>
using namespace std;

void letterCase(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<endl;
        return ;
    }


    if(isdigit(s[0]))
    {
        op.push_back(s[0]);
        s.erase(s.begin() + 0);
        letterCase(s, op);
    }
    else
    {
        string op1 = op;
        string op2 = op;

        op1.push_back(toupper(s[0]));
        op2.push_back(tolower(s[0]));
        s.erase(s.begin() + 0);

        letterCase(s, op1);
        letterCase(s, op2);
    }


    return ;
}

int main()
{
    letterCase("a1B2", "");
    return 0;
}
