#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<int> adj[100];
int visited[100];

void bfs(int s,int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        visited[i]=0;
    }

    queue<int>Q;

    Q.push(s);

    visited[s] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        cout<<u<<" ";
        Q.pop();
        for(int i = 0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v = adj[u][i];
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
}


int main()
{

    adj[6].push_back(4);
    adj[4].push_back(5);
    adj[4].push_back(3);
    adj[5].push_back(1);
    adj[5].push_back(2);
    adj[3].push_back(2);


    bfs(6,6);
}
