#include <bits/stdc++.h> 
using namespace std; 
class BST{
	struct newnode{
		int data;newnode*left,*right;
		newnode(int value){data=value;left=right=NULL;}
	};

	newnode*root=NULL;

	//------recursive print  ---------------
	void printInorder(newnode* node) 
	{ 
		if (node == NULL) 
			return; 

		/* first recur on left child */
		printInorder(node->left); 

		/* then print the data of node */
		cout << node->data << " "; 

		/* now recur on right child */
		printInorder(node->right); 
	} 
	void printpostorder_helper(newnode* node) 
	{ 
		if (node == NULL) 
			return; 
		/* first recur on left child */
		printpostorder_helper(node->left); 
		/* now recur on right child */
		printpostorder_helper(node->right); 
		/* then print the data of node */
		cout << node->data << " "; 
	} 
	void printpreorder_helper(newnode* node) 
	{ 
		if (node == NULL) 
			return; 
		cout << node->data << " "; 
		printpreorder_helper(node->left); 
		printpreorder_helper(node->right); 

	} 
	//------ recursive add node  ---------------
	void addhelper(newnode*temp,int data){
		if(data<=temp->data){
			if(temp->left==NULL)temp->left=new newnode(data);
			else addhelper(temp->left,data);
		}
		else{
			if(temp->right==NULL)temp->right=new newnode(data);
			else addhelper(temp->right,data);
		}
	}
	
	//------ recursive get max-min  ---------------
	int recursive_getmax_helper(newnode* temp){
		if(temp->right==NULL)return temp->data;
		else
			return recursive_getmax_helper(temp->right);
	}
	int recursive_getmin_helper(newnode* temp){
		if(temp->left==NULL)return temp->data;
		else
			return recursive_getmin_helper(temp->left);
	}
		
	//------ recursive search  ---------------
	bool Recursive_Find_helper(newnode* temp,int value){
		if (temp==NULL)
			return false;
		if (temp->data == value)
			return true;
		else if(value <= temp->data)
			return Recursive_Find_helper(temp->left,value);
		else if (value> temp->data)
			return Recursive_Find_helper(temp->right,value);
	}
	
	//------ recursive remove node  ---------------
	newnode* removeHelper(newnode* root, int data)
	{
		if (root == nullptr) return root;
		
		else if (data < root->data)
			root->left = removeHelper(root->left, data);

		else if (data > root->data)
			root->right = removeHelper(root->right, data);
		
		////////////////////////////////////////////////////////
		else{
			if (root->left == nullptr){
				newnode* temp = root->right;
				delete root;
				return temp;
			}
			
			else if (root->right == nullptr){
				newnode* temp = root->left;
				delete root;
				return temp;
			}

			else{
				int maxValue = this->recursive_getmax_helper(root->left);
				root->data = maxValue;
				root->left = removeHelper(root->left, maxValue);
			}
			
		}
		return root;
	}
	
	//------ destructor  ---------------
	void DestroyBST(Node* temp){
		if (temp == nullptr)
			return;
		DestroyBST(temp->left);
		DestroyBST(temp->right);
		delete temp;
	}
public:		
		//------- insert (add) --------
		void iterative_insert(int data){
			if(root==NULL){root=new newnode(data);return;}
			newnode*temp=root;
			newnode*parent=NULL;
				while (temp!=NULL)
				{	parent=temp;
					if(data <= temp->data)
						temp=temp->left;
					else 
						temp=temp->right;
				}
				data <= parent->data?parent->left=new newnode(data):parent->right=new newnode(data);
			}
		void recursive_insert(int data){
			if(root==NULL)root=new newnode(data);
			else
				addhelper(root,data);
		}
		//------- MAX & MIN element --------
		int iterative_getmax(){
		newnode * temp=root;
		while(temp->right!=NULL){
			temp=temp->right;	
		}
			return temp->data;
		}
		int iterative_getmin(){
			newnode * temp=root;
			while(temp->left!=NULL){
				temp=temp->left;	
			}
			return temp->data;
		}

		int recursive_getmax(){return recursive_getmax_helper(root);}
		int recursive_mintmax(){return recursive_getmin_helper(root);}
		
		//------- remove --------
		void remove(int data)
		{
		root = removeHelper(root, data);
		}
		
		//------- search --------
		bool find(int key)
		{
		newnode*temp=root;
		while (temp != NULL && temp->data != key)
		{
			if (key < temp->data)
			temp = temp->left;
			else 
			temp = temp->right;
		}
		return temp!=NULL;  
		}
		bool Recursive_Find(int key)
		{
			return Recursive_Find_helper(root,key);
		}
		
		//------- display (Traversal) --------
		void printLevelOrder()
		{
			// Base Case
			if (root == NULL)  return;
		
			// Create an empty queue for level order traversal
			queue<newnode *> q;
		
			// Enqueue Root and initialize height
			q.push(root);
		
			while (q.empty() == false)
			{
				// Print front of queue and remove it from queue
				newnode *node = q.front();
				cout << node->data << " ";
				q.pop();
		
				/* Enqueue left child */
				if (node->left != NULL)
					q.push(node->left);
		
				/*Enqueue right child */
				if (node->right != NULL)
					q.push(node->right);
			}
		}
		void prinitinorder()
		{
			printInorder(root);
		}
		void printpostorder()
		{
			printpostorder_helper(root);
		}
		void printpreorder()
		{
			printpreorder_helper(root);
		}
		//------- destructor ---------
	~BST()
	{
		DestroyBST(root);
	}
};
int main(){ 
	BST k;
	k.recursive_insert(10);
	k.recursive_insert(5);
	k.recursive_insert(3);
	k.recursive_insert(7);
	k.recursive_insert(20);
	k.printpostorder();
	k.remove(3);
	cout<<"\n===================\n";
	k.printpostorder();
	return 0; 
} 