#include<iostream>
using namespace std;

class TwoStack {
    private:
        int arr[10];
        int top1;
        int top2;

    public:
        TwoStack(){
            top1 = -1;
            top2 = 10;
        }

        bool stacksIsFull(){
            if(top2 - top1 == 1){
                return true;
            }
            return false;
        }

        bool isEmptyStack1(){
            if(top1 == -1){
                return true;
            }
            return false;
        }

        bool isEmptyStack2(){
            if(top2 == 10){
                return true;
            }
            return false;
        }

        void pushInStack1(int value){
            if(stacksIsFull()){
                cout<< "stack is overflow\n";
                return;
            }
            top1++;
            arr[top1] = value;
        }

        void pushInStack2(int value){
            if(stacksIsFull()){
                cout<< "stack is overflow\n";
                return;
            }
            top2--;
            arr[top2] = value;
        }

        int popStack1(){
            if(isEmptyStack1()){
                cout<< "stack is underflow\n";
                abort();
            }
            int x = arr[top1];
            top1--;
            return x;
        }

        int popStack2(){
            if(isEmptyStack2()){
                cout<< "stack is underflow\n";
                abort();
            }
            int x = arr[top2];
            top2++;
            return x;
        }
    
};

int main(){
    TwoStack s1;
    s1.pushInStack1(1);
    s1.pushInStack1(2);
    s1.pushInStack1(3);
    s1.pushInStack1(4);
    s1.pushInStack1(5);
    s1.pushInStack2(6);
    s1.pushInStack2(7);
    s1.pushInStack2(8);
    s1.pushInStack2(9);
    s1.pushInStack2(10);
    cout<< s1.popStack2()<<endl;
    cout<< s1.popStack2()<<endl;
    s1.pushInStack2(11);
    cout<<s1.stacksIsFull();
    return 0;
}