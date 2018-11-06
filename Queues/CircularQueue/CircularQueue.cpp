#include<stdio.h>
#include<iostream>
#include<string.h>
#define SIZE 5
using namespace std;

class queue
{
    int data[SIZE];
    int front;
    int rear;
public:
    void enq(int a)
    {
        if((rear+1)%SIZE==front)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear=(rear+1)%SIZE;
        data[rear]=a;
    }
    int deq()
    {
        if(rear==front)
        {
            return -9999;
        }
        front=(front+1)%SIZE;
        int v=data[front];
        return v;
    }
    queue()
    {
        front=SIZE-1;
        rear=SIZE-1;
    }
    void display()
    {
            cout<<endl;
            int r=rear;
            int f=front;
            while((f+1)%SIZE!=(r+1)%SIZE)
            {
                f=(f+1)%SIZE;
                cout<<data[f]<<endl;
            }
            cout<<endl;
    }
};

void menu()
{
    cout<<"#####################################"<<endl;
    cout<<"########## CIRCULAR QUEUE ###########"<<endl;
    cout<<"Choose the following options- "<<endl;
    cout<<"1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit"<<endl;
}
int main()
{
    queue q1;
    int quit=0,choice,value;
    menu();
    while(!quit)
    {
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter value to be inserted"<<endl;
                    cin>>value;
                    q1.enq(value);
                    break;
            case 2: value=q1.deq();
                    if(value==-9999)
                        cout<<"Queue Underflow"<<endl;
                    else
                        cout<<"Popped item is: "<<value<<endl;
                    break;
            case 3: q1.display();
                    break;
            case 4: quit++;
                    break;
            default: cout<<"Wrong input recieved"<<endl;
        }
    }
    return 0;
}
