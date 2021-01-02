#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack <int> st;
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    st.push(arr[0]);

    for(int i=1; i<n; i++){

        if(st.top() >= arr[i]){
            st.push(arr[i]);
        }
        else{
            while (st.top() < arr[i] && (!st.empty()))
            {
                cout<<st.top()<<"  "<<arr[i]<<endl;
                st.pop();
            }
            st.push(arr[i]);
        }

    }
//    this code will give output that do not follow  input sequence
// to output with input sequence use another array which stores only index of position
// and stack also store index and in array index must be store like at same index at same position ex if index is 2 store it than store at array index 2


    while(!st.empty()){
        cout<<st.top()<< "  "<<-1<<endl;
        st.pop();
    }


    return 0;
}
