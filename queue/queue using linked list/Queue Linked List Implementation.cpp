#include<bits/stdc++.h>
using namespace std;
class Queue{
private:
	struct Node{
		int data;
		Node* next;
	};
	Node *front = nullptr, *tail = nullptr;
public:
	void enqueue(int val){
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = nullptr;

		if (isEmpty()){
			front = tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}

	}

	void dequeue(){
		if (isEmpty())
			return;

		Node* temp = front;
		if (front == tail)
			front = tail = nullptr;
		else{
			front = front->next;
		}
		delete temp;
	}

	int frontValue(){
		if (isEmpty())
			return -1;
		else
			return front->data;
	}

	bool isEmpty(){
		if (front == nullptr && tail == nullptr)
			return true;
		else
			return false;
	}
     void display(){
        Node*cur=front;
        cout<<"[ ";
        while (cur!=NULL)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<" ]\n";
    }
	~Queue(){
		Node* temp = front;
		while (front != nullptr){
			front = front->next;
			delete temp;
			temp = front;
		}
		front = tail = nullptr;
	}
};
int main()
{
    Queue k;
    k.enqueue(10);
    k.enqueue(20);
    k.enqueue(30);
    k.enqueue(40);

    k.display();
    
    return 0;
}