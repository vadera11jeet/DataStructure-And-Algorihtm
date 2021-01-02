// postfix expression evaluation
#include<iostream>
#include<stack>
using namespace std;

void postfixEvaluation(string s)
{
    stack <int>st;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
            continue;
        else if(isdigit(s[i])){
            int value = 0;
            while(i < s.length() && isdigit(s[i])){
                value = (value * 10) + (s[i] - '0');
                i++;
            }
            st.push(value);
        }
        else
        {
            char a = s[i];
            int ab = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c;
            if(a == '+')
                c = b + ab;
            else if(a == '-')
                c = b - ab;
            else if(a == '*')
                c = ab * b;
            else if(a == '/')
                c = b / ab;

            st.push(c);
        }
    }
    cout<<st.top()<<endl;
}

int main()
{
//    give space separate input
    postfixEvaluation("2 4 + 4 6 + *");
    postfixEvaluation("2 3 1 * + 9 -");

    return 0;
}
