#include<iostream>
using namespace std;

class Node
{
    public:
        int value;
        int priority;
        Node * next;

        Node(int val = INT_MIN, int priority = INT_MIN ,Node * n = NULL)
        {
            value = val;
            this->priority = priority;
            next = n;
        }
};

class PriorityQueue
{
    public:
        Node *front_;

        PriorityQueue()
        {
            front_ = NULL;
         }

    void enqueue(int value, int priority)
    {
        Node * temp = new Node(value, priority, NULL);

        if(front_ == NULL)
        {
            front_ = temp;
        }

        else if(front_->priority <= temp->priority)
        {
            temp->next = front_;
            front_ = temp;
        }
        else
        {
            Node * temp1 = front_;
            while(temp1->next != NULL && temp1->next->priority > priority)
            {
                temp1 = temp1->next;
            }
            temp->next = temp1->next;
            temp1->next = temp;
        }

    }

    void dequeue()
    {
        if(front_ == NULL)
            return;

        front_ = front_->next;
    }

    void print()
    {
        Node *temp = front_;
        while(temp != NULL)
        {
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }

};

int main()
{
    PriorityQueue p;
    p.enqueue(1,5);
    p.enqueue(1,6);
    p.enqueue(2,4);
    p.enqueue(3,3);
    p.enqueue(4,2);
    p.enqueue(5,1);

    p.print();

    p.dequeue();

    cout<<endl;
    p.print();

    return 0;
}
