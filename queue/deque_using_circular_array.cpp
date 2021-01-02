// deque is the special type of queue in this data structure we can insert and delete data from both pointer front and rear
// this data structure is to solve a problem like 0-1 BFS and many more problem

#include<iostream>
using namespace std;

#define MAX 100

class Deque
{

public:
    int arr[MAX];
    int front_;
    int rear;
    int size_;

    Deque(int size_)
    {
        front_ = -1;
        rear = -1;
        this->size_ = size_;
    }

    void insertFront(int value)
    {
        if(isFull())
            return ;

        else if(isEmpty())
            front_ = rear = 0;

        else if(front_ == 0)
            front_ = size_ - 1;

        else
            front_--;

        arr[front_] = value;
    }

    void insertRear(int value)
    {
        if(isFull())
            return;
        else if(isEmpty())
            front_ = rear = 0;
        else if(rear == size_ - 1)
            rear = 0;
        else
            rear++;
        arr[rear] = value;
    }

    void deleteFront()
    {
        if(isEmpty())
            return;

//      there is only one element in deque to remove this element

        else if(front_ == rear)
            front_ = rear = -1;

        else if(front_  == size_ - 1)
            front_ = 0;

        else
            front_++;
    }

    void deleteRear()
    {
        if(isEmpty())
            return ;

        else if(front_ == rear)
            front_ = rear = -1;

        else if(rear == 0)
            rear = size_ - 1;

        else
            rear --;
    }

    bool isFull()
    {
        return ((front_ == rear + 1) || (front_ == 0 && rear == size_ - 1));
    }

    bool isEmpty()
    {
        return (front_ == -1);
    }

    void print()
    {
        for(int i = front_ ; i <= rear; i = (i+1) % size_)
            cout<<arr[i]<<endl;
    }

};


int main()
{
    Deque d(5);
    d.insertFront(1);
    d.insertRear(2);
    d.insertRear(3);
    d.print();
    cout<<endl;
    d.deleteFront();
    d.print();
    cout<<endl;
    d.deleteRear();
    d.print();
    cout<<endl;

    return 0;
}
