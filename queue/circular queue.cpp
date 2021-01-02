#include<iostream>
using namespace std;

class Queue
{
    private:
        int front_;
        int rear;
        int arr[5];

    public:
        Queue()
        {
            front_ = -1;
            rear = -1;
        }

        void enqueue(int a)
        {
            if(front_ == rear + 1 || (front_ == -1 && rear == 4))
            {
                cout<< "queue is full\n";
                return ;
            }
            else
            {
                if(front_ == -1)
                    front_ = 0;
                rear = (rear + 1) % 5;
                arr[rear] = a;
            }
        }

        void dequeue()
        {
            if(front_ == -1)
            {
                cout<< "queue is empty\n";
                return;
            }
            else
            {
                if(front_ == rear)
                {
                    front_ = -1;
                    rear = -1;
                }
                else
                {
                    front_ = (front_ + 1) %5;
                }
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
            if (front_ == -1)
            {
//                printf("\nQueue is Empty");
                return;
            }
//            printf("\nElements in Circular Queue are: ");
            if (rear >= front_)
            {
                for (int i = front_; i <= rear; i++)
                    cout<<arr[i]<<endl;
            }
            else
            {
                for (int i = front_; i < 5; i++)
                    cout<<arr[i]<<endl;

                for (int i = 0; i <= rear; i++)
                    cout<<arr[i]<<endl;
            }
                }

};


int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print();

    q.dequeue();
    q.enqueue(6);

    q.print();



    return 0;
}
