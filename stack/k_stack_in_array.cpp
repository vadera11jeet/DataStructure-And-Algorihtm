#include<iostream>
using namespace std;

class KStack{
    int *arr;
    int *top;
    int *next;
    int n,k;
    int free_;
    public : 
        KStack(int k_, int n_){
            int n = n_;
            int k = k_;
            arr = new int[n];
            top = new int[k];
            next = new int[n];

            free_ = 0;

            for(int i = 0; i<k; i++)
                top[i] = -1;
            
            for(int i = 0; i < n-1; i++){
                next[i] = i + 1;
            }
            next[n-1] = -1;
        }

        bool isFull(){
            return free_ == -1;
        }

        bool isEmpty(int sn){
            return top[sn] == -1;
        }

        void push(int value, int stack_num){
            if(isFull()){
                cout<<"stack is overflow \n";
                return;
            }
            else{
                int i = free_;
                free_ = next[i];
                next[i] = top[stack_num];
                top[stack_num] = i;
                arr[i] = value;
            }
        }

        int pop(int stack_num){
            if(isEmpty(stack_num))
            {
                cout<<"stack is underflow\n";
                abort();
            }
            int i = top[stack_num];
            top[stack_num] = next[i];
            next[i] = free_;
            free_ = i;
            return arr[i];
        }

};

int main(){

    KStack ks(3, 10);
    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout<< "poped from stack 2 " << ks.pop(2)<<endl;
    cout<< "poped from stack 1 " << ks.pop(1)<<endl;
    cout<< "poped from stack 0 " << ks.pop(0)<<endl;
    
    return 0;
}