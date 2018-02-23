//Complete C++ program to demonstrate deletion
// in threaded BST
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int info;

    // True if left pointer points to predecessor
    // in Inorder Traversal
    bool lthread;

    // True if right pointer points to predecessor
    // in Inorder Traversal
    bool rthread;
};

// Insert a Node in Binary Threaded Tree
struct Node *insert(struct Node *root, int ikey)
{
    // Searching for a Node with given value
    Node *ptr = root;
    Node *par = NULL; // Parent of key to be inserted
    while (ptr != NULL)
    {
        // If key already exists, return
        if (ikey == (ptr->info))
        {
            printf("Duplicate Key !\n");
            return root;
        }

        par = ptr; // Update parent pointer

        // Moving on left subtree.
        if (ikey < ptr->info)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }

        // Moving on right subtree.
        else
        {
            if (ptr->rthread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }

    // Create a new Node
    Node *tmp = new Node;
    tmp -> info = ikey;
    tmp -> lthread = true;
    tmp -> rthread = true;

    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }

    return root;
}

// Returns inorder successor using left
// and right children (Used in deletion)
struct Node *inSucc(struct Node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;

    ptr = ptr -> right;
    while (ptr->right)
        ptr = ptr->left;

    return ptr;
}

// Returns inorder successor using rthread
// (Used in inorder)
struct Node *inorderSuccessor(struct Node *ptr)
{
    // If rthread is set, we can quickly find
    if (ptr -> rthread == true)
        return ptr->right;

    // Else return leftmost child of right subtree
    ptr = ptr -> right;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    return ptr;
}
Node* preorderSuc(Node* c)
{
	if (c->lthread==1)
	{
		return c->left;

	}
	while(c->rthread==0)
	{
		c=c->right;
	}
	return c->right;
}
// Printing the threaded tree
void inorder(struct Node *root)
{
    if (root == NULL)
        printf("Tree is empty");

    // Reach leftmost Node
    struct Node *ptr = root;
    while (ptr -> lthread == false)
        ptr = ptr -> left;

    // One by one print successors
    while (ptr != NULL)
    {
        printf("%d ",ptr -> info);
        ptr = inorderSuccessor(ptr);
    }
}

struct Node *inPred(struct Node *ptr)
{
    if (ptr->lthread == true)
        return ptr->right;

    ptr = ptr->left;
    while(ptr->rthread)
        ptr = ptr->right;
    return ptr;
}
void preorder(Node *root)
{
	if (root == NULL)
	        printf("Tree is empty");

	    // Reach leftmost Node
	    struct Node *ptr = root;
	    while (ptr -> lthread == false)
	        ptr = ptr -> right;

	    // One by one print successors
	    while (ptr != NULL)
	    {
	        printf("%d ",ptr -> info);
	        ptr = preorderSuc(ptr);
	    }
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseA(struct Node *root, struct Node *par,
                                       struct Node *ptr)
{
    // If Node to be deleted is root
    if (par == NULL)
        root = NULL;

    // If Node to be deleted is left
    // of its parent
    else if (ptr == par->left)
    {
        par->lthread = true;
        par->left = ptr->left;
    }
    else
    {
        par->rthread = true;
        par->right = ptr->right;
    }

    // Free memory and return new root
    free(ptr);
    cout<<"\nDeletion Successful..";
    return root;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseB(struct Node *root, struct Node *par,
                                       struct Node *ptr)
{
    struct Node *child;

    // Initialize child Node to be deleted has
    // left child.
    if (ptr->lthread == false)
        child = ptr->left;

    // Node to be deleted has right child.
    else
        child = ptr->right;

    // Node to be deleted is root Node.
    if (par == NULL)
        root = child;

    // Node is left child of its parent.
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    // Find successor and predecessor
    Node *s = inSucc(ptr);
    Node *p = inPred(ptr);

    // If ptr has left subtree.
    if (ptr->lthread == false)
        p->right = s;

    // If ptr has right subtree.
    else
    {
        if (ptr->rthread == false)
            s->left = p;
    }

    free(ptr);
    cout<<"\nDeletion Successful..";
    return root;
}

// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseC(struct Node *root, struct Node *par,
                                       struct Node *ptr)
{
    // Find inorder successor and its parent.
    struct Node *parsucc = ptr;
    struct Node *succ = ptr -> right;

    // Find leftmost child of successor
    while (succ->left != NULL)
    {
        parsucc = succ;
        succ = succ -> left;
    }

    ptr->info = succ->info;

    if (succ->lthread == true && succ->rthread == true)
        root = caseA(root, parsucc, succ);
    else
        root = caseB(root, parsucc, succ);

    cout<<"\nDeletion Successful..";
    return root;
}

// Deletes a key from threaded BST with given root and
// returns new root of BST.
struct Node *delThreadedBST(struct Node* root, int dkey)
{
    // Initialize parent as NULL and ptrent
    // Node as root.
    struct Node *par = NULL, *ptr = root;

    // Set true if key is found
    int found = 0;

    // Search key in BST : find Node and its
    // parent.
    while (ptr != NULL)
    {
        if (dkey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found == 0)
        printf("dkey not present in tree\n");

    // Two Children
    else if (ptr->lthread == false && ptr->rthread == false)
        root = caseC(root, par, ptr);

    // Only Left Child
    else if (ptr->lthread == false)
        root = caseB(root, par, ptr);


    // Only Right Child
    else if (ptr->rthread == false)
        root = caseB(root, par, ptr);

    // No child
    else
        root = caseA(root, par, ptr);

    return root;
}



// Driver Program
int main()
{
    struct Node *root = NULL;


    	int value;
    	int choice;
    	bool run=true;
    	while(run)
    	{
    	cout<<"\n1.Create Tree.""\n2.InOrder Traversal""\n3.PreOrder Traversal""\n4.Delete a node""\n5.Exit""\nEnter your choice:";
    	cin>>choice;
    		switch(choice)
    		{
    		case 1:
    			cout<<"\nEnter number(data):";
    			cin>>value;
    			root=insert(root,value);
    			break;
    		case 2:
    			cout<<"\nInorder traversal of TBT:\n";
    			if(root!=NULL)
    			{
    			inorder(root);}
    			else
    				cout<<"Tree Empty...";
    			break;
    		case 3:
				cout<<"\nPreOrder traversal of TBT:\n";
				if(root!=NULL){
				preorder(root);}
				else
					cout<<"Tree Empty...";
				break;
    		case 4:
    			int d;
    			cout<<"\nEnter data to delete:";
    			cin>>d;
    			root=delThreadedBST(root,d);
    			//inorder(root);
    			break;
    		case 5:
    			run=false;
    			break;
    		default:
    			cout<<"\nWrong choice.";
    		}
    	}
    	return 0;
}
