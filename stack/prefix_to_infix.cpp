#include<iostream>
#include<stack>
using namespace std;

void prefixToInfix(string s){
    stack <string> st;
    for(int i = s.length()-1; i>=0; i --){
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^'){
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push("("+ a + s[i] + b + ")");
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    cout<<st.top();
}

int main(){
    string temp = "*-A/BC-/AKL";
    prefixToInfix(temp);
    return 0;
}