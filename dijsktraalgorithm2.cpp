#include<bits/stdc++.h>
using namespace std;
int minPath(int dist[],bool visit[])
{

    int m =INT_MAX,index;
    for(int i=0; i<6; i++)
    {
        if(visit[i]==false && dist[i]<=m)
        {
            m=dist[i];
            index=i;
        }
    }
    return index;

}
void Dijk(int graph[6][6],int src)
{

    int dist[6];
    bool visit[6];

    for(int i = 0 ; i<6; i++)
    {
        dist[i] = INT_MAX; //+2147483647
        visit[i] = false;
    }

    dist[src] = 0;

    for(int i = 0 ; i<6 ; i++)
    {
        int m=minPath(dist,visit);//0
        visit[m] = true;

        for(int i = 0 ; i<6 ; i++)
        {
            if(visit[i]!=true && graph[m][i] && dist[m]!=INT_MAX && (dist[m]+graph[m][i])<dist[i])
                dist[i]=dist[m]+graph[m][i];
        }


    }

    cout<<"Vertex\t\tDistance from source"<<endl;
    for(int i = 0; i<6; i++)
    {
        char str=65+i;
        cout<<str<<"\t\t\t"<<dist[i]<<endl;
    }


}

int main()
{
    int graph[6][6]=
    {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };
    cout<<"Given Vertex and cost"<<endl;
    for(int i = 0 ; i < 6; i++)
    {
        char str=65+i;
        cout<<str<<" ";
        for(int j = 0 ; j<6 ; j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    Dijk(graph,0);
}
