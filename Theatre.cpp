#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node    //Structure for Node i: user information (seat)
{
    int flag;
    char movie_name[20];
    char name[20];
    long mno;
    node *next;
    node *prev;
};

struct hnode  //Header node (stores metadata of each row)
{
    node *next;  //Stores the first address node address of each row.
    int cnt;     //Sotres the number of node(book) in list.
};

class Cinemax   //class name
{
    hnode *head[11]; //array of pointer of type hnode to store ten rows address.
    node *temp,*t1,*p; //data memebers.
    int n,i,j;
   public:
    Cinemax()  //default costructor
    {
     for(i=1;i<=10;i++)
     {
      head[i]=new hnode;
          head[i]->next= NULL;   //INITIALIZATION OF HEADE ARRAY
      head[i]->cnt=0;
     }
     temp=t1=p=NULL;
     n=i=j=0;        //initialization of all data members.
    }

    void create();
    void show();
    int book_my_show(int,int,char[]);     //Member Functions Declarations.
    int cancel_my_show(int,int,char[]);
}; //end of class definition.


//Function : To book the theoter movie show logic is here..
//No of arguments passed : 03
//1. Row number 2. Number of Tickets 3.Movie name
int Cinemax::book_my_show(int r,int n,char name[20])
{
  cout<<"\nYou request for "<<n <<" Tickets of "<<name<<" movie: \n";
  temp=head[r]->next;
  int max;
  max=head[r]->cnt; //Stores the counter of booked seat.
  if(max==7)
  {
   cout<<"\nSorry there is no seat avialable in this row..";
   return 0;
  }
  else
  {
   int seat[5],cnt=0,sn;
   for(i=0;i<n;i++) //accept the seat number from user to book
   {
    cout<<"\nEnter the seat no's: ";
    cin>>sn;
    seat[i]=sn-1;// store seat number in array.
   }
   i=0;
   while(temp->next!=head[r]->next)//Check upto the last element of list
   {
    if(cnt!=seat[i])
    {
     cnt++;   //if seat no is not equal move forward
     temp=temp->next;
    }
    else
    {
     if(temp->flag==0)//if flag is zero that means seat is not booked.
     {
      strcpy(temp->movie_name,name);
      temp->flag=1;
      cout<<"\nEnter u r name:";  //Store all the user information for that book seat
      cin>>temp->name;
      cout<<"\nEnter u r mobile no: ";
      cin>>temp->mno;
      head[r]->cnt=head[r]->cnt+1; //increment the header counter by one
      cnt=0;  //make the counter zero for next booking of seat
      temp=head[r]->next; //point the temp first node of list for next booking seat.
      i++; //increment the indes of seat array for next seat booking.
      if(i==n)  //if all the seat gets book exit from the loop.
        break;
     }
    }
   }
 }
 if((temp->next==head[r]->next)) //Due to the above while condition last node is always out of the logic.
 {
  if(temp->flag==0)              //To store last node booking this code works.
  {
   strcpy(temp->movie_name,name);
   temp->flag=1;
   cout<<"\nEnter u r name:";
   cin>>temp->name;
   cout<<"\nEnter u r mobile no: ";
   cin>>temp->mno;
   head[r]->cnt=head[r]->cnt+1; //increment the header node counter by one.
  }
 }
 return 1; //return value 1 for successful completion of booking.
}


//Function : To cancel the theoter movie show logic is here..
//No of arguments passed : 03
//1. Row number 2. Number of Tickets 3.Movie name

int Cinemax::cancel_my_show(int r,int n,char name[20])
{
  cout<<"\nYour cancel request for "<<n <<" Tickets of "<<name<<" movie: \n";
  temp=head[r]->next;
  int max;
  max=head[r]->cnt; // store the no of nodes booked in row.
  if(max==-1) //check if the list is empty means no booking and still try to cancel.
  {
   cout<<"\nSorry there is no such seat avialable in this row for cancel..";
   return 0; //return 0 for unsuccessful try.
  }
  else
  {
   int seat[5],cnt=0,sn;
   for(i=0;i<n;i++) //Accept seat number from user to cancel the booking.
   {
    cout<<"\nEnter the seat no's: ";
    cin>>sn;
    seat[i]=sn-1; //Store cancel seat number in array seat[].
   }
   i=0;
   while(temp->next!=head[r]->next) //Check upto the last element of list
   {
    if(cnt!=seat[i])
    {
     cnt++;     //if seat number is not matches.
     temp=temp->next; // move to the next seat.
    }
    else
    {
     if(temp->flag==1) //if seat number matches check its flag if it is 1 that means seat is booked.
     {
      strcpy(temp->movie_name,"NIL"); // initialize all its feild to NIL value.
      temp->flag=0;                   // make it's flag 0 means not booked seat is vaccant for booking.
      strcpy(temp->name,"NIL");
      temp->mno=00;
      head[r]->cnt=head[r]->cnt-1;  //Decrement the header count by 1
      cnt=0;   //make the counter zero for next seat number to make it cancel.
      temp=head[r]->next; //point your temp to the first node of list.
      i++;  //increment i for the next seat number to cancel
      if(i==n)  //if all the seat gets cancel exit from the loop.
        break;
     }
    }
   }
 }
 if((temp->next==head[r]->next)) //Due to the above while condition last node is always out of the logic.
 {
  if(temp->flag==1)  //check the status of last node if flag is 1 means seat is booked and ready for cancel.
  {
   strcpy(temp->movie_name,"NIL");
   temp->flag=0;                    //make the flag 0 to indicate seat is vaccant.
   strcpy(temp->name,"NIL");
   temp->mno=00;                 //initialize all other value with NIL & ZERO.
   head[r]->cnt=head[r]->cnt-1;  //Decrement the header counter by one.
  }
 }
 return 1; //Return one for successful cancelletion.
}

