#include<iostream>
#include<queue>
using namespace std;

// this function make pop operation O(n) and push operation is O(1)
void stackWithOof1(){
    queue<int>q1, q2;
    int n, value;
    for(int i = 0; i < 3; i++){
        cout<<"1 for push\n";
        cout<<"2 for pop\n";
        cin>>n;
        if (n == 1)
        {
            cout<<"enter a value in stcak\n";
            cin>>value;
            q1.push(value);
        }
        if(n == 2)
        {
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            cout<<q1.front()<<endl;
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }       
    }
}

int main(){
    stackWithOof1();
    // here we make push operation is costly O(N) and pop operation is O(1)
    // queue<int>q1, q2;
    // int n, value;
    // for(int i = 0; i < 3; i++){
    //     cout<<"1 for push\n";
    //     cout<<"2 for pop\n";
    //     cin>>n;
    //     if (n==1)
    //     {
    //         cout<<"enter a value in stcak\n";
    //         cin>>value;
    //         if(q1.empty()){
    //             q1.push(value);
    //         }
    //         else{
    //             while(!q1.empty()){
    //                 q2.push(q1.front());
    //                 q1.pop();
    //             }
    //             q1.push(value);
    //             while(!q2.empty()){
    //                 q1.push(q2.front());
    //                 q2.pop();
    //             }
    //         }
    //     }

    //     if(n == 2){
    //         cout<<q1.front()<<endl;
    //         q1.pop();
    //     }
    // }
    return 0;
}