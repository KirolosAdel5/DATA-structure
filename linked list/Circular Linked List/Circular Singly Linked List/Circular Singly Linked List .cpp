#include <bits/stdc++.h>
using namespace std;
class Circulalist{
    struct node{int data;node*next;};
    node*last;
    public:
        Circulalist():last(NULL){}

//-------------insert method--------
        void addToEmpty(int data)
        {
            if (last != NULL)
            return;
            node *temp = new(node);
            temp -> data = data;
            last = temp;
            last -> next = last;
        }
        void insertend(int data){
                 if (last == NULL){
                    addToEmpty(data);return;}
                node *temp=new(node);
                temp -> data = data;
                temp -> next = last -> next;
                last -> next = temp;
                last = temp;
                return;
        }
        void insertbegin(int data){
                 if (last == NULL){
                    addToEmpty(data);return;}
                node *temp=new(node);
                temp -> data = data;
                temp -> next = last -> next;
                last -> next = temp;
        }
        void insert_after( int data, int item) {
            if (last == NULL){
                    addToEmpty(data);return;}
            node *temp, *p;
            p=last -> next;
        do
        {
        if (p ->data == item)
        {
            temp = new(node);
            temp -> data = data;
            temp -> next = p -> next;
             p -> next = temp;
             if (p == last)
                last = temp;
                return;
        }
        p = p -> next;
    
        } while (p != last -> next);
        cout << item << " not present in the list." << endl;return;
        }

//-----remove method---------
        void DeleteFirst()
    {
        node *prev=last,*firstnode=last;
        if (last==NULL){ printf("\nList is empty\n"); return;}
        if (prev->next == prev) {last = NULL;return;}
        firstnode=last->next;
        last->next=firstnode->next;
        free(firstnode);

    }
        void DeleteLast()
    {
        node *previous = last, *firstNode = last;
        if (last == NULL) {
            printf("\nList is empty\n");
            return;
        }
    
        if (previous->next == previous) {
            last = NULL;
            return;
        }
    
        while (previous->next != last) {
            previous = previous->next;
        }
        previous->next = firstNode->next;
        last = previous;
        free(firstNode);
        return;
}
        void DeleteAtPosition(int index){
            int len = Length();
            int count = 1;
            node *previous = last, *next = last;
    
            if (last == NULL) {
                printf("\nDelete Last List is empty\n");
                return;
            }
        
            if (index >= len || index < 0) {
                printf("\nIndex is not Found\n");
                return;
            }
            if (index == 0) {
                DeleteFirst();
                return;
            }
        
            node *x = last,*y=last;  
            while (count-1 <= index)  
            {  
                y = x;  
                x = x->next;  
                count++;  
            }  
            y->next = x->next;  
            free(x);return;  
        }  

//----- find number of nodes present in list---------
        int Length()
            {
            node* current = last;
            int count = 0;
            if (last == NULL) {
                return 0;
            }
            
            else {
                do {
                    current = current->next;
                    count++;
                } while (current != last);
            }
            return count;
            }//-----display method---------

//----- display  method---------
        void display()
            {
                node *p;
                if (last == NULL)
                    {
                        cout << "List is empty." << endl;
                        return;
                    }
            
                p = last -> next;
            
                do
                    {
                        cout << p -> data << " ";
                        p = p -> next;
                    }
                while(p != last->next);
            }
};
int main(){
    Circulalist k;
    k.insertend(10);
    k.insertend(20);
    k.insertend(40);
    k.insertend(50);
    k.insertend(60);
    k.insertend(70);
    k.insertend(80);
    k.DeleteAtPosition(1);

    k.display();

    return 0 ;  
}
