//============================================================================
// Name        : Flight_Graph.cpp
// Author      : Atul Patare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 10
using namespace std;
class node
{
 node *next;
 string city;
 int timeCost;
public:
 friend class F;
 node()
 {
  next=NULL;
  city="";
  timeCost=-1;
 }
 node(string city,int weight)
 {
  next=NULL;
  this->city=city;
  timeCost=weight;
 }
};

class F
{

	node *head[max];
	string city1,city2,c;
	int n;
public:
	 F(int num)
	{
	  n=num;
	  for(int i=0;i<n;i++)
	   head[i]=NULL;
	}
	int count=0;
	void readdata(int gType)
	{
	 string city1,city2,tmpcity;
	 int fcost;
	 int flight;
	 for(int i=0;i<n;i++)
	 {
	  head[i]=new node;
	  cout<<"Enter name of City no :"<<i+1<<" :: ";
	  cin>>tmpcity;
	  head[i]->city=tmpcity;
	 }
	 cout<<"\nEnter Number of Flights to insert: ";
	 cin>>flight;
	 if(gType==1)
	 {
	  for(int i=0;i<flight;i++)
	  {
	   cout<<"\nEnter Source:";
	   cin>>city1;
	   cout<<"Enter Destination:";
	   cin>>city2;
	   cout<<"Enter Time:";
	   cin>>fcost;
	   insert(city1,city2,fcost);
	  }
	 }
	 else
	 {
	  for(int i=0;i<flight;i++)
	  {
	   cout<<"\nEnter Source:";
	   cin>>city1;
	   cout<<"Enter Destination:";
	   cin>>city2;
	   cout<<"Enter Time:";
	   cin>>fcost;
	   //insertUndirected(city1,city2,fcost);
	   //cout<<"\ninserted"<<i+1;
	  }
	 }
	}
	int getindex(string s1)
	{
	 for(int i=0;i<max;i++)
	 {
	  if(head[i]->city==s1)
	   return i;
	 }
	 return -1;
	}
	void insert(string city1,string city2,int time)
	{
	 node *source;
	 node *dest=new node(city2,time);

	 int ind=getindex(city1);
	 if(head[ind]==NULL)
	  head[ind]=dest;
	 else
	 {
	  source=head[ind];
	  while(source->next!=NULL)
	   source=source->next;
	  source->next=dest;
	 }
	}
	void OutGoing(string c1)
	{
		int ind=getindex(c1);
		node *tmp=head[ind]->next;
		cout<<"Name of City\tTime Required\n";
		while(tmp!=NULL)
		{
			cout<<tmp->city<<"\t\t\t"<<tmp->timeCost<<"\n";
			tmp=tmp->next;
		}
	}
	void InComing(string c1)
	{
		int i=0;
		cout<<"Name of City\tTime Required\n";
		while(head[i]!=NULL)
		{
			node *tmp=head[i]->next;
			while(tmp!=NULL)
			{
				node *p=tmp;
				if(tmp->city==c1)
				{
					cout<<head[i]->city<<"\t\t\t"<<p->timeCost<<"\n";
				}
				tmp=tmp->next;
			}
			i++;
		}
	}
};
int main() {
	int opt,a,number,type;
	cout<<"\nEnter total Airports ::";
	cin>>number;
	F f(number);
	bool run=true;
	string city_tmp1,city_tmp2,tmp;

	while(run)
	{
		cout<<"1.Create Database";
		cout<<"\n2.Print Incoming Flights";
		cout<<"\n3.Print Outgoing Flights";
		cout<<"\n4.Delete a Flight";
		cout<<"\n5.Delete a City";
		cout<<"\n6.";
		cout<<"\n8.Exit";
		cin>>opt;
		switch(opt)
		{
		case 1:
			cout<<"\nEnter Graph type: 1.Directed 2.UnDirected";
			cin>>type;
			f.readdata(type);
			break;
		case 2:
			cout<<"\nEnter name of the city :: ";
			cin>>tmp;
			f.InComing(tmp);
			break;
		case 3:
			cout<<"\nEnter name of the city :: ";
			cin>>tmp;
			f.OutGoing(tmp);
			break;
		case 8:
			run=false;cout<<"\nExiting";break;
		}
	}
	return 0;
}
