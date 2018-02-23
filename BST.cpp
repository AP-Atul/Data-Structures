

#include <iostream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

class Node
{
public:
	string word;
	string meaning;
	Node *left;
	Node *right;
};


class BST
{
public:
	Node *root=NULL;


		void inorder(Node *t)
	{
		if(t)
		{
		inorder(t->left);
		cout<<"\nWORD: "<<t->word<<" MEANING: "<<t->meaning;
		inorder(t->right);
		}
	}
		void postorder(Node *t)
	{
		if(t)
		{
		postorder(t->right);
		cout<<"\nWORD: "<<t->word<<" MEANING: "<<t->meaning;
		postorder(t->left);
		}
	}

		void create()
	{
		Node *t=new Node;
		cout<<"\nEnter WORD and its MEANIING\n";
		cin>>t->word;
		cin>>t->meaning;
		t->left=NULL;
		t->right=NULL;
		if(root==NULL)
		{
			root=t;
		}
		else
		{
			Node *n=new Node;
			n=root;
			string str1,str2;
			str1=n->word;
			str2=t->word;
			while(true)
			{
				if(strcmp(n->word.c_str(),t->word.c_str())>0)
				{
					if(n->left==NULL)
					{
						n->left=t;
						break;
					}

					n=n->left;

				}
				else if(strcmp(n->word.c_str(),t->word.c_str())<0)
				{
					if(n->right==NULL)
					{
						n->right=t;
						break;
					}

					n=n->right;
				}

				else
				{
					cout<<"\nWord repeated\n";
					cout<<"\nAgain enter word and its meaning\n";
					cin>>t->word;
					cin>>t->meaning;

				}}}}
		void Search(Node *rt)
	{
	string key;
	cout<<"\nEnter the word you want to search";
	cin>>key;
	if(rt)
	{
		while(true)
		{
				if(rt==NULL)
				{
					cout<<"\nNOT FOUND\n";
					break;
				}

				if(strcmp(rt->word.c_str(),key.c_str())>0)
				{

					rt=rt->left;

				}
				else if(strcmp(rt->word.c_str(),key.c_str())<0)
				{


					rt=rt->right;


				}

				else
				{
					cout<<"\nFOUND: "<<" WORD - "<<rt->word<<" MEANING - "<<rt->meaning;
					break;
				}
		}
	}
	else
	{
		cout<<"\nNot FOund....";
	}
	}
		void Update(Node *rt)
		{
		string key;
			cout<<"\nEnter the word you want to search";
			cin>>key;
			if(rt)
			{
			while(true)
			{
					if(rt==NULL)
					{
						cout<<"\nNOT FOUND\n";
						break;
					}

					if(strcmp(rt->word.c_str(),key.c_str())>0)
					{
						rt=rt->left;
					}
					else if(strcmp(rt->word.c_str(),key.c_str())<0)
					{
						rt=rt->right;
					}

					else
					{
						cout<<"\nFOUND: "<<" WORD - "<<rt->word<<" MEANING - "<<rt->meaning;
						cout<<"\nEnter the new meaning you want give:";
						cin>>rt->meaning;
						cout<<"\nUpdated Values:";
						cout<<"\nWORD - "<<rt->word<<" MEANING - "<<rt->meaning;
						break;
					}
			}
			}
			else
			{
				cout<<"\nNot FOund....";
			}
		}
		Node* getRoot()
	{
		return root;
	}
		Node* operator=(Node* rt)
	{
		Node *t=new Node;
		 if(!rt)
		 {
			 return NULL;
		 }
		 else
		 {
			 t->left=rt->left;
			 t->right=rt->right;
			 t->word=rt->word;
		 }
		 return t;
	}
		void Comparison(Node* rt)
	{
		string key;int count=0;
			cout<<"\nEnter the word you want to search :: ";
			cin>>key;
			if(rt)
			{
				while(true)
				{
						if(rt==NULL)
						{
							cout<<"\nNOT FOUND\n";
							break;
						}

						if(strcmp(rt->word.c_str(),key.c_str())>0)
						{

							rt=rt->left;count++;

						}
						else if(strcmp(rt->word.c_str(),key.c_str())<0)
						{


							rt=rt->right;count++;
						}

						else
						{
							cout<<"\nFOUND: "<<" WORD - "<<rt->word<<" MEANING - "<<rt->meaning;
							count++;break;
						}
				}
			}
			else
			{
				cout<<"\nNot FOund....";
			}
			cout<<"\nNumber of Comparison required :: "<<count;
	}
		void mindel(Node *n)
		{
			Node *temp=new Node;
			temp=n;
			n=n->right;
			Node *p;

			while(n->left!=NULL)
			{
				p=n;
				n=n->left;
			}

			temp->word=n->word;
			temp->meaning=n->meaning;

			if(n->left==NULL&&n->right==NULL)
			{
				leafdel(n,p);
				return;
			}

			else if(n->left==NULL||n->right==NULL)
			{
				onechild(n,p);
				return;
			}

		}

		void leafdel(Node *n,Node *p)
		{
			if(p->left==n)
				p->left=NULL;

			if(p->right==n)
				p->right=NULL;

			delete n;


		}

		void onechild(Node *n,Node *p)
		{
			if(n->left==NULL)
			{
				if(p->left==n)
					p->left=n->right;

				if(p->right==n)
					p->right=n->right;

				delete n;


			}
			else if(n->right==NULL)
			{
				if(p->left==n)
					p->left=n->left;

				if(p->right==n)
					p->right=n->left;

				delete n;


			}



		}

		void deletefun(Node *t)
		{
			Node *n=new Node;
			Node *p;
			n=root;

				string find;
				cout<<"\nEnter word to delete\n";
				cin>>find;

				while(true)
				{
					if(n==NULL)
					{
						cout<<"\nNOT FOUND\n";
						break;
					}

					if(strcmp(n->word.c_str(),find.c_str())>0)
					{
						p=n;
						n=n->left;

					}
					else if(strcmp(n->word.c_str(),find.c_str())<0)
					{

						p=n;
						n=n->right;


					}

					else
					{

						if(n->left==NULL&&n->right==NULL)
						{
							leafdel(n,p);
							return;
						}

						else if(n->left==NULL||n->right==NULL)
						{
							onechild(n,p);
							return;
						}

						else
						{

							mindel(n);
							return;

						}


					}

				}

		}
};


int main()
{
	BST t,t1;
	Node *m=new Node;
	int choice;
	bool run=true;
	while(run)
	{
		cout<<"\nEnter your choice:\n";
		cout<<"\n1.Insert";
		cout<<"\n2.Search";
		cout<<"\n3.Update";
		cout<<"\n4.Copy (=) ";
		cout<<"\n5.MaxComparisons";
		cout<<"\n6.Display(Ascending)";
		cout<<"\n7.Display(Descending)";
		cout<<"\n8.Delete";
		cout<<"\n9.Exit";
		cin>>choice;

		switch(choice)
		{
		case 1:
			t.create();
			break;

		case 2:
			m=t.getRoot();
			t.Search(m);
			break;

		case 3:
			m=t.getRoot();
			t.Update(m);
			break;

		case 4:
			t1.root=t.root;
			t1.inorder(t1.getRoot());
			break;

		case 5:
			t.Comparison(t.getRoot());
			break;

		case 6:
			m=t.getRoot();
			t.inorder(m);
			break;

		case 7:
			m=t.getRoot();
			t.postorder(m);
			break;

		case 8:
			t.deletefun(t.getRoot());
			break;

		case 9:
			run=false;cout<<"\nRequest Exited.";break;
		}
	}

return 0;
}
