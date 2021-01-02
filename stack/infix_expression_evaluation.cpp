#include<iostream>
#include<stack>
using namespace std;

int prec(char op)
{
    if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    return 0;
}

void evalution(string str)
{
    stack <int> op;
    stack <char> oprand;

    for(int i = 0; i < str.length(); i++)
    {
        if(isdigit(str[i]))
        {
            int value = 0;
            while(i < str.length() && isdigit(str[i])){
                value = (value * 10) + (str[i] - '0');
                i++;
            }
            op.push(value);
        }
        else if (str[i] == ' ')
            continue;

        else if(str[i] == '(')
        {
            oprand.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(!oprand.empty() && oprand.top() != '(')
            {
                char a = oprand.top();
                oprand.pop();
                int ab = op.top();
                op.pop();
                int b = op.top();
                op.pop();
                int c ;
                if(a == '+')
                    c = b + ab;
                else if(a == '-')
                    c = b - ab;
                else if(a == '*')
                    c = ab * b;
                else if(a == '/')
                    c = b / ab;
                op.push(c);
            }
            if(!oprand.empty())
                oprand.pop();
        }
        else
        {

                while(!oprand.empty() && prec(oprand.top()) >= prec(str[i]))
                {
                    char a = oprand.top();
                    oprand.pop();
                    int ab = op.top();
                    op.pop();
                    int b = op.top();
                    op.pop();
                    int c ;
                    if(a == '+')
                        c = b + ab;
                    else if(a == '-')
                        c = b - ab;
                    else if(a == '*')
                        c = ab * b;
                    else if(a == '/')
                        c = b / ab;
                    op.push(c);
                }

                oprand.push(str[i]);
            }
        }
        while(!oprand.empty())
        {
            char a = oprand.top();
            oprand.pop();
            int ab = op.top();
            op.pop();
            int b = op.top();
            op.pop();
            int c ;
            if(a == '+')
                c = b + ab;
            else if(a == '-')
                c = b - ab;
            else if(a == '*')
                c = ab * b;
            else if(a == '/')
                c = b / ab;
            op.push(c);
        }
        cout<< op.top()<<endl;
    }




int main()
{
    evalution("10 + 2 * 6");
    evalution("100 * 2 + 12");
    evalution("100 * ( 2 + 12 )");
    evalutionN("100 * ( 2 + 12 ) / 14");
    return 0;
}
