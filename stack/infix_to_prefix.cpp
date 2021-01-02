#include<iostream>
#include<stack>
using namespace std;

int prec(char i){
    if(i == '^')
        return 3;
    else if(i == '/' || i == '*')
        return 2;
    else if(i == '+' || i == '-')
        return 1;
    else
        return -1;
}

void infixToPrefix(string s){

    string s1, ans;
    stack <char> st;
    st.push('\n');

    for(int i = s.length() -1; i >=0; i--){
        if(s[i] == '(')
        {
            s1 += ')';
        }
        else if(s[i] == ')'){
            s1 += '(';
        }
        else
        {
            s1 += s[i];
        }
    }

    for(int i = 0; i < s.length(); i++){
        if((s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= 'a' && s1[i] <= 'z')){
            ans += s1[i];
        }
        else if(s1[i] == '('){
            st.push(s1[i]);
        }
        else if(s1[i] == ')'){
            while(st.top() != '\n' && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(st.top() == '('){
                st.pop();
            }
        }
        else{
            while(st.top() != '\n' && prec(s[i]) <= prec(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s1[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    for(int i = ans.length() -1; i>=0; i--){
        cout<<ans[i];
    }

}


int main(){

    string s = "(A-B/C)*(A/K-L)";
    infixToPrefix(s);
    return 0;
}