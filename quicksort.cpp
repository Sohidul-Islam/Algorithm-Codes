#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

void swap(int arr[],int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    int i = l-1;
    for(int j = l; j<r; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
int main()
{
    int n;
    cout<<"Enter Array Size"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Array Elements"<<endl;
    for(int i = 0; i<n; i++)
    {
        arr[i] = rand()%30;
    }
    cout<<"Your Existing Array: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   auto start = high_resolution_clock::now();
    quickSort(arr,0,n-1);
   auto stop = high_resolution_clock::now();
    cout<<"Your Existing Array: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
     auto duration = duration_cast<nanoseconds>(stop - start);
    cout<<"It takes: "<<duration.count()<<" nanoseconds"<<endl;
}
