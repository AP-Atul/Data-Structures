//============================================================================
// Name        : TeleLines_Graph.cpp
// Author      : Atul Patare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
using namespace std;
#define max 30
int noofcity;
string city[max];
class D
{
	int u,v,w;int n=0;
public:
	friend class T;
	friend class Dlist;
	D(){}
	D(int a,int b,int weight)
	 {
	  u=a;
	  v=b;
	  w=weight;
	 }

};
class Dlist
{
public:
	D data[max];
	 int n;
	public:
	 friend class PhoneGraph;
	 Dlist()
	 { n=0;}
	void sort()
	{
	 D temp;
	 for(int i=1;i<n;i++)
	  for(int j=0;j<n-1;j++)
	   if(data[j].w>data[j+1].w)
	   {
	    temp=data[j];
	    data[j]=data[j+1];
	    data[j+1]=temp;
	   }
	}
	void print()
	{
	 int cost=0;int c1,c2;
	 for(int i=0;i<n;i++)
	 {
	  c1=data[i].u;
	  c2=data[i].v;
	  cout<<"\n"<<i+1<<" "<<city[c1]<<"--"<<city[c2]<<" = "<<data[i].w;
	  cost=cost+data[i].w;
	 }
	 cout<<"\nMinimum cost to travel :: "<<cost<<endl;
	}
};
class T
{
	int M[max][max];
	D data[max];

