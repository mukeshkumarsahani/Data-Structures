// To merge sort an array

#include<iostream>

using namespace std;

void merge(int array[], int LB, int MB, int UB)
{
    int tempArray[UB - LB +1];
    int i = LB,j = MB +1,k = 0;
    
    while(i < (MB+1) && j < (UB +1))
    {
        if(array[i] < array[j])
        {
            tempArray[k] = array[i];
            i++;
            k++;
        }
        else
        {
            tempArray[k] = array[j];
            j++;
            k++;
        }
    }
    
    if(i > (MB) && j < (UB + 1))
    {
        while(j < (UB + 1))
        {
            tempArray[k] = array[j];
            k++;
            j++;
        }
    }
    
    if(j > UB && i < (MB + 1))
    {
        while (i < (MB + 1))
        {
            tempArray[k] = array[i];
            i++;
            k++;
        }
    }
    
    for(int t = 0; t < k ; t++)
    {
        array[LB + t] = tempArray[t];
    }
}

void mergeSort(int array[], int LB, int UB)
{
    int swapVariable;
    if(LB == UB)
    {
        return;
    }
    else if(UB - LB == 1)
    {
        if(array[LB] > array[UB])
        {
            swapVariable = array[LB];
            array[LB] = array[UB];
            array[UB] = swapVariable;
        }
        return;
    }
    else
    {
        mergeSort(array, LB, (LB + UB)/2);
        mergeSort(array, (LB + UB)/2 + 1, UB);
        merge(array, LB, (LB + UB)/2, UB);
    }
}



int main()
{
     int array[10]={10,30,20,100,80,70,40,60,50,90};
    int index,swapVariable; // Index stores the index of lowest value of that round
    int i,j;
    int arraySize=(sizeof(array)/sizeof(array[0]));
    
    mergeSort(array, 0, arraySize - 1);
    
    cout<<"Sorted Array is: "<<endl;
    for(int t = 0; t < arraySize; t++)
        cout<<array[t]<<"   ";
    return 0;
}
