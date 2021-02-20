#include<iostream>
using namespace std;
#define size 10
int queue[size];
int front = -1;
int rear = -1;
void enqueue(int value);
void dequeue();
int peek();
void display();

int main()
{
    enqueue(20);
    enqueue(90);
    enqueue(10);
    display();
    cout<<"********************************"<<endl;
    dequeue();
    dequeue();
    display();
    cout<<"peek is "<<peek();
    return 0;
}

void enqueue(int value)
{
    if(rear!=size-1)
    {
        if(front==-1 && rear == -1)
        {
            front++;
            queue[++rear] = value;
        }
        else 
        {
            queue[++rear] = value;
        }
    }

    else 
    {
       cout<<"queue is full"<<endl; 
    }

}

void dequeue()
{
    if(front==-1 && rear == -1 && front>=rear)
    {
        cout<<" queue is empty"<<endl;
    }
    else 
    {
        front++;
    }
}

int peek()
{
    if(front==-1 && rear == -1 && front>=rear)
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
    if(front==-1 && rear == -1 && front>=rear)
    {
        cout<<" queue is empty"<<endl;
    }
    else 
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<" queue element is "<<queue[i]<<endl;
        }
    }

}

