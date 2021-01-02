#include<iostream>
using namespace std;

// doubly linked list queue

class Node
{
public:
    int data;
    Node * next, * prev;

    Node(int a = INT_MIN, Node *n = NULL, Node * p = NULL)
    {
        data = a;
        next = n;
        prev = p;
    }
};

class Queue
{
public:
    Node * front_, * rear;

    Queue()
    {
        front_ = rear = NULL;
    }

    void enQueue(int value)
    {
        Node * temp = new Node(value, NULL, NULL);
        if(front_ == NULL)
        {

//            tempdata = value;
//            tempprev = NULL;
//            tempnext = NULL;
            front_ = temp;
            rear = temp;

        }
        else
        {
            temp->prev = rear;
            rear->next = temp;
            rear = temp;
        }
    }

    void deQueue()
    {
        if(front_ == NULL)
        {
            return ;
        }
        else
        {
            front_ = front_->next;
        }
    }

    int headValue()
    {
        return front_->data;
    }

    int rearValue()
    {
        return rear->data;
    }

    void print()
    {
        Node *temp = front_;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

    bool search_(int a)
    {
        Node *temp = front_;
        while(temp != NULL )
        {
            if(temp->data == a)
            {
                Node *n1, *n2;
                n1 = temp->prev;
                n2 = temp->next;
                n1->next = n2;
                n2->prev = n1;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Node * getRearPoniter()
    {
        return rear;
    }
    Node * getFrontPoniter()
    {
        return front_;
    }

    void setRearPointer(Node * ptr)
    {
        rear = ptr;
    }

    void setFrontPointer(Node *ptr)
    {
        front_ = ptr;
    }

};


class LRUCache
{
    public:
    int cacheSize;
    int pageFault;
    int pageHit;
    Queue q;
    int numOfPage;

    LRUCache(int cacheSie)
    {
        cacheSize = cacheSie;
        pageFault = 1;
        pageHit = 0;
        numOfPage = 0;
    }

    void servicePage(int arr[], int n)
    {
        cout<< "hello \n";
        q.enQueue(arr[0]);

        for(int i=1; i<n; i++)
        {
            cout<< "world \n";

            if(numOfPage < cacheSize)
            {
                if(!q.search_(arr[i]))
                {
                    numOfPage++;
                    q.enQueue(arr[i]);
                    pageFault ++;
                }
                else
                {
                    q.enQueue(arr[i]);
                    numOfPage++;
                    pageHit++;
                }
            }
            if (numOfPage == cacheSize)
            {
                if(!q.search_(arr[i]))
                {
                    q.deQueue();
                    q.enQueue(arr[i]);
                    pageFault++;
                }
                else
                {
                    q.enQueue(arr[i]);
                    pageHit++;
                }
            }
        }
    }

    int getPageFault()
    {
        return pageFault;
    }

    int getPageHit()
    {
        return pageHit;
    }

};
int main()
{
    LRUCache lru(4);

    int arr [6] = {1, 2, 1, 6, 4, 5};

    lru.servicePage(arr, 6);

    cout<<lru.getPageFault()<<endl;
    cout<<lru.getPageHit()<<endl;

    return 0;
}
