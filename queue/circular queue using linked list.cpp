#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

        Node(int value = INT_MIN , Node * n = NULL)
        {
            data = value;
            next = n;
        }
};

class LinkedListCircularQueue
{
    public:
        Node *front_, *rear;

        LinkedListCircularQueue()
        {
            front_ = NULL;
            rear = NULL;
        }

        void enQueue(int value)
        {
            Node * temp = new Node(value, front_);

            if(front_ == NULL)
            {
                front_ = temp;
                rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
//                cout<<rear->data<<endl;
            }

        }

        void deQueue()
        {
            if(front_ == NULL)
                return ;
            else
            {

                front_ = front_->next;
                rear->next = front_;

            }
        }

        void print()
        {
            Node *temp = front_;
            while(temp->next != front_)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }
};


int main()
{

    LinkedListCircularQueue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);

    q.print();

    q.deQueue();
    cout<<endl;
    q.print();

    return 0;
}
