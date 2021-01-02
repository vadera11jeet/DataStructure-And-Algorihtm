#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue <int> q1;
    int n, value;

    for(int i = 0; i< 5; i++)
    {
        cout<< "1 for push\n";
        cout<< "2 for pop \n";
        cin>>n;
        if(n == 1){
            cin>>value;
            q1.push(value);
        }
        else if(n == 2){
            int s = q1.size();
            for(int i = 0; i<s-1; i++){
                q1.push(q1.front());
                q1.pop();
            }
            cout<<q1.front()<<endl;
            q1.pop();
        }
        else{
            cout<<"please enter valid value\n";
        }

    }

    return 0;
}