	int amount;
public:
	T()
	{
		for(int i=0;i<max;i++)
		{
			for(int j=0;j<max;j++)
			{
				city[i]="";
				M[i][j]=0;
			}
		}
		amount=0;
		noofcity=0;
	}
	int getCity(string c1)
	{
		int i=0;
		if(i == -1)
			return 0;
		else
		{
			for(i=0;i<max;i++)
				if(city[i]==c1)
					return i;
		}
		return -1;
	}
	void create()
	{
		string src,des;
		cout<<"\nEnter the number of Cities :: ";
		cin>>noofcity;
		cout<<"Enter their names ::\n";
		for(int i=0;i<noofcity;i++)
		{
			cout<<"Enter city number::"<<i+1<<" :: ";
			cin>>city[i];
		}

		int links;
		cout<<"\nEnter the number of links between the cities :: ";
		cin>>links;
		for(int j=0;j<links;j++)
		{
		cout<<"\nEnter the source :: ";cin>>src;
		cout<<"Enter the destination :: ";cin>>des;
		cout<<"Enter the time required to travel :: ";
		cin>>amount;

		int ind1,ind2;
		ind1=getCity(src);
		ind2=getCity(des);

		for(int i=0 ; i<noofcity ; i++)
		{
			M[ind1][ind2]=amount;
			M[ind2][ind1]=amount;
		}
		}
	}
	void display()
	{
		cout<<"\nThe Adjacency Matrix looks like ::: \n";
		for(int i=0; i<noofcity ;i++)
		{
			for(int j=0; j<noofcity ;j++)
			{
				cout<<setw(5)<<M[i][j];
			}
			cout<<"\n";
		}
	}
	int mincost(int cost[],bool visited[])
	{
	 int min=9999,min_index;
	 for(int i=0;i<noofcity;i++)
	 {
	  if(visited[i]==0 && cost[i]<min)
	  {
	   min=cost[i];
	   min_index=i;
	  }
	 }
	 return min_index;

	}
	void unionComp(int belongs[],int c1,int c2)
	{
	 for(int i=0;i<noofcity;i++)
	 {
	  if(belongs[i]==c2)
	   belongs[i]=c1;
	 }
	}
	int find(int belongs[],int vertexno)
	{
	 return belongs[vertexno];
	}
	int Prim()
	{
		bool visited[max];
		 int parents[max];
		 int cost[max]; //saving minimum cost
		 for(int i=0;i<noofcity;i++)
		 {
		  cost[i]=9999;  //set cost as infinity/MAX_VALUE
		  visited[i]=0; //initialize visited array to false
		 }

		 cost[0]=0; //starting vertex cost
		 parents[0]=-1; //make first vertex as a root
		 int c2[max];
		 for(int i=0;i<noofcity-1;i++)
		 {
		  int k=mincost(cost,visited);
		  visited[k]=1;

		  for(int j=0;j<noofcity;j++)
		  {
		   if(M[k][j] && visited[j]==0 && M[k][j] < cost[j])
		   {
		    parents[j]=k;
		    c2[j]=j;
		    cost[j]=M[k][j];
		   }
		  }
		 }
		 int c1,c;
		 cout<<"\nMinimum Cost Telephone Map:\n";
		 for(int i=1;i<noofcity;i++)
		 {
			 c1=parents[i];
			 c=c2[i];
		  cout<<i<<" "<<city[c]<<"--"<<city[c1]<<" = "<<cost[i]<<endl;
		 }
		 int mincost=0;
		 for (int i = 1; i < noofcity; i++)
		  mincost+=cost[i];
		 return mincost;
	}
	void Kruskal(Dlist &spanlist)
	{
		int belongs[max]; //Separate Components at start (No Edges, Only vertices)
		 int cno1,cno2; //Component 1 & 2
		 Dlist elist;
		 for(int i=1;i<noofcity;i++)
		  for(int j=0;j<i;j++)
		  {
		   if(M[i][j]!=0)
		   {
		    elist.data[elist.n]=D(i,j,M[i][j]); //constructor for initializing edge
		    elist.n++;
		   }
		  }
		 elist.sort(); //sorting in increasing weight order
		 for(int i=0;i<noofcity;i++)
		  belongs[i]=i;

		 for(int i=0;i<elist.n;i++)
		 {
			  cno1=find(belongs,elist.data[i].u); //find set of u
			  cno2=find(belongs,elist.data[i].v); ////find set of v
			  if(cno1!=cno2) //if u & v belongs to different sets
			  {
			   spanlist.data[spanlist.n]=elist.data[i]; //ADD Edge to spanlist
			   spanlist.n=spanlist.n+1;
			   unionComp(belongs,cno1,cno2);
			  }
		 }
	}
	void del_Link(string src,string des)
	{
		int ind=getCity(src);
		int ind1=getCity(des);
		if(ind == -1 || ind1 == -1)
			{cout<<"Cannot Delete..Does not exists\n";return;}
		M[ind][ind1]=0;
		M[ind1][ind]=0;
		display();
	}
	void del_City(string c1)
	{
		int ind=getCity(c1);
		city[ind]="\0";
		if(ind == -1 )
					{cout<<"Cannot Delete..Does not exists\n";return;}
		for(int i=0;i<noofcity;i++)
		{
			M[ind][i]=0;
			M[i][ind]=0;
		}
		display();
	}
	void insert()
	{
		string src,des;int no,i=0;

		cout<<"\nEnter the number of Cities :: ";
		cin>>no;
		noofcity=noofcity+no-1;

		cout<<"Enter their names ::\n";
		for(i=0;i<noofcity;i++)
		{
			if(city[i] == "\0" ){
			cout<<"Enter city number::"<<i+1<<" :: ";
			no--;
			cin>>city[i];}
		}
		for( i=0;i<no;i++)
		{
			if(city[i] != "\0" ){
			cout<<"Enter city number::"<<i+1<<" :: ";
			cin>>city[i];}
		}

		int links;
		cout<<"\nEnter the number of links between the cities :: ";
		cin>>links;
		for(int j=0;j<links;j++)
		{
		cout<<"\nEnter the source :: ";cin>>src;
		cout<<"Enter the destination :: ";cin>>des;
		cout<<"Enter the time required to travel :: ";
		cin>>amount;

		int ind1,ind2;
		ind1=getCity(src);
		ind2=getCity(des);

		for(int i=0 ; i<noofcity ; i++)
		{
			M[ind1][ind2]=amount;
			M[ind2][ind1]=amount;
		}
		}
	}
};
int main()
{
	int opt,cost;
	T t;
	Dlist d;
	bool run=true;
	string c1,c2;


	while(run)
	{
		cout<<"\nEnter your choice :: ";
		cout<<"\n1.Create Database";
		cout<<"\n2.Kruskal's Solution for Traversing";
		cout<<"\n3.Prim's Solution for Traversing";
		cout<<"\n4.Delete a Link between cities";
		cout<<"\n5.Delete a City";
		cout<<"\n6.Insert a City and Links";
		cout<<"\n7.Traverse the Graph";
		cout<<"\n8.Exit";
		cin>>opt;
		switch(opt)
		{
		case 1:
			t.create();
			break;
		case 2:
			t.Kruskal(d);cout<<"\nMinimum Cost Telephone Map:\n";
			d.print();
			break;
		case 3:
			cost=t.Prim();
			cout<<"\nMinimum cost to travel :: "<<cost<<endl;
			break;
		case 4:
			cout<<"\nEnter the source city name :: ";
			cin>>c1;
			cout<<"Enter the destination city name :: ";
			cin>>c2;
			t.del_Link(c1, c2);
			break;
		case 5:
			cout<<"\nEnter the source city name :: ";
			cin>>c1;
			t.del_City(c1);
			break;
		case 6:
			t.insert();
			break;
		case 7:
			t.display();
			break;
		case 8:
			run=false;cout<<"\nRequest Exited....";
			break;
		default:
			cout<<"\nEnter a valid choice from above...";
			break;
		}
	}
	return 0;
}
