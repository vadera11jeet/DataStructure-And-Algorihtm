//queue using stack
#include<iostream>
#include<stack>
using namespace std;
void enqeueWithO1();
// here enqueue operation is costly it take O(n) time complexity and deqeue is take O(1) time complexcity

int main(){
    // enqeueWithO1();
    stack <int> s1, s2;
    int n, temp;
    for(int i = 0; i < 5; i++){
        cout<< "select an operation \n";
        cout<< "1 for enqueue \n";
        cout<< "2 for dequeue \n";
        cin>>n;
        if(n == 1){
            cout<< "enter value \n";
            cin>>temp;
            if(s1.empty()){
                s1.push(temp);
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(temp);
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }
        else if(n == 2){
            if(s1.empty()){
                cout<< "queue is empty\n";
            }
            else{
                cout<<s1.top()<<endl;
                s1.pop();
            }
        }
        else{
            cout<< "enter correct value\n";
        }
    }


    return 0;
}


// another approch in which enqeue is done in O(1) time complexcity and deqeue O(n) time complexcity
void enqeueWithO1(){

    stack <int> s1, s2;
    int n, temp;
    for(int i = 0; i< 5; i ++){
        cout<< "select an operation \n";
        cout<< "1 for enqueue \n";
        cout<< "2 for dequeue \n";
        cin>>n;
        if(n == 1){
            cin>>temp;
            s1.push(temp);
        }
        else if (n == 2){
            if(s1.empty()){
                cout<< "queue is empty\n";
                return;
            }
            else{
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                cout<<s2.top()<<endl;
                s2.pop();
                while(!s2.empty())
                {
                    s1.push(s2.top());
                    s2.pop();
                }
                
            }
        }
        else{
            cout<<"enter correct value\n";
        }
    }

}
