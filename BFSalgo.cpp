#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<int> Graph[100];//vector array stl.
int isVisited[100];

void BreadthFirstSearch(int s,int n)//s = starting node and n = total vertex
{
    for(int i = 0 ; i<n ; i++)
    {
        isVisited[i]=0;
    }

    queue<int>Queue;//taking a queue.

    Queue.push(s);

    isVisited[s] = 1;

    while(!Queue.empty())
    {
        int u = Queue.front();
        cout<<u<<" ";
        Queue.pop();
        for(int i = 0; i<Graph[u].size(); i++)
        {
            if(isVisited[Graph[u][i]]==0)
            {
                int v = Graph[u][i];
                isVisited[v] = 1;
                Queue.push(v);
            }
        }
    }
}

int main()
{
    Graph[6].push_back(4);
    Graph[4].push_back(6);
    Graph[4].push_back(3);
    Graph[4].push_back(5);
    Graph[5].push_back(2);
    Graph[5].push_back(1);
    Graph[3].push_back(4);
    Graph[3].push_back(2);
    Graph[2].push_back(3);
    Graph[2].push_back(5);
    Graph[2].push_back(1);
    Graph[1].push_back(2);
    Graph[1].push_back(5);
    BreadthFirstSearch(2,6);
}
