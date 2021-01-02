#include<iostream>
using namespace std;

class Queue
{

    int front_, rear;
    int arr[10];

    public:

        Queue()
        {
            front_ = -1;
            rear = -1;
        }

        void enqueue(int a)
        {
            if(rear == 9)
                return ;
            else
            {
                if(front_ == -1)
                {
                    front_ = 0;
                }
                rear++;
                arr[rear] = a;
            }
        }

        void dequeue()
        {
            if(front_ == -1)
                return ;
            else
            {
                front_++;
            }
        }

        int getFront()
        {
            return front_;
        }

        int getRear()
        {
            return rear;
        }

        void print()
        {
            for(int i = front_ ; i <= rear; i++)
                cout<< arr[i]<<endl;
        }
};

int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.print();

    cout<<endl;

    q1.dequeue();
    q1.print();

    return 0;
}
