#include<iostream>

using namespace std;

int main()
{
    int array[10]={10,30,20,100,80,70,40,60,50,90};
    int index,swapVariable; // Index stores the index of lowest value of that round
    int round,j;
    int arraySize=(sizeof(array)/sizeof(array[0]));

    for(round = 0; round < arraySize; round++)
    {
        // This loop starts from its index and goes till the end of the loop
        index=round;
        for(j=round+1; j < arraySize; j++)
        // After the round index it searches for the index of the smallest element
        {
            if(array[j]<array[index])
                index=j;
        }
        // This swaps the smallest value at index with the round index
        swapVariable = array[round];
        array[round] = array[index];
        array[index] = swapVariable;
    }

    cout<<"Sorted Array is: "<<endl;
    for(int t = 0; t < arraySize; t++)
        cout<<array[t]<<"   ";
    return 0;
}
