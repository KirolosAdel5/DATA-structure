#include<bits/stdc++.h> 
using namespace std; 

struct Queue 
{ 
	int rear, front; 
	int size; 
	int *arr; 

	Queue(int s) 
	{ 
	front = rear = -1; 
	size = s; 
	arr = new int[s]; 
	} 

	void enQueue(int value); 
	void deQueue(); 
	void displayQueue(); 
  bool isfull();
  bool isempty();
}; 

bool Queue::isempty(){return (front == -1&&rear == -1);}
bool Queue::isfull() {return front==(rear+1)%size;}/*(front==rear+1)or(rear=(front-1)%(size-1))*/
void Queue::enQueue(int value) 
{ 
	if (isfull()) 
	{ 
		printf("\nQueue is Full"); 
		return; 
	} 
  else if(isempty())rear=front=0;
  else 
    rear=(rear+1)%size;
  
	arr[rear] = value; 
} 

void Queue::deQueue() 
{ 	 

	if  (isempty())
	{ 
		printf("\nQueue is Empty"); 
		return ; 
	} 
	else if (front == rear) 
	{ 
		front = rear =-1; 
	} 
	else
		front=(front +1) %size; 

} 

void Queue::displayQueue() 
{ 
	if (isempty()) 
	{ 
		printf("\nQueue is Empty"); 
		return; 
	} 
  while (!isempty())
  {
    cout<<arr[front]<<" ";
    deQueue();
  }
  

} 

/* Driver of the program */
int main() 
{ 
	Queue q(5); 

	// Inserting elements in Circular Queue 
	q.enQueue(14); 
	q.enQueue(15); 
	q.enQueue(16); 
	q.enQueue(17); 
	q.enQueue(18); 
  q.deQueue();
  q.deQueue();
  q.deQueue();
  q.deQueue();
  q.deQueue();
  q.displayQueue();
	return 0; 
} 
