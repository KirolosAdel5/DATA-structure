#include <bits/stdc++.h>
using namespace std;
class circlarlinkedlist{
    struct node  
    {  
        struct node *prev;  
        struct node *next;  
        int data;  
    };  
    node *head;
    public:  
        circlarlinkedlist():head(NULL){};
        void insertion_beginning(int item);  
        void insertion_last(int item);  
        void deletion_beginning();  
        void deletion_last();  
        void display();  
        void search(int item);  
};

//--------- insert methods ---------
void circlarlinkedlist::insertion_beginning(int item)  
{  
    node *ptr,*temp;   
    ptr = new(node);  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW"); return;
    }  
  
    ptr->data=item;  
    if(head==NULL)  
        {  
            head = ptr;  
            ptr -> next = head;   
            ptr -> prev = head; 
            return;  
        }    
    temp = head;   
    while(temp -> next != head)  
        {  
            temp = temp -> next;   
        }  
        temp -> next = ptr;  
        ptr -> prev = temp;  
        ptr -> next = head;  
        head -> prev = ptr;  
        head = ptr;     
}  
void circlarlinkedlist::insertion_last(int item)  
{  
    node *ptr,*temp;  
    ptr = new(node);  
        if(ptr == NULL)  
            {  
                printf("\nOVERFLOW"); return; 
            }  
        ptr->data=item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;   
            ptr -> prev = head;  
            return;
        }  
        temp = head;  
        while(temp->next !=head)  
            {  
            temp = temp->next;  
            }  
        temp->next = ptr;  
        ptr ->prev=temp;  
        head -> prev = ptr;  
        ptr -> next = head;     
}  

//--------- deletion methods ---------  
void circlarlinkedlist::deletion_beginning()  
{  
        node *temp;  
        if(head == NULL)  
            {  
                printf("\n UNDERFLOW");  return;
            }  
        if(head->next == head)  
            {  
                head = NULL;   
                free(head);return;  
            }  

        temp = head;   
        while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
        temp -> next = head -> next;  
        head -> next -> prev = temp;  
        free(head);  
        head = temp -> next;  
}  
void circlarlinkedlist::deletion_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  
    {  
        head = NULL;   
        free(head);   
    }  
    else   
    {  
        ptr = head;   
        while(ptr->next != head)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = head;  
        head -> prev = ptr -> prev;    
        free(ptr);  
    }  
}  

//--------- display method ---------
void circlarlinkedlist::display()  
{  
    node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");return;  
    }               
    while(ptr -> next != head)  
        {  
        
            printf("%d ", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);      
}  

//--------- search method ---------
void circlarlinkedlist::search(int item)  
{  
    node *ptr;  
    int i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");return; 
    }  
    if(head ->data == item)  
        {  
        printf("item found at location %d",i+1);  
        flag=0;return;
        }  

    while (ptr->next != head)  
    {  
        if(ptr->data == item)  
        {  
            printf("item found at location %d ",i+1);  
            flag=0;  
            break;  
        }   
        else  
        {  
            flag=1;  
        }  
        i++;  
        ptr = ptr -> next;  
    }  
    
    if(flag != 0)  
    {  
        printf("Item not found\n");
        return;
    }     
          
}  
int main ()  
{  
    circlarlinkedlist k;
    k.insertion_beginning(10);
    k.insertion_beginning(20);
    k.insertion_beginning(30);
    k.insertion_beginning(40);
    k.display();
    k.insertion_last(10);
    k.insertion_last(20);
    k.insertion_last(30);
    k.insertion_last(40);
    k.display();
    k.deletion_beginning();
    k.deletion_beginning();
    k.deletion_beginning();
    k.deletion_beginning();
    k.display();
    k.deletion_last();
    k.deletion_last();
    k.deletion_last();
    k.display();
    k.search(5);
    k.search(10);
    return 0;
}  
