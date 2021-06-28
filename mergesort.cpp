#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;
int st,en;
void merge(int ar[],int l,int mid, int r)
{
    int num1 = mid-l+1;
    int num2 = r-mid;

    int a[num1];
    int b[num2]; //temp arrays

    for(int i = 0 ; i<num1 ; i++)
    {
        a[i] = ar[l+i];
    }
    for(int i = 0 ; i<num2 ; i++)
    {
        b[i] = ar[mid+1+i];
    }

    int p1 = 0;
    int p2 = 0;
    int p3 = l;

    while(p1<num1 && p2<num2)
    {
        if(a[p1]<b[p2])
        {
            ar[p3]=a[p1];
            p3++; p1++;
        }
        else
        {
            ar[p3] = b[p2];
            p3++;
            p2++;
        }
    }
        while(p1<num1)
        {
            ar[p3] = a[p1];
            p3++;
            p1++;
        }
        while(p2<num2)
        {
            ar[p3] = b[p2];
            p3++;
            p2++;
        }
}
void mergesort(int ar[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(ar,l,mid);
        mergesort(ar,mid+1,r);

        merge(ar,l,mid,r);
    }
}
int main()
{
    int n;
    cout<<"Enter Array Size"<<endl;
    cin>>n;//input n = 100
    int arr[n];//arr[100]
    for(int i = 0 ; i < n; i++ ){
        arr[i] = rand()%20+1;
    }
    cout<<"Inputed Data"<<endl;
     for(int i = 0 ; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto start = high_resolution_clock::now();
    mergesort(arr,0,n-1);
    auto stop = high_resolution_clock::now();
    cout<<"Sorted Data"<<endl;
     for(int i = 0 ; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout<<"Duration in nanoseconds "<<duration.count()<<endl;
}
