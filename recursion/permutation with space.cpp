#include<iostream>
using namespace std;

// this function gives output like this
// here '_' means space
// a_b_c
// ab_c
// a_bc
// abc


void permutaionWithSpace(string s, string op)
{
    if(s.length() == 0)
    {
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op;

//   this function is take char as argument not string
    op1.push_back(' ');
    op1.push_back(s[0]);
    op2.push_back(s[0]);

    s.erase(s.begin() + 0);

    permutaionWithSpace(s, op1);
    permutaionWithSpace(s, op2);

}


int main()
{
    string s = "abc";
    string op = "";

    op.push_back(s[0]);
    s.erase(s.begin() + 0);

    permutaionWithSpace(s, op);

    return 0;
}
