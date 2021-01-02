#include<iostream>
using namespace std;

// this code will generate balance pair of bracket using given number like this
// here opening and closing bracket pair is always same here it is 3
//((()))
//(()())
//(())()
//()(())
//()()()

void generateBracket(int open, int close, string op)
{
    if(open == 0 && close == 0)
    {
        cout<<op<<endl;
        return;
    }

    if(open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        generateBracket(open-1, close, op1);
    }

    if(open < close)
    {
        string op2 = op;
        op2.push_back(')');
        generateBracket(open, close-1, op2);
    }

}


int main()
{
    generateBracket(3, 3 , "");

    return 0;
}
