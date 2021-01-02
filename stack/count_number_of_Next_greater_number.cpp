#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack <int> st;
    int n;
    cout<< "enter number of element\n";
    cin>>n;
    int arr1[n] = {0};
    int j = 0;

    int arr[n];
    int arr2[n] = {0};

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    st.push(0);
    for(int i = 1; i<n; i++){
        while(!st.empty()){
            if(arr[st.top()] < arr[i]){
                arr1[st.top()] = i;
                st.pop();
            }
            else
                break;
        }
        st.push(i);
    }

    while(!st.empty()){
        arr1[st.top()] = -1;
        st.pop();
    }

    for(int i = n-2; i>=0; i--){
        if(arr1[i] == -1)
            arr2[i] = 0;
        else
            arr2[i] = 1 + arr2[arr1[i]];
    }

    int q, index;
    cout<<"enter number of query\n";
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>index;
        cout<<arr2[index]<<endl;
    }

    return 0;
}
