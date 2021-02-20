#include<iostream>
using namespace std;
#define MAX 10
int size = 0;

struct stack{
    int top;
    int items[MAX];
};
typedef struct stack st;
void createempty(st*s){s->top=-1;}
bool isfull(st* s){return s->top==MAX-1;}
bool isempty(st* s){return s->top==-1;}
void push(st*s,int val){
isfull(s)?puts("stack full"):s->top++,s->items[s->top] = val,size++;
}
void pop(st*s){
isempty(s)?puts("STACK EMPTY"):s->top--,size--;
}
void printStack(st *s) {
 for (int i = 0; i < size; i++) {
    cout << s->items[i] << " ";
  }
  cout << endl;
}

int main(){
    int size,item;cin>>size;
  st *s = new(st);
  createempty(s);
  for (int i=0;i<size;i++)cin>>item,push(s,item);
  printStack(s);
  pop(s);

  cout << "\nAfter popping out\n";
  printStack(s);
    return 0;
}