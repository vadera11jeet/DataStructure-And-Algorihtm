#include<iostream>
#include<stack>
using namespace std;

int main(){

    string s;
    stack <char> st;
    cin>>s;
    int count_ = 0;

    for(int i = 0; i<s.length(); i++){
        if(st.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        if(s[i] == ']' && st.top() == '['){
            count_++;
            st.pop();
        }
        if(s[i] == ')' && st.top() == '('){
            count_++;
            st.pop();
        }
        if(s[i] == '}' && st.top() == '{'){
            count_++;
            st.pop();
        }

    }
    if(st.empty())
        cout<<"balanced";
    else
        cout<<"not balanced";
    
    return 0;
}