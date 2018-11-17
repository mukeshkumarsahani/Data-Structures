#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;


class node
{
    public:
    int data;
    node* leftChild;
    node* rightChild;
};


class tree
{
    node *root;
    int size;
    public:
    tree()
    {
        size = 0;
        root = NULL;
    }
    void insert(int);
    node* search(int);
	void printInorder();
	void printPreorder();
	void printPostorder();
	void printLevelorder();
	int heightTree();
};

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(node* root)
{
	if(root == NULL)
		return -1;
	return max(height(root->leftChild), height(root->rightChild)) + 1;
}

void inorder(node* root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->leftChild);
	cout<<root->data<<"\t"<<endl;
	inorder(root->rightChild);
}

void preorder(node* root)
{
	if(root == NULL)
	{
		return;
	}

	cout<<root->data<<"\t"<<endl;
	preorder(root->leftChild);
	preorder(root->rightChild);
}

void postorder(node* root)
{
	if(root == NULL)
	{
		return;
	}

	postorder(root->leftChild);
	postorder(root->rightChild);
	cout<<root->data<<"\t"<<endl;
}

node* insertNode(node* root, int value)
{
	if (root == NULL)
	{
		node* newNode = new node;
		if (newNode == NULL)
		{
			cout<<"Unable to allocate memory"<<endl;
			return NULL;
		}
		newNode->data = value;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		root = newNode;
		return root;
	}
	else if(root->data == value)
	{
		cout<<"Item is already available, can't insert"<<endl;
		return root;
	}
	else if (root->data > value)
	{
		root->leftChild = insertNode(root->leftChild, value);
		return root;
	}
	else if (root->data < value)
	{
		root->rightChild = insertNode(root->rightChild, value);
		return root;
	}
}

void tree :: insert(int value)
{
	/*As Argument will be a copy of actual node, so changes made in argument is assigned to the actual one*/
	root = insertNode(root, value);
}


/*void tree :: insert(int value)
{
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == null)
    {
        cout<<"unable to allocate memory"<<endl;
        return;
    }
    newnode->data = value;
    newnode->leftchild = null;
    newnode->rightchild = null;
    if(root == null)
    {
        root = newnode;
    }
    else
    {
        node *current;
        current = root;
        while(current != null)
        {
            if(value>current->data)
            {
                if(current->rightchild == null)
                {
                    current->rightchild = newnode;
                    break;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            else if(value<current->data)
            {
                if(current->leftchild == null)
                {
                    current->leftchild = newnode;
                    break;
                }
                else
                {
                    current = current->leftchild;
                }
            }
            else
                return;
        }
    }
    size++;
}*/

void menu()
{
    cout<<"###############################"<<endl;
    cout<<"############# TREE ############"<<endl;
    cout<<"1. Insert\n2. Search\n3. Delete\n4. Print Preorder\n5. Print Inorder\n6. Print Postorder\n7. Print Level Order\n8. Height of tree\n9. Exit"<<endl;
}

node* tree :: search(int value)
{
    node* current = root;
    while(current != NULL)
    {
        if(current->data == value)
        {
            return current;
        }
        else if(current->data>value)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
    return NULL;
}

void tree :: printPreorder()
{
	preorder(root);
}

void tree :: printInorder()
{
	inorder(root);
}

void tree :: printPostorder()
{
	postorder(root);
}

int tree :: heightTree()
{
	return height(root);
}

void tree :: printLevelorder()
{
	if(root == NULL)
		return;
	
	queue<node*> pipe;
	pipe.push(root);
	node* current;
	
	while(!pipe.empty())
	{
		current = pipe.front();
		cout<<current->data<<"\t";
		if (current->leftChild != NULL)
			pipe.push(current->leftChild);
		if (current->rightChild != NULL)
			pipe.push(current->rightChild);
		pipe.pop();
	}
}

int main()
{
    tree BST;
    menu();
    int choice,value,quit = 0;
    while(!quit)
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter value to insert"<<endl;
                    cin>>value;
                    BST.insert(value);
                    break;
            case 2: cout<<"Enter the element you want to search: ";
                    cin>>value;
                    node *temp;
                    temp = BST.search(value);
                    if(temp == NULL)
                    {
                        cout<<"Item not found"<<endl;
                    }
                    else
                    {
                        cout<<"Item is at location: "<<temp<<endl;
                    }
                    break;
            case 3: 
                    
                    break;
            case 4: BST.printInorder();	
                    break;
            case 5: BST.printPreorder();	
                    break;
            case 6: BST.printPostorder();	
                    break;
			case 7: BST.printLevelorder();
					break;
			case 8: cout<<"Height of Tree= "<<BST.heightTree()<<endl;
					break;
            case 9: quit++;
                    break;
            default: cout<<"Wrong Input recieved"<<endl;
        }
    }
    return 0;
}
