#include<iostream>
using namespace std;

class Stack{

    private:
        static const int max = 100;
        int arr[max];
        int top;
        int isMin;

    public:
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(top == max - 1){
                return true;
            }
            return false;
        }

        int pop(){
            if(isEmpty()){
                cout<< "stack is underflow\n";
                abort();
            }
            int x = arr[top];
            top--;
            return x;
        }

        void push(int value){
            if(isFull()){
                cout<< "stack is overflow\n";
                return;
            }
            else{
                if(top == -1){
                    isMin = value;
                }
                if(isMin > value){
                    isMin = value;
                }
                top++;
                arr[top] = value;
            }
        }
        
        int getMin(){
            return isMin;
        }
};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<"Minimum number from the stack "<<s1.getMin()<<endl;
    cout<<"poping the element " <<s1.pop()<<endl;
    return 0;
}