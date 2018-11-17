#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define SIZE 100
using namespace std;

int main()
{
    int UB=SIZE-1,LB=0,MB;
    int data[SIZE];
    int item;
    cout<<"Give item to search: "<<endl;
    cin>>item;
    for(int i=0;i<SIZE;i++)
        data[i]=i+1;
    /*for(int t=0;t<SIZE;t++)
        cout<<data[t]<<" ";*/
    while(1)
    {
        MB=(UB+LB)/2;
        if(item == data[MB])
        {
            cout<<"Item Found"<<endl;
            break;
        }
        else if(LB == UB)
        {
            cout<<"Item Not found"<<endl;
            break;
        }
        else if(item > data[MB])
            LB=MB+1;
        else if(item < data[MB])
            UB=MB-1;
    }
    return 0;
}
