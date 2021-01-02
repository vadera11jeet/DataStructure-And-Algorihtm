#include<iostream>
#include<stack>
using namespace std;

void postfixToInfix(string s){
    stack <string> st;
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^'){
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push("("+ b + s[i] + a + ")");
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    cout<<st.top();
}

int main(){
    string s = "ab*c+";
    postfixToInfix(s);
    return 0;
}