#include <bits/stdc++.h>
using namespace std;
class doublylinkedlist{
    struct node
    {
        int data;node*next;node*prev;
    };
    node*head;node*prev;
    public:
        doublylinkedlist():head(NULL),prev(NULL){}
        
        //----------- insert -----------
        void insertstart( int new_data)
            {

          node* new_node = new node;
            //------- allocate new node --------
            new_node->data = new_data;
            new_node->next = head;
            new_node->prev = NULL;
            //---------------
            if ((head) != NULL)
                (head)->prev = new_node;

            (head) = new_node;
            }
        void insertend(int new_data)
        {
            node* new_node = new( node);        
            new_node->data = new_data;
            new_node->next = NULL;
   
            if (head == NULL) {
                new_node->prev = NULL;
                head = new_node;
                return;
            }
            node* last = head;
            while (last->next != NULL)
                last = last->next;
        
            last->next = new_node;
            new_node->prev = last;
        }
        void insert_mid(int new_data){  
            node* new_node = new( node);        
            new_node->data = new_data;
            new_node->next = NULL;
   
            if (head == NULL) {
                new_node->prev = NULL;
                head = new_node;
                return;
            }
            node*current=head;
            while (new_node->data > current->next->data&&new_node->data<current->prev->data)
            {
            current=current->next;
            }
            new_node->next=current->next;
            current->next=new_node;
            new_node->prev=current->prev;

    }
        void isert_postion(int new_data,int pos){
            node* new_node = new( node);        
            new_node->data = new_data;
            new_node->next = NULL;
   
            if (pos == 0) {
                new_node->next=head;
                head->prev = new_node;
                head=new_node;
                return;
            }
           	node* temp = head;
            for (int i = 0; i < pos && temp != nullptr; i++){
                temp = temp->next;
            }

            if (temp == NULL){
                this->insertstart(new_data);
                return;
		}

		new_node->prev = temp->prev;
		temp->prev->next = new_node;
		temp->prev = new_node;
		new_node->next = temp;
        }

        //----------- delete -----------
        void delete_item(int data){
            node* temp=head;
            if(temp->data==data){
                head=temp->next;
                if(head!=NULL)
                    head->prev=NULL;
                delete temp;
			    return;
            }
                while (temp!=NULL&&temp->data!=data)
                {
                    temp=temp->next;
                }
            if (temp == nullptr)
			return;
            temp->prev->next=temp->next;
                if(temp->next!=NULL)
                    temp->next->prev= temp->prev;
            delete temp;
        }
        void delete_pos(int pos){
            node* temp=head;
            if (head == nullptr)
			    return;
            if (pos == 0){
			head = temp->next;
			if (head)
				head->prev = NULL;
			delete temp;
			return;
		}
        for (int i = 0; i < pos && temp != nullptr; i++)
			        temp = temp->next;
        if (temp == NULL)
			return;
            
        temp->prev->next=temp->next;
            if(temp->next!=NULL)
                    temp->next->prev= temp->prev;
            delete temp;
        }
        
        //----------- display -----------
        void display(){
            node* temp = head;
            while (temp !=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};
int main(){
    doublylinkedlist k;
    k.insertend(10);
    k.insertend(20);
    k.insertend(30);
    k.insertend(10);
    k.insertend(20);
    k.insertend(30);
    k.isert_postion(100,0);
    k.isert_postion(100,4);
    k.delete_item(100);
    k.delete_item(100);
    k.delete_pos(0);
    k.display();
    return 0;
}