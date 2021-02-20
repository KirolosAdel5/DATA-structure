#include <bits/stdc++.h> 
using namespace std; 
#define MAX 10
template<class t>
class Stack{
    struct node{
        t data;node*next;
    };
    node*top,*cur;
    int count=0;
public:
    Stack():top(NULL){}
    void push(t element){
        node*elementptr=new node;
        elementptr->data=element;
        elementptr->next=top;
        top=elementptr;
        count++;
    }
    bool isempty(){
        return top==NULL;
    }
    bool isfull(){return count>=MAX-1;}
    void pop(){
        if(isempty()){cout<<"Stack is empty";}
        else
        {
            node*temp=top;
            top=top->next;
            temp=temp->next=NULL;
            delete temp;
            count--;
        }
        }    
    t peek(){
        if(isempty()){cout<<"Stack is empty";}
        else
        {
            return top->data;
        }}  
    void display(){
        cur=top;
        cout<<"[ ";
        while (cur!=NULL)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<" ]\n";
    }

    int len(){return count;}
};

int main() 
{ 
    int ch, val;Stack<int>s;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) get top stack"<<endl;
   cout<<"5) get length of stack"<<endl;
   cout<<"6) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
        case 1: {cout<<"Enter value to be pushed:"<<endl;cin>>val;s.push(val);break;}
        case 2: {s.pop();break;}
        case 3: {s.display();break;}
        case 4:{cout<<"top is : "<<s.peek()<<endl;break;}
        case 5:{cout<<"length is : "<<s.len()<<endl;break;}
        case 6: {cout<<"Exit"<<endl;exit(0);break;}
        default: {cout<<"Invalid Choice"<<endl;}
      }
   }while(ch!=6);
   
    return 0; 
}