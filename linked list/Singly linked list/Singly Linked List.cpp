#include <bits/stdc++.h>
using namespace std;
class linkedlist{
    struct node
    {
        int data;node*next;
    };
public:
    node*head=NULL;
//-------------------- insert -------------------
    void insert_end(int val){
 
        node*newnode=new node;
        newnode->data=val;
        newnode->next=NULL;
        
        //----------------
        if(head==NULL){head=newnode;}
        else
        {
            node*temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newnode;
        }
    }
    void insert_begin(int val){
        node*current=head;
        node*newnode=new node;
        newnode->data=val;
        newnode->next=head;
        head=newnode;        
    }
    void insert_mid(int val){  
        node* current=head;
        node* newnode=new node;
        newnode->data=val;
        newnode->next=NULL;
        while (newnode->data>current->next->data)
        {
           current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;

    }
    void insert_at_possession(int val ,int pos){
            node*newnode=new node;
            newnode->data=val;
            newnode->next=NULL;

            if(pos==0){newnode->next=head;head=newnode;return;}
            else{
            node* currnode=head;
            for (int i = 0; i<pos-1&&currnode->next!=NULL; i++)
            {
                currnode=currnode->next;
            }
            newnode->next=currnode->next;
            currnode->next=newnode;
            }
    }

//-------------------- remove -------------------
    void remove_end(){
        
        if(head->next==NULL){
            head=NULL;}
        else if(head==NULL){puts("list empty!\n");return;}
        else {
        node *prev,*currnet;
        prev=currnet=head;
        while (currnet->next!=NULL)
        {
            prev=currnet;
            currnet=currnet->next;
        } 
        if(currnet==NULL){return;}
        else{prev->next=currnet->next;delete (currnet);}
        }
    }
    void remove_begin(){
        if(head==NULL){puts("list is empty!");return;}
        node* temp = head; 
        head = head->next; 
        delete temp; 
    }
    void remove_at_possession(int pos){
        if(head==NULL){return;}
        else if(pos==0){
            node*temp=head;
            head=head->next;
            delete temp;
        }
        else{
            node*temp=head;
            for(int i=0;i<pos-1&&temp->next!=NULL;i++){
                temp=temp->next;
            }
            node*temp2=temp->next;
            temp->next=temp2->next;
            delete temp2;
        }
    }
    void remove_value(int val){
        if(head==NULL){puts("list empty!\n");return;}
        node *prev,*currnet;
        prev=currnet=head;
        if(currnet->data==val){
            head=currnet->next;
            delete currnet;
            return;
        }
        while (currnet!=NULL&&currnet->data!=val)
        {
           prev=currnet;
           currnet=currnet->next;
        }
        if(currnet==NULL){return;}
        else{prev->next=currnet->next;delete (currnet);}
    }

//-------------------- display -------------------
    void display(){ 
    node* ptr= head;
    if(ptr==NULL){cout<<"linked list is empt!"<<endl;}
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
         }
    }

//-------------------- search in linked list -------------------
    bool search(int x)  
    {
    node* current = head; // Initialize current  
    while (current != NULL)  
    {  if (current->data == x)  
            return true;  
        current = current->next;  
    }  
    return false;  
    } 
    void search_get_index(int x)  
    {
    int index=0;
    node* current = head; // Initialize current  
    while (current != NULL)  
    {   
        if (current->data == x){cout<<"\nitem "<<x<<" find in index : "<<index<<endl;return;}  
        index++;    
        current = current->next;  
    }  
    cout<<"\nitem "<<x<<" not found!"<<endl;return; 
    } 

//-------------------- reverse linked list -------------------
    void reverse()
    {
      
        node* current = head;
        node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

//-------------------- reverse linked list method 2 -------------------
    node* reverse2(node* head){
        if (head == NULL || head->next == NULL)
        return head;
 
        node* rest = reverse2(head->next);
        head->next->next = head;
        head->next = NULL;
         return rest;
    }

//-------------------- get end -------------------
    int end(){
            node*temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            return temp->data;
    }

//-------------------- get front -------------------
    int front(){
        return head->data;
    }
};

int main()
{   linkedlist k;
    k.insert_end(10);
    k.insert_end(20);
    k.insert_end(30);
    k.insert_end(40);
    k.insert_end(50);
    k.display();
      return 0;
} 
