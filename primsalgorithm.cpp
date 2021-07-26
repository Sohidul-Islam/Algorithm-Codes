
#include <cstring>
#include <iostream>
using namespace std;
#define INF 9999999
#define V 5
//#define V 6
int G[V][V] =
{
    {0,9, 75, 0,0},
    {9, 0, 95, 19, 42},
    {75,95,0,51,66},
    {0, 19,51,0,31},
    {0,42,66, 31, 0}
};

//{ {0, 4, 6, 0, 0, 0},
//{4, 0, 6, 3, 4, 0},
//{6, 6, 0, 1, 8, 0},
//{0, 3, 1, 0, 2, 3},
//{0, 4, 8, 2, 0, 7},
//{0, 0, 0, 3, 7, 0}
//
//};

int main()
{
    int no_edge;
    int total_cost = 0;
    bool selected[V];

    for(int i = 0 ; i<V ; i++)
    {
        selected[i] = false;
    }
    no_edge = 0;
    selected[0] = true;

    int x;
    int y;


    // print for edge and weight
    cout<<"We have "<<V<<" vertexes "<<endl;
    cout << "Edge"
         << " : "
         << "Weight";
    cout << endl;
    while (no_edge < V - 1)
    {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {

            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {

                    if (!selected[j] && G[i][j])
                    {

                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;

                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        total_cost = total_cost+G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;


    }
    cout<<endl;
    cout<<"Total Cost: "<<total_cost<<endl;

    return 0;
}
