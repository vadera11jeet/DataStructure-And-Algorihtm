#include<iostream>
#include<stack>
using namespace std;

int prec(char a){
    if(a == '^')
        return 3;
    else if(a == '*' || a == '/')
        return 2;
    else if(a == '+' || a == '-' )
        return 1;
    else 
        return -1;
}   

void infixToPostfix(string s){

    int len = s.length();
    stack <char> st;
    st.push('\n');
    for(int i = 0; i<len; i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            cout<<s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(st.top() != '(' && st.top() != '\n'){
                cout<<st.top();
                st.pop();
            }
            if(st.top() == '('){
                st.pop();
            }
        }
        else
        {
            while (st.top() != '\n' && prec(s[i]) <= prec(st.top()))
            {
                cout<<st.top();
                st.pop();
            }
            st.push(s[i]);            
        }
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;    
}


int main(){

    string st = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(st);
    return 0;

}