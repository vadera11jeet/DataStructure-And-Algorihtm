#include<iostream>
using namespace std;

// this function is give output like
// ab
// aB
// Ab
// AB

void permutationWithCase(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(s[0]);
    op2.push_back(toupper(s[0]));

    s.erase(s.begin() + 0);

    permutationWithCase(s, op1);
    permutationWithCase(s, op2);
    return;

}

int main()
{
    string s = "abc";
    string op = "";
    permutationWithCase(s, op);

    return 0;
}