//Function: To create the Doubly circular linked list for cinemax theoter booking
//no of arguments zero.

void Cinemax::create()
{
    node *f1;
    cout<<"\n\n!!!!!!!!!!!! Welcome To Cinemax Theoter!!!!!!!!!!\n";
    for(i=1;i<=10;i++)
    {
        p = new node;  // Allocate the memory for node
        p->next=NULL;   // initialize all feilds.
        p->prev=NULL;
        p->flag=0;
        strcpy(p->movie_name,"NIL");
        strcpy(p->name,"NIL");
        p->mno=0;

        if(head[i]->next==NULL)//check header next of each row if it null store this node as first node of that row
        {
         head[i]->next= p; //store the address of p in next feild of i th row header node.
         p->prev=p; //initially it's prev and next point to itself i:e p only.
         p->next=p;
        }
        //cout<<"\nAdding the row : "<<i <<" : information\n";

            temp=head[i]->next; // Here onwards we are adding the remaining six node in DCLL.
            f1=temp; //Storing the first node address in this pointer to point to the prev of first node.
            for(j=1;j<=6;j++)//wants to add six node
            {
                t1=new node; // Allocate memeory for node
                t1->flag=0;
                t1->mno=0;   //initialize all it's memory feilds.
                strcpy(t1->movie_name,"NIL");
                strcpy(t1->name,"NIL");

                t1->next=head[i]->next; //last node always points to the first node of list in DCLL.
                temp->next=t1; //join the new new node at end of list.
                t1->prev=temp; //new node prev is the previous node address of list.
                f1->prev=t1; //First node always points to the last node of list in DCLL.
                temp=t1; //make the new node (t1) as previous node (temp) for upcoming new node (t1).
            }
            //cout<<"\n Row Number : "<<i<<" : gets created....\n";
     }

}

//Function: To display the whole theoter booking status.
//how any seats are book or how many are vaccant.
//No of arguments zero.
void Cinemax::show()
{
    cout<<"Rows Status are as follows...\n";
    cout<<"\nHead Node\tCol1\t\tCol2\t\tCol3\t\tCol4\t\tCol5\t\tCol6\t\tCol7"; //To display column of the theator.
    for(i=1;i<=10;i++)//Total ten rows and each row seven seats we want to display.
    {
        cout<<"\nRow : "<<i;
        temp=head[i]->next; //Storing the address of i th row in temp to display.
         cout<<"[ "<<head[i]->cnt<<" ]--->"; //show no of nodes booked in the i th row.
        while(temp->next!=head[i]->next) //Travese upto the last node by this condition.
        {
         cout<<"[ "<<temp->flag<<"|"<<temp->movie_name<<"|"<<temp->name<<"]->"; //display flag value, name of movie & name of Ticket holder.
         temp=temp->next; //move towards the next seat.
        }
        if(temp->next==head[i]->next) //Due to the above while condition last node is out of code.
        {
         cout<<"[ "<<temp->flag<<"|"<<temp->movie_name<<"|"<<temp->name<<"]->";//displaying the last node containt.
        }
        cout<<"\n\n";
    }
}

int main()
{
    Cinemax c1; //object of cinemax theoter.
        int row,n,am,ch,amnt=150;
     char mname[20];
    c1.create(); //Function gets call to create the logical view of cinemax theoter.
    do
     {
    cout<< "\n!!!Cinemax Theator!!!" << endl; // prints !!!!!!

    cout<<"\n1.Book_my_Show\n2.Display Seat status\n3.Cancel_my_show"; //Show the options to choose.

    cout<<"\nEnter u R Choice: ";
    cin>>ch;
    switch(ch)
    {
     case 1:cout<<"\nWelcome To Cinemax Theator For Book your Show...\n";
        cout<<"\n Friday's Movies are as follows...\n";
        cout<<"\n1.Mohenjo_Daro\n2.Rustom\n3.Happy_Bag_Jayegi\n4.Bar_Bar_Dekho\n5.Akira\n6.Rangoon\n7.A Flying_Jatt.\n";
        cout<<"\nEnter u r movie name to book the show:(Note: space is not allowed in movie name)::  ";
                cin>>mname;
        c1.show();
        cout<<"\nEnter the row number to book u r ticket: ";
            cin>>row;
        cout<<"\nHow many Tickets u want to Book: ";
        cin>>n;
        am=c1.book_my_show(row,n,mname);
        if(am!=0)
        {
         c1.show();
         cout<<"\n\n Please pay the cash: u r total amount is: "<<amnt*n;;
         cout<<"\n\nYour booking is confirmed please see the status: ..\n\n";
                }
        else
        {
         cout<<"\n\nTry for another row...\n";
         }
                break;
         case 2:cout<<"\n The Booking status of the Cinemax Theator are as follows...\n\n";
        c1.show();
                break;
         case 3:cout<<"\nWelcome To Cinemax Theator For Cancel your Show...";
        cout<<"\nEnter u r movie name to cancel the show:(Note: space is not allowed in movie name)::  ";
                cin>>mname;
        c1.show();
        cout<<"\nEnter the row number to cancel u r ticket: ";
            cin>>row;
        cout<<"\nHow many Tickets u want to Cancel: ";
        cin>>n;
        am=c1.cancel_my_show(row,n,mname);
        if(am!=0)
        {
         c1.show();
         cout<<"\n\n Your total refund amount is: "<<((amnt*n)-50);;
         cout<<"\n\nYour booking is cancel please see the status: ..\n\n";
                }
        else
        {
         cout<<"\n\nTry for another row...\n";
         }
                break;
    }
     }while(ch!=4);


    return 0;
}// end of main function
