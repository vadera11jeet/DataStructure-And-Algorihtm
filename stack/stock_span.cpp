// std problem interview question
#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack <int> s;
    s.push(0);
    int value, n;
    cout<< "enter value of the n \n";
    cin>>n;
    int arr[n];
    int arr1[n];
    arr1[0] = 1;
    cout<< "enter a value in array\n";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<n; i++){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        arr1[i] = s.empty() ? (i+1) :(i - s.top());
        s.push(i);
    }
    for(int i = 0; i<n; i++)
        cout<<arr1[i]<< endl;

    return 0;
}
