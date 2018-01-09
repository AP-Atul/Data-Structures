//Program for simulating DEqueue
#include<iostream>
#define MAX 10
using namespace std;

class DQ
{
    int rear,front;
    int arr[MAX];
public:
    DQ()
    {
        front=-1;
        rear=-1;
    }
    void addfront(int a);
    void addrear(int a);
    void delrear();
    void delfront();
    void display();
};
void DQ::addfront(int a)
{
    rear++;
    if(front==-1)
    {
        front++;
        arr[front]=a;
    }
    else if(rear>=front&&rear!=MAX-1)
    {
        for(int i=rear;i>=front;i--)
        {
            cout<<front;
            arr[i+1]=arr[i];
        }
        arr[front]=a;
    }
    else
    {
        cout<<"\nQueue overflow..";
    }
    cout<<"\nRear=="<<rear;
}
void DQ::addrear(int a)
{
    cout<<rear;
    if(rear!=MAX-1)
    {
        rear++;
        arr[rear]=a;
    }
    else
    {
        cout<<"\nQueue overflow..";
    }
}
void DQ::delrear()
{
    int a;
    if(rear>front)
    {
        a=arr[rear];
        rear--;
        cout<<"\nElement deleted is::"<<a;
    }
    else
    {
        cout<<"\nQueue underflow..";
    }
}
void DQ::delfront()
{
    int a;
    if(front<=rear)
    {
        a=arr[front];
        front++;
        cout<<"\nElement deleted is::"<<a;
    }
    else
    {
        cout<<"\nQueue underflow..";
    }
}
void DQ::display()
{
    cout<<"\nElements are::";
    for(int i=front;i<=rear;i++)
        cout<<" "<<arr[i];
}
int main()
{
    int opt,a;
    bool run=true;
    DQ d;

    while(run)
    {
        cout<<"\nEnter your choice:";
        cout<<"\n1.Read array elements.";
        cout<<"\n2.Add from front.";
        cout<<"\n3.Add from rear.";
        cout<<"\n4.Delete from front.";
        cout<<"\n5.Delete from rear.";
        cout<<"\n6.Display.";
        cout<<"\n7.Exit.";
        cin>>opt;

        switch(opt)
        {
            //case 1:d.read();break;
            case 2:cout<<"\nEnter element to insert:";cin>>a;d.addfront(a);break;
            case 3:cout<<"\nEnter element to insert:";cin>>a;d.addrear(a);break;
            case 4:d.delfront();break;
            case 5:d.delrear();break;
            case 6:d.display();break;
            case 7:cout<<"\nRequest exited.";run=false;break;
            default: cout<<"\nenter valid option..";
        }
    }
    return 0;
}
