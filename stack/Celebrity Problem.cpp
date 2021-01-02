#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> st;
    int n;
    cout<<"enter a number of person\n";
    cin>>n;
    int arr[n][n];
    int count_ = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        st.push(i);
    }
    while(st.size() >= 2){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(arr[a][b] == 0){
            st.push(a);
        }
        else{
            st.push(b);
        }
    }
    int a = st.top();
    for(int i = 0; i<n; i++){
        if(arr[a][i] == 0 && arr[i][a] == 1 && i != a)
            count_++;
    }

    if(count_ == n-1)
        cout<< a <<"\n";
    else
        cout<<"no\n";

    return 0;
}
