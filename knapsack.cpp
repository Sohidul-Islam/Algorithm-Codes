#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }

}

int knapsack(int cap,int val[],int weight[],int n)
//now n = 3;
{
    if(n==0 || cap == 0) //or operator
    {
        return 0;
    }
    if(weight[n-1]>cap)
    {
      return knapsack(cap,val,weight,n-1);
    // int val[] = {60,110,120,}
    // int weight[] = {10,20,35,}
    //           alu = 10,potol = 20,gajor = 35
    // int cap = 50;
    }
    else
    {   //max()
        return max(val[n-1]+
                   knapsack(cap-weight[n-1],val,weight,n-1),knapsack(cap,val,weight,n-1));
    // int val[] = {60,110,120,}
    // int w[] = {10,20,35,}
    // int w = 50;  val = (120+(50-35)),()
    }
    cout<<endl;
}


int main()
{
    int item;
    cout<<"Enter Item numbers: "<<endl;
    cin>>item;
    int value[item];
    int weight[item];

    // int val[] = {60,110,120,125}
    // int w[] = {10,20,35,60}
    // int w = 50;

    for(int i = 0 ; i<item; i++){
        cout<<"for item "<<i+1<<endl;//cout<< / printf();
        cout<<"Value: ";
        cin>>value[i];// cin>> scanf
        cout<<"Weight: ";
        cin>>weight[i];
    }
    int capacity;
    cout<<"Enter Knapsack Capacity"<<endl;
    cin>>capacity;
    int r = knapsack(capacity,value,weight,item);
    cout<<"Result: "<<r<<endl;

}
