#include<iostream>
#include<stack>
using namespace std;

void prefixToPostfix(string s){
    
    stack <string> st;
    for(int i = s.length()-1; i>=0; i--){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push(a + b + s[i] );
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    cout<<st.top();
}

int main(){

    string s = "*-A/BC-/AKL";
    prefixToPostfix(s);
    return 0;

}