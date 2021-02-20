#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
class Queue{
private:
    int items[SIZE], front, rear;
public:
  Queue() {
    front = -1;
    rear = -1;
  }
  bool isFull() 
  {
   return (front == 0 && rear == SIZE - 1); 
  }
  bool isEmpty() {
    return front == -1;
  }
  // Adding an element
  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front ++;
      rear++;
      items[rear] = element;
    }
  }
  // Removing an element
  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else {
        front++;
      }
      return (element);
    }
  }

  void display() {
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;return;
    } 
  
     cout << "Front -> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i]<<" ";
      cout << items[i];
      cout << endl
         << "Rear -> " << rear;
    }
};
int main()
{
   int value, choice;
   Queue k;
    k.enQueue(10);
    k.enQueue(20);
    k.enQueue(30);
    k.enQueue(40);
    k.display();
}