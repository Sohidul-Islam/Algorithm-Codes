#include<stdio.h>
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
		int min = 9999, a = 0, b = 0,i = 0,j=0;
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++)
            {
                int k,l;
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
        printf("Edge: %d (%d, %d) cost: %d \n",edge_count++,a,b,min);
		mincost += min;
	}
	 printf("Minimum csot %d \n",mincost);
}
// driver program to test above function
int main()
{

    scanf("%d %d",&V,&E);//input vertex and edges.
    for(int i=0;i<V;i++)//row i = 0;
    {
        for(int j=0; j<V; j++)//col j = 0 to j<v;
        {
            cost[i][j]= 9999; //here cost is 2d array r = v , col = v; r*c = v*v = ?

        }
    }

    for(int i=0;i<V;i++)//row i = 0;
    {
        for(int j=0; j<V; j++)//col j = 0 to j<v;
        {
            printf("%d ",cost[i][j]);//here cost is 2d array r = v , col = v; r*c = v*v = ?

        }
        printf("\n");
    }




    for(int j = 0;j<E;j++)
    {
        int m,n;// 0--->1
        //here m = starting node(parent node) and n = destinatin node
        // m = 0 , n = 1;

        scanf("%d %d",&m,&n);
        scanf("%d",&cost[m][n]);
        //cost[m][n];
        //cost[0][1];
    }

 for(int i=0;i<V;i++)//row i = 0;
    {
        for(int j=0; j<V; j++)//col j = 0 to j<v;
        {
            printf("%d ",cost[i][j]);//here cost is 2d array r = v , col = v; r*c = v*v = ?

        }
        printf("\n");
    }


    for (int i = 0; i < V; i++)
        parent[i] = i;

	/// Print the solution

	kruskalMST();
	return 0;
}
