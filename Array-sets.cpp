#include<iostream>
#define MAX 10
using namespace std;

class A
{
    int a[MAX],b[MAX],count,M,nc,nb;

public:
    void read();
    void read1();
    void uni();
    void inter();
    void sub1();
    void sub2();
    void none();
    void display();
};
void A::read1()
{
    cout<<"\nEnter total students:";
    cin>>M;
}
void A::read()
{
    int n;
    cout<<"\nEnter the number of elements in arrayA:";
    cin>>n;
    cout<<"\nEnter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        nc++;
    }
    n=0;
    cout<<"\nEnter the number of elements in arrayB:";
    cin>>n;
    cout<<"\nEnter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        nb++;
    }
}
void A::uni()
{
    int u[MAX];
    for(int i=0;i<nc;i++)
    {
        u[i]=a[i];
        count++;
    }
    for(int i=0;i<nb;i++)
    {
        u[nc+i]=b[i];
        count++;
    }
    display();
}

void A::inter()
{
    int in[MAX],k=0;
    for(int i=0;i<nc;i++)
    {
        for(int j=0;j<nb;j++)
        {
            if(a[i]==b[j])
            {
                in[k]=b[j];
                k++;
            }
        }
    }
    display();
}

void A::sub1()
{
    int in[MAX],k=0;
    for(int i=0;i<nc;i++)
    {
        for(int j=0;j<nb;j++)
        {
            if(a[i]!=b[j])
            {
                in[k]=b[j];
                k++;
                in[k]=a[i];
                k++;
            }
        }
    }
    display();
}

void A::sub2()
{
    int in[MAX],k=0;
    for(int i=0;i<nb;i++)
    {
        for(int j=0;j<nc;j++)
        {
            if(a[j]!=b[i])
            {
                in[k]=b[j];
                k++;
                in[k]=a[i];
                k++;
            }
        }
    }
    display();
}

void A::none()
{
    cout<<"\nNumber of student not playing are::"<<M-count;
}

void A::display()
{
    for(int i=0;i<count;i++)
        cout<<a[i];
}

int main()
{
    A a;
    int opt,c,m;
    int a1[MAX],a2[MAX];
    bool run=true;

    while(run)
    {
        cout<<"\nEnter your choice.";
        cout<<"\n0.Read.";
        cout<<"\n1.Union.";
        cout<<"\n2.Intersection.";
        cout<<"\n3.A-B.";
        cout<<"\n4.B-A.";
        cout<<"\n5.M-AUB.";
        cout<<"\n6.Display.";
        cout<<"\n7.Exit..";
        cin>>opt;

        switch(opt)
        {
            case 0:a.read();break;
            case 1:a.uni();break;
            case 2:a.inter();break;
            case 3:a.sub1();break;
            case 4:a.sub2();break;
            case 5:a.none();break;
            case 6:a.display();break;
            case 7:run=false;break;
        }

    }
    return 0;
}
