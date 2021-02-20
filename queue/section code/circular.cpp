#include <iostream>
using namespace std;
#define size 10
int queue[size];
int front = -1;
int rear = -1;

bool isFull()
{
    if(front == 0 && rear == size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if(front==-1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int value)
{
    if(isFull())
    {
        cout<<" queue is full"<<endl;
    }
    else
    {
        if(isEmpty())
        {
            front = rear =0; // front++;
            queue[rear] = value; // queue[++rear] = value;
        }
        else if (rear == size-1)
        {
            rear =0;
            queue[rear] = value;
        }
        else
        {
            queue[++rear] = value; 
        }

    }
}
void dequeue()
{
    if(isEmpty())
    {
        cout<<"queue is empty "<<endl;
    }

else
{
   if(front == rear)
   {
       front = rear -1;
   }
   else if(front == size-1)
   {
       front = 0;
   }
   else 
   {
       front++;
   }

}

}

int peek()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<" queue is empty"<<endl;
    }
    else
    {
        if(front<=rear)
        {
            for(int i = front;i<=rear;i++)
            {
                cout<<"queue element "<<queue[i]<<endl;
            }
        }
        else
        {
            for(int i=front;i<size;i++)
            {
                cout<<"queue element is "<<queue[i]<<endl;
            }
            cout<<"************************"<<endl;
            for(int i=0;i<=rear;i++)
            {
                cout<<" queue element is "<<queue[i]<<endl;
            }
        }
    }

}

int main()
{
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(60);
    enqueue(100);
    enqueue(101);
    enqueue(102);
    enqueue(103);
    enqueue(104);
    enqueue(105);
    display();
    cout<<"***********************"<<endl;
    dequeue();
    enqueue(106);
    enqueue(107);
    enqueue(108);
    display();
    cout<<"peek is "<<peek();
}
