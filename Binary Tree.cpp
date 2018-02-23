#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	node *left,*right;
	int data;
};

node *root;
class stack
{
	int top=-1;
	node *data[20];
public:
	void push(node *dt)
	{
		top=top+1;
		data[top]=dt;
	}
	node* pop()
	{
		node *t;
		t=data[top];
		top=top-1;
		return t;
	}
	bool isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
};
class BinaryTree
{

	int count,c2;
	public:

		BinaryTree()
	{
			count = 0;
			c2=0;
			root=NULL;
	}

		node* createnewnode()
		{
			node *newnode=new node;
			cout<<"\nEnter data:";
			cin>>newnode->data;
			newnode->left=NULL;
			newnode->right=NULL;
			return newnode;
		}
		void create()
		{

			node  *t=new node;
			t=NULL;
			t=root;
			int flag = 1;
			while(flag==1)
			{
			if(!root)
			{
				root = createnewnode();
				cout<<"\nRoot Created..";
				return;
			}
			else
			{
				char ch;

				cout<<"\n "<<t->data;
				cout<<"\nEnter where you want to insert data( l || r) :: ";
				cin>>ch;
				if(ch=='l'||ch=='L')
				{
					if(t->left==NULL)
					{
						t->left = createnewnode();
						cout<<"\nNode Inserted..";
						flag=0;
					}
					else
					{
						cout<<"\nHeading towards Sub Tree..";
						t = t->left;
					}
				}
				if(ch=='r'||ch=='R')
				{
					if(t->right==NULL)
					{
						t->right = createnewnode();
						cout<<"\nNode Inserted..";
						flag=0;
					}
					else
					{
						cout<<"\nHeading Towards Sub Tree..";
						t = t->right;
					}
				}
			}
			}

		}
		node* getRoot()
		{
			return root;
		}

		void inorder(node *ot)
		{
			if(ot!=NULL)
			{
				inorder(ot->left);
				cout<<" "<<ot->data;
				inorder(ot->right);
			}
		}
		void preorder(node *rot)
		{
			if(rot!=NULL)
			{
				cout<<" "<<rot->data;
				preorder(rot->left);
				preorder(rot->right);
			}

		}
		void postorder(node *rot)
		{
			if(rot!=NULL)
			{
				postorder(rot->left);
				postorder(rot->right);
				cout<<" "<<rot->data;
			}

		}
		void createMirror(node *rt)
		{
			if(!rt)
				return;
			else
			{
				node *newnode;
				newnode = rt;
				createMirror(rt->left);
				createMirror(rt->right);
				newnode = rt->left;
				rt->left = rt->right;
				rt->right = newnode;

			}
		}
		int HeightTree(node *rot)
		{
			if(rot==NULL)
				return 0;

			return 1+max(HeightTree(rot->left),HeightTree(rot->right));

		}
		int countLeaves(node *rot)
		{

			if(rot==NULL)
			{

				return 0;

			}
			else
			{

				if(rot->left==NULL&&rot->right==NULL)
				{

					count++;
				}
				countLeaves(rot->left);
				countLeaves(rot->right);

			}
		return count;
		}
		void cnt()
		{
			count = 0;

		}
		void cnt1()
				{
					c2 = 0;

				}
		int countInternals(node *rot)
				{

					if(rot==NULL)
					{
						return 0;
					}
					else
					{

						if(rot->left!=NULL || rot->right!=NULL)
						{
							c2++;
						}
						countInternals(rot->left);
						countInternals(rot->right);

					}
				return c2;
				}


		void erase(node *rot)
		{
			if(rot==NULL)
				return;

			rot->data=0;
			cout<<"\nData Erased.";
			erase(rot->left);
			erase(rot->right);
		}
		void copy(node *rt)
		{
			if(!rt)
				return;
			else
			{
				node *newnode;
				newnode = rt;
				copy(rt->right);
				copy(rt->left);
				newnode = rt->left;
				rt->left = rt->right;
				rt->right = newnode;
			}
		}
		 node* operator=(node* rt)
		{
			 node *t=new node;
			 if(!rt)
			 {
				 return NULL;
			 }
			 else
			 {
				 t->left=rt->left;
				 t->right=rt->right;
				 t->data=rt->data;
			 }
			 return t;
		}
		 void RecInOder(node *rt)
		 {
			 stack s;
			 while(rt!=NULL || (!s.isEmpty()))
			 {
				 if(rt!=NULL)
				 {
					 s.push(rt);
					 rt=rt->left;
				 }
				 else
				 {
					 rt=s.pop();
					 cout<<" "<<rt->data;
					 rt=rt->right;
				 }
			 }
		 }
		 void RecPreOder(node *rt)
		 {
			 stack s;
			 while(rt!=NULL || (!s.isEmpty()))
			{
				if(rt!=NULL)
				{
					cout<<" "<<rt->data;
					s.push(rt);
					rt=rt->left;
				}
				else
				{
					rt=s.pop();
					rt=rt->right;
				}
			}
		 }
		 void RecPosOder(node *rt)
		 {
			 stack s1,s2;
			 node *curr;
			 if(rt==NULL)
				 return;
			 s1.push(rt);

			 while(!s1.isEmpty())
			 {
				 curr=s1.pop();
				 s2.push(curr);

				 if(curr->left)
					 s1.push(curr->left);
				 if(curr->right)
					 s1.push(curr->right);
			 }
			 while(!s2.isEmpty())
			 {
				 curr=s2.pop();
				 cout<<" "<<curr->data;
			 }
		 }

};

int main()
{
		BinaryTree b,b1,c1;
		node *m,*m1;
		bool run=true;
		int opt;
		int ht,lv,in;
		while(run)
		{
			cout<<"\n\n1.Insert.";
			cout<<"\n2.InOrder Traversal.";
			cout<<"\n3.PreOrder Traversal.";
			cout<<"\n4.PostOrder Traversal.";
			cout<<"\n5.Mirror Image";
			cout<<"\n6.Height of Tree";
			cout<<"\n7.Count Leaves";
			cout<<"\n8.Count Internal Nodes";
			cout<<"\n9.Erase Tree";
			cout<<"\n10.Copy Tree";
			cout<<"\n11.Exit";
			cin>>opt;

			switch(opt)
			{
			case 1:b.create();break;

			case 2:
			cout<<"\nRecursive:\n";b.inorder(root);
			cout<<"\nNon-Recursive:\n";m=b.getRoot();b.RecInOder(m);break;

			case 3:cout<<"\nRecursive:\n";b.preorder(root);
			cout<<"\nNon-Recursive:\n";m=b.getRoot();b.RecPreOder(m);break;

			case 4:cout<<"\nRecursive:\n";b.postorder(root);
			cout<<"\nNon-Recursive:\n";m=b.getRoot();b.RecPosOder(m);break;

			case 5:b.createMirror(root);cout<<"\nMirror Image of Tree is Created";break;

			case 6: ht = b.HeightTree(root);cout<<"\nHeight of Tree is :: "<<ht;break;

			case 7:b.cnt();lv=b.countLeaves(root);cout<<"\n Leaves :: "<<lv;break;

			case 8:b.cnt1();in=b.countInternals(root);cout<<"\nInternal Nodes :: "<<in;break;

			case 9:m=b.getRoot();b.erase(m);break;

			case 10:m=c1.getRoot();m1=b.getRoot();m=m1;c1.inorder(m);break;


			case 11:run=false;cout<<"\nRequest exited.";break;
			}
		}
	return 0;
}
