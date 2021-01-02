#include<iostream>
#include<stack>
using namespace std;

void postfixToPrefix(string s){

    stack <string> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push(s[i] + b + a);
        }
        else
        {
            st.push(string(1, s[i]));
        }
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
        
}

int main(){

    postfixToPrefix("ABC/-AK/L-*");
    return 0;
}