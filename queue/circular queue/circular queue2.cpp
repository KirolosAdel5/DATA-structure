#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class cqueue
{
private:
    int front,items[MAX],rear;
public:
    cqueue():front(-1),rear(-1){}
    bool isfull(){return (front==0&&rear==MAX-1)||front==rear+1;}
    bool isempty(){return front==-1;}
    void enQueue(int element){isfull()?puts("Queue is full!"):front==-1?front=0,rear = (rear + 1) % MAX,items[rear] = element:rear = (rear + 1) % MAX,items[rear] = element;}
    void deQueue(){isempty()?puts("Queue is empty!"):front==rear?front=rear=-1:front = (front + 1) % MAX;}
    void display(){
        int i;
        if(isempty())puts("empty!");
        else{
            for (i= front; i != rear; i = (i + 1) % MAX)cout << items[i]<<" ";
            cout<<items[i]<<"\n";
    }}
    void peek(){cout <<"\nfront= "<< items[front] <<" rear= "<<items[rear];}
};

int main(){
    cqueue cq;
    cq.enQueue(10);
    cq.enQueue(20);
    cq.enQueue(30);
    cq.enQueue(40);
    cq.display();
    cq.peek();



 
    return 0;
}