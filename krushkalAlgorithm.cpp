#include <bits/stdc++.h>
using namespace std;
int V,E; //total number of vertex total number of edges
int parent[100];
int cost [1000][10000];


int find(int i)///Find the parent of i
{
	while (parent[i] != i)
        i = parent[i];
    return i;
}
void union1(int i, int j)   /// make the parent of i to the parent of j
{
	int a = find(i);//2
	int b = find(j);//3
	parent[a] = b;
	//parent a = 2 sekhane parent a 3;
}
void kruskalMST()
{
	int mincost = 0; // Cost of min MST.
	int edge_count = 0;

	while (edge_count < V - 1)
    {
		int min = INT_MAX ,a = -1,b=-1;
		for (int i = 0; i < V; i++) {//row
			for (int j = 0; j < V; j++)//col
            {
                int k,l;//temporary variable for storing i and j value.
                k = i;
                l = j;

				if (find(i) != find(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}

			}
		}

		union1(a, b);
        cout<<"Edge "<<edge_count++<<":("<<a<<" "<<b<<") cost:"<<min<<endl;
		mincost += min;//mincost = mincost+min
	}
	cout<<endl<<"Minimum cost= "<<mincost;
}
// driver program to test above function
int main()
{
    cin>>V>>E;//input vertex and edges.
    for(int i=0;i<V;i++)//row i = 0;
    {
        for(int j=0; j<V; j++)//col j = 0 to j<v;
        {
            cost[i][j]= INT_MAX;//2147483647 //here cost is 2d array r = v , col = v; r*c = v*v = ?

        }
    }

//    cout<<"Cost: "<<endl;
//
//     for(int i=0;i<V;i++)
//    {
//        for(int j=0; j<V; j++)
//        {
//            cout<<cost[i][j]<<" ";
//
//        }
//        cout<<endl;
//    }

    for(int j = 0;j<E;j++)
    {
        int m,n;// 0--->1
        //here m = starting node(parent node) and n = destination node
        // m = 0 , n = 1;
        cin>>m>>n;
        cin>>cost[m][n];//5
        //cost[m][n];
        //cost[0][1];

        /* input here
            4 6
            0 1 2
            0 3 4
            0 2 3
            1 3 5
            1 2 6
            2 3 1
        */
    }


// cout<<"Cost: "<<endl;
//
//     for(int i=0;i<V;i++)
//    {
//        for(int j=0; j<V; j++)
//        {
//            cout<<cost[i][j]<<" ";
//
//        }
//        cout<<endl;
//    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

	/// Print the solution

	kruskalMST();
	return 0;
}
