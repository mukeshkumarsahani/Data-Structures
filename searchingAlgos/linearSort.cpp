#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define SIZE 100
using namespace std;

int main()
{
    int a[SIZE];
    for(int i=0;i<SIZE-2;i++)
        a[i]=i+1;

    cout<<"Enter the element you want to search: ";
    cin>>a[SIZE-1];
    try
    {
        for(int j=0;j<SIZE-1;j++)
        {
            if(a[j]==a[SIZE-1])
             {
                cout<<"Element found at position "<<j+1<<endl;
                exit(0);
             }
        }
        throw 0;
    }
    catch(int &ex)
    {
        cerr<<"Element Not found"<<endl;
    }
    return 0;
}
