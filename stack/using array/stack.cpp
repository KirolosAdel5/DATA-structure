#include <bits/stdc++.h> 
using namespace std; 
#define MAX 10
template<class t>
class Stack
{
private:
    int top;t arr[MAX];
public:
    //--------- define intail value to top -1 using constructor------ 
    Stack():top(-1){}
    //--------- push value to stack------ 
    bool push(t data){
        if(top>=MAX-1){puts("stack overflow");return false;}
        else{
            arr[++top]=data;
            cout<<data<<" pushed in stack\n";
            return true;}
    }
    //--------- pop value from stack------ 
    t pop(){
        if(top<0)cout<<"stck underflow\n";
        else{t data =arr[top--];return data;}
    }
    //--------- get top value------ 
    t peek(){
    if (top<0){cout<<"stack is empty!\n";}
    else
    {return arr[top];}}
    //--------- check if stack is empty ------ 
    bool isempty(){
        return top<0;
    }
    //--------- check if stack is full ------ 
    bool isFull(){
            return  top>=MAX-1;
        }
   //--------- display stack items ------ 
    void display(){
        int index=top;
        cout<<"\n";
        while (index>=0)
        {
            cout<<arr[index--]<<" ";
        }
        cout<<"\n";
    }
};

int main() 
{
    Stack<int> t;
    t.push(10);t.push(20);t.push(30);
    t.push(10);t.push(20);t.push(30);
    t.push(10);t.push(20);t.push(30);
    t.push(10);t.push(10);t.push(10);t.push(10); 
    
    t.display();
    printf("top is: %d \n",t.peek());
    t.isempty()?puts("stack is empty"):puts("stack is not empty");
    t.isFull()?puts("stack is full"):puts("stack is not full");
    cout<<t.peek();
    return 0; 
}