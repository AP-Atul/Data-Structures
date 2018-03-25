#include<iostream>
#include<string>
#define max 10
using namespace std;

struct node
{
	int key;
	int val;
};

class Hash
{
	int no;
	node hashtable[max];

public:
	Hash()
	{
		no=0;
		for(int i=0;i<max;i++)
		{
			hashtable[i].key=-1;
			hashtable[i].val=-1;
		}
	}

	//modulo hash function
	int hash_function(int key)
	{
		int t;
		t=key%max;
		return t;
	}

	//insertion function without replacement
	void no_replace()
	{
		int val,key;int flag=0;
		cout<<"\nEnter the key :: ";cin>>key;
		cout<<"\nEnter the value :: ";cin>>val;
		int ind=hash_function(key);

		//Checking for the generated index
		if(hashtable[ind].key==-1)
		{
			hashtable[ind].val=val;
			hashtable[ind].key=key;
			flag=1;
		}
		else
		{
			for(int i=ind+1;i<max;i++)
			{
				if(hashtable[i].key==-1){
					hashtable[i].val=val;
					hashtable[i].key=key;
					flag=1;break;
				}
			}
		}
		if(flag == 0)
			cout<<"\nHashtable overflow..";
	}

	//insertion function with replacement
	void replace()
	{
		int val,key;int flag=0;
		cout<<"\nEnter the key :: ";cin>>key;
		cout<<"\nEnter the value :: ";cin>>val;
		int ind=hash_function(key);

		//Checking for the generated index
		if(hashtable[ind].key==-1)
		{
			hashtable[ind].val=val;
			hashtable[ind].key=key;
			flag=1;
		}
		else if(hashtable[ind+1].key==-1)
		{
				hashtable[ind+1].val=val;
				hashtable[ind+1].key=key;
				flag=1;
		}
		else if(hashtable[ind+1].key!=-1)
		{
			int a=ind+1;
				while(hashtable[a].key!=-1)
				{
					a++;
				}
				while(a>ind)
				{
					hashtable[a+1].key=hashtable[a].key;
					hashtable[a+1].val=hashtable[a].val;
					hashtable[a].val=-1;hashtable[a].key=-1;
					a--;
				}
				if(hashtable[ind+1].key==-1)
				{
					hashtable[ind+1].val=val;
					hashtable[ind+1].key=key;
					flag=1;
				}
		}
		if(flag == 0)
			cout<<"\nHashtable overflow..";
	}

	//Search function for both the cases
	void Search()
	{
		int key;
		cout<<"\nEnter the key to search :: ";
		cin>>key;
		int ind=hash_function(key);
		if(hashtable[ind].key==-1)
		{
			cout<<"\nNot Found";
		}
		else
		{
			if(hashtable[ind].key==key)
			{
				cout<<"\nFound at :: "<<ind<<"\tValue :: "<<hashtable[ind].val;
			}
			for(int i=ind;i<max;i++)
			{
				if(hashtable[i+1].key==key)
				{
					cout<<"\nFound at :: "<<i+1<<"\tValue :: "<<hashtable[i+1].val;break;
				}
			}
		}
	}

	//Deleting requested key
	void Delete()
	{
		int key;
		cout<<"\nEnter the key to search :: ";
		cin>>key;
		int ind=hash_function(key);
		if(hashtable[ind].key==-1)
		{
			cout<<"\nNot Found";
		}
		else
		{
			if(hashtable[ind].key==key)
			{
				cout<<"\nFound at :: "<<ind<<"\tValue :: "<<hashtable[ind].val;
				hashtable[ind].val=-1;hashtable[ind].key=-1;
			}
			for(int i=ind;i<max;i++)
			{
				if(hashtable[i+1].key==key)
				{
					cout<<"\nFound at :: "<<i+1<<"\tValue :: "<<hashtable[i+1].val;
					hashtable[i+1].key=-1;hashtable[i+1].val=-1;break;
				}
			}
		}
	}

	//Displaying all the contents
	void Display()
	{
		for(int i=0;i<max;i++)
		{
				cout<<i<<"\tKey :: "<<hashtable[i].key<<"\tValue :: "<<hashtable[i].val;
				cout<<"\n";
		}
	}
};

int main()
{
	Hash h;
	int opt;
	bool run=true;

	while(run)
	{
		cout<<"\n1. Insert with replacement";
		cout<<"\n2. Insert without replacement";
		cout<<"\n3. Search the HashTable";
		cout<<"\n4. Delete the entry";
		cout<<"\n5. Display the contents of HashTable";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice :: ";
		cin>>opt;

		switch(opt)
		{
		case 1:
			h.replace();
			break;
		case 2:
			h.no_replace();
			break;
		case 3:
			h.Search();
			break;
		case 4:
			h.Delete();
			break;
		case 5:
			h.Display();
			break;
		case 6:
			cout<<"\nRequest Exited.";
			run=false;
			break;
		}
	}
	return 0;
}
